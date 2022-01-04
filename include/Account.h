#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include "Transaction.h"

/*
Header file for Account class
*/

class Account
{
  public :
    std::string toString(float input);
    virtual void deposit(float amount) =0;
    virtual void withdraw (float amount)=0;
    
    virtual void display() = 0;
    
    void setName(std::string input);
    std::string getName();
    
    void setNumber();
    int getNumber();

    void setType(char input);
    std::string getType();

    void setBalance(float input);
    float getBalance();

    void addHistory(Transaction input);
    void displayHistory();
    
    Account();

  private :
    std::string name;
    int number;
    char type;
  protected :
    int balance;
    std::vector <Transaction> history;
};

#endif
