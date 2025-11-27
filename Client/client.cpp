//
// Created by Mark on 11/9/25.
//
#include <iostream>

#include "../messenger.h"
#include "../Utility/OperationCodes.h"
#include <chrono>
#include <thread>



int main() {
    Messenger messenger(CLIENT);
    std::cout << "Sending message..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    messenger.send(OperationCodes::get_join_code());
    std::this_thread::sleep_for(std::chrono::seconds(5));
    messenger.send(OperationCodes::get_exit_code());
    std::cout << messenger.receive() << std::endl;



    return 0;
}
