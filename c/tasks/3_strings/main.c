#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *str1 = "Hello";

    char str2[] = "Hello";
    str2[0] = 'H';

    char *str3 = malloc(10 * sizeof(char));
    strcpy(str3, "Gopher");

    printf("%s: %ld\n", str3, strlen(str3));

    free(str3);

    return 0;
}