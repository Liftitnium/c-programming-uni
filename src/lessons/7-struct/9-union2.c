#include <stdio.h>

typedef union {
  double val;
  unsigned char bytes[sizeof(double)];
} TypeInspect;

int main() {
  TypeInspect twofold = {
    .val = 2.779887e-317
  };

  printf("Value: %g\n", twofold.val);
  printf("Bytes: ");
  for (size_t i = 0; i < sizeof(double); i++) {
    printf("%02x ", twofold.bytes[i]);
  }
  printf("\n");

  return 0;
}
