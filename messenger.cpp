//
// Created by Mark on 11/10/25.
//

#include "messenger.h"
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>


//Messenger::Messenger(sockaddr_in dest, int port_number) : dest(dest) , port_number(port_number){}


Messenger::Messenger() {
    this->socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (this->socket_fd < 0) {
        perror("Socket creation failed...");
        exit(EXIT_FAILURE);
    }

    memset(&server, 0, sizeof(server));
    this->server.sin_family = AF_INET;
    this->server.sin_addr.s_addr = inet_addr("127.0.0.1");
    this->server.sin_port = htons(8080);

    this->client_length = sizeof(client);

    /*int client_message_size = recvfrom(socket_fd, (char*) buffer, sizeof(buffer),
        MSG_WAITALL, (struct sockaddr*) &client, &client_length);

    buffer[client_message_size] = '\0';
    std:: cout << "Received " << buffer << std::endl;*/
}


std::string Messenger::receive() {
    if (bind(socket_fd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }


    int client_message_size = recvfrom(socket_fd, (char*) buffer, sizeof(buffer),
        MSG_WAITALL, (struct sockaddr*) &client, &client_length);

    buffer[client_message_size] = '\0';

    return this->buffer;
}

void Messenger::send(const char* message) {
    ssize_t bytes_sent = sendto(socket_fd, message, strlen(message)
        ,0 , (const struct sockaddr*) &server, sizeof(server));


    if (bytes_sent < 0) {
        perror("Sending message failed");
        close(socket_fd);
        exit(EXIT_FAILURE);
    }

    std::cout << "Sent " << bytes_sent << " bytes: " << message << std::endl;
}


std::string Messenger::receive_no_wait() {
    std::string message;
    struct timeval tv{0,0};

    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(this->socket_fd, &fds);

    int ret = select(this->socket_fd + 1, &fds,NULL, NULL, &tv);

    if (ret > 0) {
        recv(this->socket_fd, buffer, sizeof(buffer), 0);
    } else {
        std::cout << "No message ):" << std::endl;
    }



    return this->buffer;

}


int Messenger::get_port_number() const {
    return port_number;
}
