#include <stdio.h>

int main() {
    int a = 1; // Reserve and assign one int in the stack 
    int numbers[5]; // Reserve 5 ints
    for (int i = 0; i < 5; i++) {
        numbers[i] = i * 10;
    }
    for (int i = 0; i < 5; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }
    
    int numbers2[5] = {0}; // Reserve and zero-initialize 5 ints.
    int numbers3[] = {1,2,3}; // Reserve and initialize 3 ints. 


    return 0;
}