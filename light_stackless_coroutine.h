/*
 * Copyright (c) 2018, 2020, Xianguang Zhou <xianguang.zhou@outlook.com>. All
 * rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LIGHT_STACKLESS_COROUTINE_H_
#define LIGHT_STACKLESS_COROUTINE_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LscCoroutine LscCoroutine;
typedef void (*LscFunction)();

struct LscCoroutine {
  void *pc;
  void *bp;
  void *sp;
  LscCoroutine *link;
};

extern LscCoroutine *lsc_swap_context(LscCoroutine *other, LscCoroutine *self);

extern __thread LscCoroutine *lsc_current_coro;

void lsc_open();
void lsc_close();
LscCoroutine *lsc_new(LscFunction func);
void lsc_resume(LscCoroutine *coro);
#define lsc_yield                                                              \
  lsc_current_coro = lsc_swap_context(lsc_current_coro->link, lsc_current_coro)
#define lsc_return lsc_swap_context(lsc_current_coro->link, lsc_current_coro)
void lsc_free(LscCoroutine *coro);

#ifdef __cplusplus
}
#endif

#endif
