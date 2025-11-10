//
// Created by Mark on 11/9/25.
//
#include <iostream>
#include <vector>
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "../outcome.h"


Outcome global_winning_outcome;
std::vector<std::thread> global_comms;
int main() {
    std::cout << "Starting server..." << std::endl;

    //main game loop
    while (true) {
        //here we want server
        //if new player, joins, we handle that in a new thread
        std:: cout << "Spinning wheel..." << std::endl;
        global_winning_outcome = Outcome::generate_random_outcome();
        std::cout << "Spun wheel" << std::endl;

    }

    return 0;
}




void thread_init(sockaddr_in dest, int port) {
    memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_port = port;


}



