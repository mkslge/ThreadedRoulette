//
// Created by Mark on 11/9/25.
//
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#ifndef UTILITY_H
#define UTILITY_H



class Utility {
public:
    static sockaddr_in init_thread_addr(int port);


};



#endif //UTILITY_H
