#include <stdio.h>

#define ARR_SIZE 5

int main() {
    int arr[ARR_SIZE];

    int *pointer = arr;
    int sum = 0;

    for (int i = 1; i <= 5; i++) {
        *pointer = i;
        pointer++;
    }

    pointer = arr;
    for (int i = 1; i <= 5; i++) {
        sum += *pointer;
        pointer++;
    }

    printf("%d\n", sum);

    return 0;
}