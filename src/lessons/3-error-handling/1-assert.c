#include <assert.h>
#include <stdio.h>
#define MAX_ALLOWED_SIZE 8
//constexpr int MAX_ALLOWED_SIZE = 8;

void foo(int *ptr, size_t size) {
  assert(ptr != NULL);
  assert(size < MAX_ALLOWED_SIZE);
  // Do something with ptr
  
}

int main() {
  int arr[MAX_ALLOWED_SIZE] = {0};
  for (int i = 0; i < MAX_ALLOWED_SIZE; i++) {
    printf("Calling foo with size: %d\n", i);
    foo(arr, i);
  }
  foo(NULL, 0);
  return 0;
}