#include <stdio.h>
#include <stdlib.h>

void do_something() {
    size_t eight_gb = 1024 * 1024 * 1024;
    size_t *data = (size_t *)malloc(eight_gb * sizeof(size_t));
    if (data == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    // Fill the allocated memory to ensure it's actually used
    for (size_t i = 0; i < eight_gb; i ++) {
        data[i] = i;
    }
    printf("Allocated %lu bytes at %p\n", eight_gb, data);
    // Intentionally forget to free the allocated memory
    // free(data); // This line is omitted, causing a memory leak
}

int main() {
    do_something();
    printf("Allocated 8GB, waiting for user input to exit...\n");
    scanf("%*c"); // Wait for user input to keep the program running
    printf("Memory leak demonstration complete.\n");
    return 0;
}