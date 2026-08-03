#include <stdio.h>
#include <errno.h>
#include <string.h>

#define MAX_BUFFER 1024
#define SQUARE(x) ((x) * (x))

#ifdef _WIN32
    // Code for Windows
#else
    // Code for Unix-like systems
#endif

int main() {
    FILE *f = fopen("non_existed_file.txt", "r");
    if (f == NULL) {
        printf("Error code: %d\n", errno);
        printf("Error desription: %s\n", strerror(errno));
        return 1;
    }

    return 0;
}