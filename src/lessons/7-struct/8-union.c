#include <stdio.h>

typedef union {
  int i;   ///< Integer member
  float f; ///< Float member
} Data;

int main() {
  Data data; // Declare a variable of type Data (union)
  printf("Size of union: %zu bytes\n", sizeof(data));

  data.i = 10; // Store an integer
  printf("data.i: %d\n", data.i);

  data.f = 220.5; // Store a float (overwrites the integer)
  printf("data.f: %.2f\n", data.f);
  // Accessing the integer now gives the
  // representation of the bits of 220.5 as an int
  printf("data.i (after storing float): %d\n", data.i);
  return 0;
}