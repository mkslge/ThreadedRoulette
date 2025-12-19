//
// Created by Mark on 11/9/25.
//
#include <iostream>

#include "../messenger.h"
#include "../Utility/OperationCodes.h"
#include "../Utility/utility.h"
#include "clientutility.h"
#include "../Models/bet.h"
#include "../Models/clientinfo.h"
#include "../Models/wheel.h"
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
        } else if (bet::is_bet_command(command)) {
            bet curr_bet = bet(client);

            curr_bet.prompt_bet_color();
            curr_bet.prompt_bet_amount();
            std::string bet_code = curr_bet.create_bet_code();
            messenger.send(bet_code.c_str());


            std::cout << messenger.receive() << std::endl;
            std::string server_response = messenger.receive();
            int bet_result = parse_bet_result(server_response);


            Wheel wheel(result_is_win(server_response));
            wheel.spin();



            amount += bet_result;

            std::cout << "Bet result: " << bet_result << std::endl;


        }





    }







    return 0;
}
