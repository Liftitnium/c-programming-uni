#include <assert.h>
#include <stdio.h>
  // Try changing the 4 to a 8
static_assert(sizeof(int) == 4 , "int must be 4 bytes");

void print_bits(int value) {
    for (int i = 31; i >= 0; i--) {
        putchar((value & (1 << i)) ? '1' : '0');
        if (i % 8 == 0) putchar(' ');
    }
    putchar('\n');
}

int main() {
    int num = 42;
    print_bits(num);
    return 0;
}