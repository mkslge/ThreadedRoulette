//
// Created by Mark on 11/10/25.
//

#ifndef MESSAGER_H
#define MESSAGER_H
#include <netinet/in.h>


class Messenger {
private:
    sockaddr_in server;
    int socket_fd;
    char buffer[2048];
    int port_number;

    sockaddr_in client;
    socklen_t client_length;

public:
    Messenger();
    Messenger(sockaddr_in dest, int port_number);
    void receive();
    void send(const char* message);
    int get_port_number() const;



};



#endif //MESSAGER_H
