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
#include "../Models/outcome.h"
#include "../Utility/utility.h"
#include "serverutility.h"
#include "../Utility/OperationCodes.h"







int main() {
    srand(time(0));
    std::cout << "Starting server..." << std::endl;
    Messenger messenger(SERVER);

    //main game loop
    while (true) {
        if (is_join_message(messenger.receive_no_wait())) {
            //add new thread in here
            std::cout << "New thread being made..." << std::endl;
            threads.emplace_back(&init_thread, messenger);
        }
        //here we want server
        //if new player, joins, we handle that in a new thread
        std:: cout << "Spinning wheel..." << std::endl;
        global_winning_outcome = Outcome::generate_random_outcome();
        outcome_generated = true;
        std::cout << "Spun wheel, " << global_winning_outcome.to_string() << std::endl;
        outcome_generated = false;
        std::this_thread::sleep_for(std::chrono::seconds(5));

    }

    return 0;
}




void thread_init(sockaddr_in dest, int port) {
    memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_port = port;


}



