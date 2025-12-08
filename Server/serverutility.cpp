//
// Created by Mark on 11/27/25.
//

#include "serverutility.h"
#include <thread>

void init_thread(Messenger server, int thread_num) {
    std::cout << "Starting up thread..." << std::endl;
    clientinfo client = clientinfo();
    const char* response;
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

            bool client_won = curr_bet.is_winning_bet(get_next_outcome());

            if (client_won) {
                std::cout << "Bet won..." << std::endl;
                std::string response_string = std::string(1, OperationCodes::WIN_CODE) +
                    " " + std::to_string(curr_bet.get_amount());
                response = response_string.c_str();
                server.send_to_client(response);
            } else {

                std::cout << "Bet lost ):" << std::endl;
                std::string response_string = std::string(1, OperationCodes::LOSS_CODE) +
                    " " + std::to_string(curr_bet.get_amount());
                response = response_string.c_str();
                server.send_to_client(response);
            }




        } else {
            std::cout << "Waiting in thread " << thread_num << "..." << std::endl;
            std:std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}

Outcome get_next_outcome() {
    while (!outcome_generated) {

    }
    return Outcome(global_winning_outcome);
}