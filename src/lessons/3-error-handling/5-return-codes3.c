  #include <stdio.h>
  #include <stdlib.h>

  int divide(int a, int b, int *result) {
    if (b == 0) {
      return -1; // Error: division by zero
    }
    *result = a / b;
    return 0; // Success
  }

  int main() {
    int result;
    if (divide(10, 3, &result) != 0) {
      fprintf(stderr, "Error: Division by zero\n");
      return EXIT_FAILURE;
    }
    printf("Result: %d\n", result);
    return EXIT_SUCCESS;
  }