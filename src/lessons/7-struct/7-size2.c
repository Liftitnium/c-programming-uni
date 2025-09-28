#include <stdio.h>
#include <string.h>

typedef struct {
  char a;        ///< 1 byte
  int b;         ///< 4 bytes
  char c;        ///< 1 byte
} MyWeirdStruct; // Total: 12 bytes

int main() {
  MyWeirdStruct s;
  s.a = 'A';
  s.b = 42;
  s.c = 'C';
  printf("a: %c, b: %d, c: %c\n", s.a, s.b, s.c); // a: A, b: 42, c: C
  // The address of b is 4 bytes after the address of a
  printf("Address of a: %p\n", (char *)&s.a);
  printf("Address of b: %p\n", (char *)&s.b);
  printf("Address of a + 4 bytes: %p\n", (char *)&s.a + 4);
  printf("Contents of &s+4 (%p) as int: %d\n", (char *)&s.a + 4,
         *(int *)((char *)&s.a + 4));
  printf("Contents of &s+4+4 as char: %c\n", *(char *)((char *)&s.a + 4 + 4));
  return 0;
}