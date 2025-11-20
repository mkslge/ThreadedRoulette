//
// Created by Mark on 11/20/25.
//

#ifndef RECEIVER_H
#define RECEIVER_H

#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

class Receiver {

    sockaddr_in server_addr;
    int socket_fd;
    char buffer[2048];


    Receiver();
};



#endif //RECEIVER_H
