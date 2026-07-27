#include <stdio.h>
#include <stdlib.h>

int* create_array(int size) {
    int* new_array = malloc(size * sizeof(int));

    if (new_array == NULL) {
        return NULL;
    }
    
    for (int i = 0; i < size; i++) {
        new_array[i] = i * i;
    }

    return new_array;
}

int main() {
    int array_size = 7;

    int* result = create_array(array_size);
   
   for (int i = 0; i < array_size; i++) {
       printf("Index %d = %d\n", i, result[i]);
   } 

   free(result);

   return 0;
}