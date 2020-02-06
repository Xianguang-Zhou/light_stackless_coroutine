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
#include "light_stackless_coroutine.h"
#include <stdlib.h>

extern LscCoroutine *lsc_start_context(LscCoroutine *other, LscCoroutine *self);

__thread LscCoroutine *lsc_current_coro = NULL;

void lsc_open() {
	if (NULL == lsc_current_coro) {
		lsc_current_coro = calloc(1, sizeof(LscCoroutine));
	}
}

void lsc_close() {
	if (NULL != lsc_current_coro) {
		free(lsc_current_coro);
		lsc_current_coro = NULL;
	}
}

LscCoroutine *lsc_new(LscFunction func) {
	LscCoroutine *coro = calloc(1, sizeof(LscCoroutine));
	coro->pc = func;
	return coro;
}

void lsc_resume(LscCoroutine *coro) {
	if (NULL == coro->link) {
		coro->link = lsc_current_coro;
		LscCoroutine *self = lsc_current_coro;
		lsc_current_coro = coro;
		lsc_current_coro = lsc_start_context(coro, self);
	} else {
		lsc_current_coro = lsc_swap_context(coro, lsc_current_coro);
	}
}

void lsc_free(LscCoroutine *coro) { free(coro); }
