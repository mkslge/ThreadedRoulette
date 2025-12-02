//
// Created by Mark on 12/2/25.
//

#ifndef CLIENTUTILITY_H
#define CLIENTUTILITY_H


#include <string>
#include "../Utility/utility.h"
#include "../Utility/OperationCodes.h"
int parse_bet_result(const std::string& response_string);
bool result_is_win(std::string result);



#endif //CLIENTUTILITY_H
