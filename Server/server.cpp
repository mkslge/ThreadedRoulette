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
#include <string>

#include <chrono>
#include <thread>

#include "../messenger.h"
#include "../outcome.h"


Outcome global_winning_outcome;
std::vector<std::thread> global_comms;
int main() {
    srand(time(0));
    std::cout << "Starting server..." << std::endl;
    Messenger messenger(SERVER);
    //messenger.receive();
    //std::cout << "Received message: " << messenger.receive_no_wait() << std::endl;

    //return 0;
    //main game loop
    while (true) {
        if (messenger.receive_no_wait() == "JOINING") {
            //add new thread in here
            std::cout << "New thread being made..." << std::endl;
        }
        //here we want server
        //if new player, joins, we handle that in a new thread
        std:: cout << "Spinning wheel..." << std::endl;
        global_winning_outcome = Outcome::generate_random_outcome();
        std::cout << "Spun wheel, " << global_winning_outcome.to_string() << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));

    }

    return 0;
}




void thread_init(sockaddr_in dest, int port) {
    memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_port = port;


}



