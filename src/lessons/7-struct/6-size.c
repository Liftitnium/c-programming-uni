#include <stdio.h>

typedef struct {
  int a;    ///< 4 bytes
  float b;  ///< 4 bytes
} MyStruct; // Total: 8 bytes

typedef struct {
  char a;        ///< 1 byte
  int b;         ///< 4 bytes
  char c;        ///< 1 byte
} MyWeirdStruct; // Total: ?? bytes

int main() {
  printf("Size of MyStruct: %zu bytes\n", sizeof(MyStruct));
  printf("Size of MyWeirdStruct: %zu bytes\n", sizeof(MyWeirdStruct));
  return 0;
}