/*
 * Copyright (c) 2018, Xianguang Zhou <xianguang.zhou@outlook.com>. All rights reserved.
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct LscCoroutine LscCoroutine;
struct LscCoroutine {
	void *pc;
	void *bp;
	void *sp;
	LscCoroutine *link;
};

extern LscCoroutine *lsc_start_context(LscCoroutine *that,
		LscCoroutine *this);
extern LscCoroutine *lsc_swap_context(LscCoroutine *that,
		LscCoroutine *this);

#if defined(__x86_64__)
#define SPACE_SIZE 73
#elif defined(__i386__)
#define SPACE_SIZE 193
#endif

void co2_func(LscCoroutine *co2) {
	char space[SPACE_SIZE];
	int lv = 5;
	printf("co2 begin, lv = %d\n", lv);
	co2 = lsc_swap_context(co2->link, co2);
	lv += 5;
	printf("co2 end, lv = %d\n", lv);
	co2 = lsc_swap_context(co2->link, co2);
}

void co3_func(LscCoroutine *co3) {
	char space[SPACE_SIZE];
	int lv;
	printf("co3 begin, lv = %d\n", lv);
	co3 = lsc_swap_context(co3->link, co3);
	printf("co3 end, lv = %d\n", lv);
	co3 = lsc_swap_context(co3->link, co3);
}

int main() {
	LscCoroutine *co1 = calloc(1, sizeof(LscCoroutine));
	LscCoroutine *co2 = calloc(1, sizeof(LscCoroutine));
	co2->pc = co2_func;
	co2->link = co1;
	LscCoroutine *co3 = calloc(1, sizeof(LscCoroutine));
	co3->pc = co3_func;
	co3->link = co1;
	puts("co1 start co2");
	co1 = lsc_start_context(co2, co1);
	puts("co1 start co3");
	co1 = lsc_start_context(co3, co1);
	puts("co1 resume co2");
	co1 = lsc_swap_context(co2, co1);
	puts("co1 resume co3");
	co1 = lsc_swap_context(co3, co1);
	puts("co1 end");
	return 0;
}

