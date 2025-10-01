#include <stdio.h>
#include <stdlib.h>

int sum(int *arr, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

int allocFun(void) {
    int *point = NULL;
    int num;
    int count = 0;
    printf("type your numbers:\n");
    while (1) {
        if (scanf("%d", &num) != 1) {          
            fprintf(stderr, "bad input\n");
            free(point);
            return 1;
        }
        if (num < 0) break;

        int *temp = realloc(point, (count + 1) * sizeof(int));
        if (temp == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            free(point);
            return 1;
        }
        point = temp;

        point[count] = num;                    
        // printf("%d\n", point[count]);       
        count++;
    }

    if (count == 0) {                        
        printf("No numbers entered.\n");
        free(point);
        return 0;
    }

    int fin = sum(point, count);
    int average = fin / count;                 
    printf("The sum is %d and the average is %d\n", fin, average);

    free(point);                              
    return 0;
}

int main(void) {
    allocFun();                                                      
    return 0;
}
