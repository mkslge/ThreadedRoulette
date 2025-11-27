//
// Created by Mark on 11/26/25.
//

#ifndef OPERATIONCODES_H
#define OPERATIONCODES_H



class OperationCodes {
public:
    static const char* EXIT_CODE;
    static const char* JOIN_CODE;
private:
    OperationCodes();
public:
    const static char* get_exit_code();
    const static char* get_join_code();

};



#endif //OPERATIONCODES_H
