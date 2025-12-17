//
// Created by Mark on 11/26/25.
//

#ifndef OPERATIONCODES_H
#define OPERATIONCODES_H



class OperationCodes {
public:
    static char EXIT_CODE;
    static char JOIN_CODE;
    static char BET_CODE;
    static char WIN_CODE;
    static char LOSS_CODE;
    static int ROULETTE_SIZE;
private:
    OperationCodes();
public:
    static char get_exit_code();
    static char get_join_code();
    static char get_bet_code();
    static char get_win_code();
    static char get_loss_code();
    static int get_roulette_size();
};



#endif //OPERATIONCODES_H
