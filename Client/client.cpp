//
// Created by Mark on 11/9/25.
//
#include <iostream>

#include "../messenger.h"
#include "../Utility/OperationCodes.h"
#include "../Utility/utility.h"
#include "../Utility/threadutil.h"
#include "../Models/bet.h"
#include "../Models/clientinfo.h"
#include <chrono>
#include <thread>
#include <string>



int main() {
    Messenger messenger(CLIENT);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Attempting to join server..." << std::endl;
    messenger.send("j");

    clientinfo client = clientinfo();

    int amount = 100;
    while (true) {
        std::string command;
        std::cout << "Type E to exit, or B to bet: " << std::endl;
        std::cin >> command;

        if (is_exit_message(command)) {
            std::cout << "Exiting..." << std::endl;
            messenger.send(command.c_str());
            return 0;
        } if (bet::is_bet_command(command)) {
            bet curr_bet = bet(client);

            curr_bet.prompt_bet_color();
            curr_bet.prompt_bet_amount();
            std::string bet_code = curr_bet.create_bet_code();
            messenger.send(bet_code.c_str());

            /*std::string bet_color;
            std::cout << "What color do you want to bet on? (R, B, or G)" << std::endl;
            std:: cin >> bet_color;
            int bet_amount;
            std::cout << "How much do you want to bet?" << std::endl;
            std:: cin >> bet_amount;
            std::string bet_command = bet::create_bet_message(bet_amount, bet_color);
            std:: cout << "Bet command: " << bet_command << std::endl;*/
            return 0;

        }




        std::cout << messenger.receive() << std::endl;
    }


    std::this_thread::sleep_for(std::chrono::seconds(5));




    return 0;
}
