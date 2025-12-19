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

#include "../Models/messenger.h"
#include "../Models/outcome.h"
#include "../Utility/utility.h"
#include "serverutility.h"
#include "../Models/wheel.h"
#include "../Utility/OperationCodes.h"

int main() {
    init_random_seed();
    int server_balance = SERVER_STARTING_BALANCE;
    int threads_made = 0;

    std::cout << "Starting server..." << std::endl;
    Messenger messenger(SERVER);

    //main game loop
    while (true) {
        while (is_join_message(messenger.receive_no_wait())) {

            //add new thread in here
            std::cout << "New thread being made..." << std::endl;
            threads.emplace_back(&init_thread, std::ref(messenger), threads_made);
            threads_made++;
        }
        //here we want server
        //if new player, joins, we handle that in a new thread
        std:: cout << "Spinning wheel..." << std::endl;

        //server-side animation
        Wheel wheel;
        wheel.spin();

        //generating outcome
        global_winning_outcome = Outcome::generate_random_outcome();
        outcome_generated = true;
        std::cout << "Spun wheel, " << global_winning_outcome.to_string() << std::endl;
        outcome_generated = false;

        std::cout << "Current house balance: " << server_balance << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    return 0;
}




