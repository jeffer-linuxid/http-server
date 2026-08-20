#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int server_fd;
int new_fd;

const char *get_content_type(const char *path)
{
    const char *ext = strrchr(path, '.');
    if (!ext) return "application/octet-stream";

    if (strcmp(ext, ".html") == 0) return "text/html";
    if (strcmp(ext, ".css")  == 0) return "text/css";
    if (strcmp(ext, ".js")   == 0) return "application/javascript";
    if (strcmp(ext, ".png")  == 0) return "image/png";
    if (strcmp(ext, ".jpg")  == 0) return "image/jpeg";
    if (strcmp(ext, ".json") == 0) return "application/json";

    return "application/octet-stream";
}

char *read_file(const char *filepath, long *out_size)
{
    FILE *f = fopen(filepath, "rb");
    if (!f) return NULL;

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    rewind(f);

    if (size < 0) {
        fclose(f);
        return NULL;
    }

    char *buf = malloc(size + 1);

    if (!buf) {
        fclose(f);
        return NULL;
    }

    if (size > 0 && fread(buf, 1, size, f) != (size_t)size) {
        fclose(f);
        free(buf);
        return NULL;
    }

    fclose(f);

    *out_size = size;

    return buf;
}

char *find_route(const char *path)
{
    static char full_path[512];

    if (strstr(path, "..") != NULL) {
        return NULL;
    }

    if (strcmp(path, "/") == 0) {
        snprintf(full_path, sizeof(full_path), "public/index.html");
    } else {
        snprintf(full_path, sizeof(full_path), "public%s", path);
    }

    if (access(full_path, F_OK) != 0) {
        return NULL;
    }

    return full_path;
}

int main(void)
{
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0) {
        perror("socket()");
        return -1;
    }

    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
        .sin_addr.s_addr = INADDR_ANY
    };

    printf("Success make a socket\n");

    if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind()");
        close(server_fd);
        return -1;
    }

    if (listen(server_fd, 10) < 0) {
        perror("listen()");
        close(server_fd);
        return -1;
    }

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

            char method[16];
            char path[256];
            char version[16];

            if (sscanf(buffer, "%15s %255s %15s", method, path, version) != 3) {
                close(client_fd);
                continue;
            }

            const char *file = find_route(path);

            if (!file) {
                const char *response =
                    "HTTP/1.1 404 Not Found\r\n"
                    "Content-Length: 0\r\n"
                    "Connection: close\r\n"
                    "\r\n";

                send(client_fd, response, strlen(response), 0);
                close(client_fd);
                continue;
            }

            long size;
            char *content = read_file(file, &size);

            if (!content) {
                perror(file);
                const char *response =
                    "HTTP/1.1 500 Internal Server Error\r\n"
                    "Content-Length: 0\r\n"
                    "Connection: close\r\n"
                    "\r\n";

                send(client_fd, response, strlen(response), 0);
                close(client_fd);
                continue;
            }

            const char *content_type = get_content_type(file);

            char response[4096];

            int response_size = snprintf(
                response,
                sizeof(response),
                "HTTP/1.1 200 OK\r\n"
                "Content-Type: %s\r\n"
                "Content-Length: %ld\r\n"
                "Connection: close\r\n"
                "\r\n",
                content_type,
                size
            );

            send(client_fd, response, response_size, 0);
            send(client_fd, content, size, 0);

            free(content);
        }
        else {
            close(client_fd);
            continue;
        }

        close(client_fd);
    }

    close(server_fd);

    return 0;
}