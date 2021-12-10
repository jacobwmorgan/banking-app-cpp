#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>

class Account
{
  public :
    std::string toString(std::string input);
    virtual void deposit(int amount);
    int withdraw (int amount);
  protected :
    int balance;
    std::vector <std::string> history;
};

#endif
