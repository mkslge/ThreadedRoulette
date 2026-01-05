//
// Created by Mark on 11/9/25.
//
#include <iostream>

#include "../Models/messenger.h"
#include "../Utility/constants.h"
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
    std::this_thread::sleep_for(std::chrono::seconds(constants::STARTUP_TIME));
    std::cout << "Attempting to join server..." << std::endl;
    messenger.send("j");

    clientinfo client = clientinfo();


    while (true) {
        std::string command;
        std::cout << "Type E to exit, or B to bet, your balance is now " << client.get_balance() << ": " << std::endl;
        std::cin >> command;

        if (is_exit_message(command)) {
            std::cout << "Exiting..." << std::endl;
            messenger.send(command.c_str());
            return 0;
        } else if (bet::is_bet_command(command)) {
            //initialize new bet connection
            bet curr_bet = bet(client);

            //prompt user for the color and amount to bet
            curr_bet.prompt_bet_color();
            curr_bet.prompt_bet_amount(client);

            //start animation thread
            std::cout << BET_RESULT_RECEIVED;
            std::thread bet_animation_thread(spin_wheel_animation);

            //send message to server
            std::string bet_code = curr_bet.create_bet_code();
            messenger.send(bet_code.c_str());



            //wait for response from server
            std::string server_response = messenger.receive();

            //mark bet as received and join thread
            BET_RESULT_RECEIVED = true;
            bet_animation_thread.join();

            int bet_result = parse_bet_result(server_response);


            Wheel wheel(result_is_win(server_response));
            wheel.spin();

            client.add_balance(bet_result);
            std::cout << "Your current balance is now " << client.get_balance() << std::endl;
        }




        BET_RESULT_RECEIVED = false;
    }
    return 0;
}
