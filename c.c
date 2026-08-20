#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
int server_fd;
int new_fd;



int main(void)
{
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0) {
        perror("socket()");
        return -1;
    }

    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
        .sin_addr.s_addr = INADDR_ANY
    };

    printf("Success make a socket\n");

    if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind()");
        return -1;
    };

    if (listen(server_fd, 10) < 0) {
        perror("listen()");
        return -1;
    };

    printf("Waiting connection...\n");

    while (1)
{
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);

    int client_fd = accept(
        server_fd,
        (struct sockaddr *)&client_addr,
        &addr_len
    );

    if (client_fd < 0) {
        perror("accept()");
        continue;
    }

    char buffer[4096];

    ssize_t bytes = recv(
        client_fd,
        buffer,
        sizeof(buffer) - 1,
        0
    );

    if (bytes > 0) {
        buffer[bytes] = '\0';

        printf("----- HTTP REQUEST -----\n");
        printf("%s", buffer);
        printf("------------------------\n");
    }
    printf("farmou auria 102 64 e 101 mogado based alfa giga chad autismo prime");
    close(client_fd);
}

close(server_fd);

  
    
}
