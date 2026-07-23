#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZE 1024

int main() {
    int src_fd, dst_fd;
    ssize_t n_read;
    char buffer[BUF_SIZE];

    src_fd = open("source.txt", O_RDONLY);
    if (src_fd == -1) {
        perror("Error to open source file");
        exit(1);
    }

    dst_fd = open("destintaion.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst_fd == -1) {
        perror("Error to open destination file");
        close(src_fd);
        exit(1);
    }

    while((n_read = read(src_fd, buffer, BUF_SIZE)) > 0) {
        if (write(dst_fd, buffer, n_read) != n_read) {
            perror("Writing error");
            break;
        }
    }

    close(src_fd);
    close(dst_fd);

    printf("File copied\n");
    return(0);
}