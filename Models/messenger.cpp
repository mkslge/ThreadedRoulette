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


Messenger::Messenger(MessageRole role) {
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
    if (role == SERVER) {
        if (bind(socket_fd, (struct sockaddr*)&server, sizeof(server)) < 0) {
            perror("Bind failed");
            exit(EXIT_FAILURE);
        }
    }
}


/* Receives message, waiting for message to be received if none has been sent to Messenger.
 */
std::string Messenger::receive() {

    int client_message_size = recvfrom(socket_fd, buffer, sizeof(buffer),
        MSG_WAITALL, (struct sockaddr*) &client, &client_length);

    buffer[client_message_size] = '\0';

    return std::string(this->buffer);
}
/* Receives a message only if a message has already been sent by a client.
 * returns "" if no message has been sent by a client
 */
std::string Messenger::receive_no_wait() {
    struct timeval tv{0,0};

    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(this->socket_fd, &fds);

    int ret = select(this->socket_fd + 1, &fds,NULL, NULL, &tv);


    if (ret > 0) {

        ssize_t message_length = recvfrom(socket_fd, buffer, sizeof(buffer) - 1,
        0, (struct sockaddr*)&client, &client_length);

        if (message_length < 0) {
            perror("Recv failed...");
            return "";
        }

        buffer[message_length] = '\0';
    } else if (ret == 0) {
        return "No message ):";
    } else {
        perror("Select failed...");
        return "";
    }

    return std::string(this->buffer);

}


bool Messenger::send(const char* message) {
    ssize_t bytes_sent = sendto(socket_fd, message, strlen(message)
        ,0 , (const struct sockaddr*) &server, sizeof(server));


    if (bytes_sent < 0) {
        perror("Sending message failed");
        close(socket_fd);
        return false;
    }

    return true;
}

bool Messenger::send_to_client(const char* message) {
    ssize_t bytes_sent = sendto(socket_fd, message, strlen(message)
        ,0 , (const struct sockaddr*) &client, sizeof(client));

    return true;
}





int Messenger::get_port_number() const {
    return port_number;
}


void Messenger::set_client(sockaddr_in client) {
    this->client = client;
}

sockaddr_in Messenger::get_client() {
    return client;
}

