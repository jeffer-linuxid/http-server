


void *handle_client(void *arg) {
    int client_fd = *(int *)arg; 
    char buffer[256] = {0};
    read(client_fd, buffer, sizeof(buffer));
    printf("response: %s\n", buffer);

    char *response = "Mensagem recebida!\n";
    write(client_fd, resposta, strlen(resposta));

    close(client_fd);
    return NULL;
}


int main(){

    
}
