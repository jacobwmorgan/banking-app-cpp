#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include "Transaction.h"

/*
Header file for Account class

Account is a virtual base class 
This allows for the other classes to inherit from it properly
*/

class Account 
{x
  public :
    virtual std::string toString(float input) = 0; // We need this to turn floats into strings so we can output them
    virtual void deposit(float amount) = 0; 
    virtual void withdraw (float amount) = 0;
    
    virtual void display() = 0; //This will display the accounts basic infomation
    virtual void displayInterest(float time) = 0 ; //This projects the users balance into the future

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
