#ifndef CURRENT_H
#define CURRENT_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>

#include "Account.h"


/*
Current inherits from the account class
There can only be one current account
*/

class Current : public Account
{
  public:
    Current(float initialDeposit);
    std::string toString(float input);
    void deposit(float amount);
    void withdraw(float amount);
    void display();
    void displayInterest(float time);
    std::string getType();
    float getBalance();
    void addHistory(Transaction input);
    void displayHistory();
};

#endif