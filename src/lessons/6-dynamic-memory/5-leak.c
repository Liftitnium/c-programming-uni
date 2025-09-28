#include <stdio.h>
#include <stdlib.h>
void leak_memory() {
  int *leak = (int *)malloc(100 * sizeof(int));
  // do something
}
int main() {
  leak_memory();
  // No way to free the memory allocated in leak_memory
  return 0;
}