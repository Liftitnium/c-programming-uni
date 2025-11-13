#include <stdio.h>
#include <stdlib.h>


//excersise 1
void print_bits32(void* ptr, int size) {
    int x = *(int*)ptr;
    for (int i = 31; i >= 0; i--) {
        int bit = (x >> i) & 1;
        printf("%d", bit);
    }
};

//excersise 1 with the union part

typedef union {
    int i;
    float f;
    double d;
    char c;
    unsigned char bytes[8];
} DataUnion;

void byte_to_bits(unsigned char byte, char *bits) {
    for (int i = 7; i >= 0; i--) {
        bits[7 - i] = ((byte >> i) & 1) ? '1' : '0';
    }
    bits[8] = '\0'; // Null-terminator
}
void print_bits_union(DataUnion data, size_t size) {
    char bits[9];
    // Print from most significant byte to least
    for (int i = (int)size - 1; i >= 0; i--) {    //loop over each byte 
        byte_to_bits(data.bytes[i], bits);
        printf("%s ", bits);
    }
    printf("\n");
}


int main() {

//excersise 1 test

    char r = 'a';
    void* p = &r;
    print_bits32(p, sizeof(r));
//excersise 1 with union test.These tests were done with autopilot.
    DataUnion data;
    data.i = 305419896; // Example integer
    printf("Integer bits: ");
    print_bits_union(data, sizeof(data.i));

    data.f = 3.14f; // Example float
    printf("Float bits: ");
    print_bits_union(data, sizeof(data.f));

    data.d = 3.14; // Example double
    printf("Double bits: ");
    print_bits_union(data, sizeof(data.d));

    data.c = 'A'; // Example char
    printf("Char bits: ");
    print_bits_union(data, sizeof(data.c));

    return 0;
}
