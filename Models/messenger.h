//
// Created by Mark on 11/10/25.
//

#ifndef MESSAGER_H
#define MESSAGER_H
#include <netinet/in.h>
#include <string>


enum MessageRole{CLIENT, SERVER};

class Messenger {
private:
    sockaddr_in server;
    int socket_fd;
    char buffer[2048];
    int port_number;

    sockaddr_in client;
    socklen_t client_length;

public:
    Messenger(MessageRole role);
    Messenger(sockaddr_in dest, int port_number);

    std::string receive();
    std::string receive_no_wait();
    bool send(const char* message);
    bool send_to_client(const char* message);

    int get_port_number() const;

    void set_client(sockaddr_in client);
    sockaddr_in get_client();




};



#endif //MESSAGER_H
