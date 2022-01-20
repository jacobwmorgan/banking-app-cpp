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
    float overdraft;
    Current(float initialDeposit);
    void deposit(float amount);
    void withdraw(float amount);
    void display();
    void displayInterest(float time);
};

#endif