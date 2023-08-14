#include <stdio.h>
#include <stdlib.h>

// 3 global variables
int global1 ;
int global2 = 2;
int global3 = 3;

int recursive_function(int n) {
    if (n <= 0) {
        return 0;
    }
    int local_variable_recursive = n;
    printf("Stack address of local_variable_recursive: %p\n", &local_variable_recursive);
    return n+recursive_function(n - 1);
}

int main() {
    // 3 local variables in main
    int local_variable_main1 = 11;
    int local_variable_main2 = 22;
    int local_variable_main3 = 33;
    // 3 heap variables in main
    int* heap_variable1 = (int*)malloc(sizeof(int));
    int* heap_variable2 = (int*)malloc(sizeof(int));
    int* heap_variable3 = (int*)malloc(sizeof(int));

    printf("Data address of global1: %p\n", &global1);
    printf("Data address of global2: %p\n", &global2);
    printf("Data address of global3: %p\n", &global3);

    printf("Stack address of local_variable_main1: %p\n", &local_variable_main1);
    printf("Stack address of local_variable_main2: %p\n", &local_variable_main2);
    printf("Stack address of local_variable_main3: %p\n", &local_variable_main3);

    printf("Heap address of heap_variable1: %p\n", heap_variable1);
    printf("Heap address of heap_variable2: %p\n", heap_variable2);
    printf("Heap address of heap_variable3: %p\n", heap_variable3);


    int result = recursive_function(5);
    // stack overflow
    //int result = recursive_function(200000);

    free(heap_variable1);
    free(heap_variable2);
    free(heap_variable3);

    return 0;
}
