//
// Created by Mark on 11/27/25.
//

#include "threadutil.h"

void init_thread(Messenger server) {

    while (true) {
        std::string received_message = server.receive_no_wait();
        if (received_message == "E") {
            server.send_to_client("Ended");
            std::cout << "Thread life ended ): goodbye world..." << std::endl;
            return;
        }
    }
}