

#include <arpa/inet.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

int main(void){

    char buffer[256] = {};
    int socket_my = socket(
        AF_INET,
        SOCK_STREAM,0
    );
    if(socket_my < 0){
        perror("tcp_socket()");
        return -1
    }

     struct sockaddr_in addr =
    {
       AF_INET,
       0x901f,
       0
    };
    
    printf("Success make a socket");
    int client_connection = accept(socket_my,0,0);
    bind(socket_my,&addr,sizeof(addr));

    listen(socket_my,10);
    recv(client_connection,buffer,256,0);

}