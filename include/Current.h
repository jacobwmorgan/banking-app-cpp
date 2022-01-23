#ifndef CURRENT_H
#define CURRENT_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>

#include "Account.h"

class Current : public Account
{
  public:
    Current(float initialDeposit);
    std::string toString(float i nput);
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