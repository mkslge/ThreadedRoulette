//
// Created by Mark on 11/9/25.
//

#include "utility.h"

sockaddr_in Utility::init_thread_addr(int port) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    sockaddr_in dest;
    memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_port = port;

    if (inet_pton(AF_INET, "127.0.0.1", &dest.sin_addr) <= 0) {
        std::cout << "Failed to initialize client on port " <<  port << std::endl;
        return dest;
    }

    char* str = "Placeholder initialization message";

    if (sendto(sockfd, str, strlen(str), 0, (struct sockaddr*)&dest, sizeof(dest)) < 0) {
        std::cout << "Error sending message." << std::endl;
        return dest;
    } else {
        std::cout << "Message sent and initalized.";
    }



    return dest;
}


bool send_message(sockaddr_in dest, char* message) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    return sendto(sockfd, message, strlen(message), 0, (struct sockaddr*)&dest, sizeof(dest));
}