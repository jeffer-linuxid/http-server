#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>

int server_fd;
int new_fd;

void *handle_client(void *arg) {
    int client_fd = *(int *)arg; 
    char buffer[256] = {0};
    read(client_fd, buffer, sizeof(buffer));
    printf("Receive: %s\n", buffer);

    char *response = "Mensenge receive!\n";
    write(client_fd, response, strlen(response));

    close(client_fd);
    return 0;
    
}


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
    }

    if (listen(server_fd, 10) < 0) {
        perror("listen()");
        return -1;
    }

    printf("Waiting connection...\n");

    while (1)
    {
        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);

        new_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len);

        if (new_fd < 0) {
           
            perror("accept()");
            continue;
        }


        printf("Client connected!\n");

        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, &new_fd);
        pthread_join(tid, NULL); 
    }

    close(server_fd);
    return 0;
}
