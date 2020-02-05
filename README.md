# light_stackless_coroutine

## Example

```c
#include <light_stackless_coroutine.h>
#include <stdio.h>

void co_func() {
  puts("The coroutine yields.");
  lsc_yield;

  puts("The coroutine ends.");
  lsc_return;
}

int main() {
  lsc_open();

  LscCoroutine *co = lsc_new(co_func);

  puts("Start the coroutine.");
  lsc_resume(co);

  puts("Resume the coroutine.");
  lsc_resume(co);

  puts("Free the coroutine.");
  lsc_free(co);

  lsc_close();
  return 0;
}
```
