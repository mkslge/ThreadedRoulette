//
// Created by Mark on 11/9/25.
//

#include "utility.h"

/* DIFFERENT COMMANDS: CLIENT -> SERVER
 * JOIN: J
 * EXIT: E
 * BET : <COLOR><VALUE>_<AMOUNT>
 *
 */
void init_thread(Messenger server) {

    while (true) {
        std::string received_message = server.receive_no_wait();
        if (received_message == "E") {
            std::cout << "Thread life ended ): goodbye world..." << std::endl;
            return;
        }
    }
}


