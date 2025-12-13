//
// Created by Mark on 11/28/25.
//

#ifndef CLIENTINFO_H
#define CLIENTINFO_H



inline int DEFAULT_STARTING_BALANCE = 100;

class clientinfo {
    int balance;
public:
    clientinfo();
    clientinfo(int starting_balance);
    int get_balance();
    void add_balance(int amount);
    void remove_balance(int amount);
    bool sufficient_balance(int bet_amount) const;
};



#endif //CLIENTINFO_H
