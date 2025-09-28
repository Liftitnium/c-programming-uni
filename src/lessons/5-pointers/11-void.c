#include <stdio.h>

int main() {
  int x = 5;
  void *ptr = &x;            // Cast int* to void*
  double *int_ptr = (double*)ptr; // Cast void* back to int*
  printf("Value of x: %g\n", *int_ptr);
  return 0;
}
