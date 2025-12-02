//
// Created by Mark on 11/27/25.
//

#include "threadutil.h"
#include <thread>

void init_thread(Messenger server) {
    std::cout << "Starting up thread..." << std::endl;
    clientinfo client = clientinfo();

    while (true) {
        std::string received_message = server.receive_no_wait();
        if (is_exit_message(received_message)) {
            server.send_to_client("Ended");
            std::cout << "Thread life ended ): goodbye world..." << std::endl;
            return;
        } else if(bet::is_bet_command(received_message)){
            std::cout << "Received message: " << received_message << std::endl;
            bet curr_bet = bet::encode_bet_string(received_message);
            curr_bet.set_clientinfo(client);

            if (curr_bet.is_winning_bet(global_winning_outcome)) {
                std::cout << "Good job buddy... xd" << std::endl;
            } else {
                std::cout << "epic fail... );" << std::endl;
            }




        } else {
            std::cout << "Waiting..." << std::endl;
            std:std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}

