#include <stdio.h>

#define BUFFER_SIZE 10

int main() {
    char buffer[BUFFER_SIZE];
    
    printf("Введите текст (макс %d символов): ", BUFFER_SIZE - 1);
    
    if (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        printf("Содержимое буфера: %s\n", buffer);
    }
    
    return 0;
}