#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    int *arr = (int *)calloc(n, sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Array elements after calloc:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}