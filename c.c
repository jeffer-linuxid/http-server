


#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 50
int main(void){


    int tcp_socket = socket(
        AF_INET,
        SOCK_STREAM,0
    );
    if(tcp_socket == -1){
        perror("tcp_socket()");
        return 1;
    }
    struct c
    {
        /* data */
    };
    
    printf("Success make a socket")



}