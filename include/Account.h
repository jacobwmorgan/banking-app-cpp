#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>

/*
Header file for Account class
*/

class Account
{
  public :
    Account();
    virtual ~Account();
    std::string toString(std::string input);
    virtual void deposit(int amount);
    int withdraw (int amount);
    void setName(std::string input);
    void genAccountNumber(std::vector<Account> accounts);
    std::string getName();
    int getNumber();

   
  private :
    std::string name;
    std::string accountNumber;
  protected :
    int balance;
    std::vector <std::string> history;
};

#endif
