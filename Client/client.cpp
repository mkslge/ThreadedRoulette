//
// Created by Mark on 11/9/25.
//
#include <iostream>

#include "../messenger.h"
#include "../Utility/OperationCodes.h"
#include "../Utility/utility.h"
#include <chrono>
#include <thread>



int main() {
    Messenger messenger(CLIENT);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Attempting to join server..." << std::endl;
    messenger.send(OperationCodes::get_join_code());
    while (true) {
        std::string command;
        std::cout << "Type E to exit, or B to bet: " << std::endl;
        std::cin >> command;
        messenger.send(command.c_str());
        if (command == OperationCodes::get_exit_code()) {
            std::cout << "Exiting..." << std::endl;
            return 0;
        } if (is_bet_command(command)) {
            std::string bet_color;
            std::cout << "What color do you want to bet on? (R, B, or G)" << std::endl;
            std:: cin >> bet_color;
            int bet_amount;
            std::cout << "How much do you want to bet?" << std::endl;
            std:: cin >> bet_amount;
            std::string bet_command = create_bet_message(bet_amount, bet_color);
            std:: cout << "Bet command: " << bet_command << std::endl;
            return 0;

        }




        std::cout << messenger.receive() << std::endl;
    }


    std::this_thread::sleep_for(std::chrono::seconds(5));




    return 0;
}
