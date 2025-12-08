//
// Created by Mark on 11/27/25.
//

#ifndef THREADUTIL_H
#define THREADUTIL_H

#include "../messenger.h"
#include "../Models/bet.h"
#include <iostream>
#include <string>
#include "../Utility/utility.h"
#include <chrono>
#include "../Utility/OperationCodes.h"
#include <thread>


inline Outcome global_winning_outcome;
inline std::vector<std::thread> threads;
inline bool outcome_generated = false;
void init_thread(Messenger server, int thread_num);
Outcome get_next_outcome();






#endif //THREADUTIL_H
