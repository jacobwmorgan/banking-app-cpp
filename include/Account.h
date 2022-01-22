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
    virtual std::string toString(float input) = 0;
    virtual void deposit(float amount) = 0;
    virtual void withdraw (float amount) = 0;
    
    virtual void display() = 0;
    virtual void displayInterest(float time) = 0 ;

    virtual std::string getType() = 0;
    virtual float getBalance() = 0;

    virtual void addHistory(Transaction input) = 0;
    virtual void displayHistory() = 0;

    float overdraft;

  protected :
    float balance;
    std::vector <Transaction> history;
};

#endif
