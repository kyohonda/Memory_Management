#include <stdio.h>
#include <stdlib.h>

// global variables
int global1 = 10;
int global2 = 20;
int global3 = 30;

int recursive_function(int n) {
    if (n <= 0) {
        return 0;
    }
    int local_variable_function = n;
    printf("Stack address of local_variable_function: %p\n", &local_variable_function);
    return n+recursive_function(n - 1);
}

int main() {
    // 3 local variables in main
    int local_variable_main1 = 100;
    int local_variable_main2 = 200;
    // 3 heap variables in main
    int* heap_variable1 = (int*)malloc(sizeof(int));
    int* heap_variable2 = (int*)malloc(sizeof(int));
    int* heap_variable3 = (int*)malloc(sizeof(int));

    printf("Stack address of local_variable_main1: %p\n", &local_variable_main1);
    printf("Stack address of local_variable_main2: %p\n", &local_variable_main2);

    printf("Heap address of heap_variable1: %p\n", heap_variable1);
    printf("Heap address of heap_variable2: %p\n", heap_variable2);
    printf("Heap address of heap_variable3: %p\n", heap_variable3);

    int result = recursive_function(5);
    printf("Result: %d\n", result);

    free(heap_variable1);
    free(heap_variable2);
    free(heap_variable3);

    return 0;
}
