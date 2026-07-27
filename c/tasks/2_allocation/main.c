#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;

    int *dynamic_arr = malloc(n * sizeof(int));

    if (dynamic_arr == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        dynamic_arr[i] = i * 10;
    }

    printf("Dynamic value: %d\n", dynamic_arr[2]);

    free(dynamic_arr);

    return 0;
}