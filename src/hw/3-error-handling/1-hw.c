# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
#include <limits.h>

static_assert(sizeof(int) == 4, "int must be 4 bytes");

void print_array(int *arr, int size) {
for (int i = 0; i < size; i++) {
printf("%d ", arr[i]);
}
printf("\n");
}
void vectorized_divide(int *a, int *b, int *result, int size) {
  for (int i = 0; i < size; i++) {
    if (b[i] == 0) {
      printf(stderr, "No division by zero");
      
      continue;
    }
    if (a[i] == INT_MIN && b[i] == -1) {
      fprintf(stderr, "overflow");
      continue;
    }
  result[i] = a[i] / b[i];
  }
}


int main() {
int numbers[5] = {1, 2, 3, 4, 20};
int divisors[5] = {0, 1, 2, 3, 4};
int results[5] = {0};
vectorized_divide(numbers, divisors, results, 5);
print_array(results, sizeof(results) / sizeof(results[0]));
return EXIT_SUCCESS;
}

