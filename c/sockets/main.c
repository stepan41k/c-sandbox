#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = { .sin_family = AF_INET, .sin_port = htons(8080), .sin_addr.s_addr = INADDR_ANY };

    if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("ERROR: failed to bind");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    listen(server_fd, 5);

    while (1) {
        int client_fd = accept(server_fd, NULL, NULL);
        char buf[1024] = {0};
        read(client_fd, buf, strlen(buf));
        close(client_fd);
    }

    return 0;
}