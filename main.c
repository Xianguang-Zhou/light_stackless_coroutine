#include <stdlib.h>
#include <stdio.h>

typedef struct LscCoroutine LscCoroutine;
struct LscCoroutine{
	void *pc;
	void *bp;
	void *sp;
	LscCoroutine *link;
};

extern LscCoroutine *lsc_start_context(LscCoroutine *that,
		LscCoroutine *this);
extern LscCoroutine *lsc_swap_context(LscCoroutine *that,
		LscCoroutine *this);

void co2_func(LscCoroutine *co2){
	puts("co2 begin");
	co2=lsc_swap_context(co2->link, co2);
	puts("co2 end");
	co2=lsc_swap_context(co2->link, co2);
}

int main(){
	LscCoroutine *co1=calloc(1,sizeof(LscCoroutine));
	LscCoroutine *co2=calloc(1,sizeof(LscCoroutine));
	co2->pc=co2_func;
	co2->link=co1;
	puts("co1 start co2");
	co1=lsc_start_context(co2,co1);
	puts("co1 resume co2");
	co1=lsc_swap_context(co2,co1);
	puts("co1 end");
	return 0;
}

