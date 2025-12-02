//
// Created by Mark on 11/27/25.
//

#ifndef THREADUTIL_H
#define THREADUTIL_H

#include "../messenger.h"
#include "../Models/bet.h"
#include <iostream>
#include <string>
#include "utility.h"
#include <chrono>
#include "OperationCodes.h"
#include <thread>


inline Outcome global_winning_outcome;
inline std::vector<std::thread> threads;

void init_thread(Messenger server);






#endif //THREADUTIL_H
