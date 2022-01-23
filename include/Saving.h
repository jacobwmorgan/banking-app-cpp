#ifndef SAVING_H
#define SAVING_H


#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>

#include "Account.h"
#include "Interest_Earning.h"


/*
  Saving is the same as current other than it can have two types
  A standard saving account or an ISA
  The only difference is the interest rate
  This means the savings account has much more complexity than the current account
*/

class Saving : public Account , public Interest_Earning
{
  public:
    Saving(float initialDeposit,bool isaInput);
    std::string toString(float input);
    float getInterestRate();
    void setInterestRate();
    bool getIsa();
    void setIsa(bool input);
    std::string isaString();

    void deposit(float amount);
    void withdraw(float amount);
  
    std::string getType();
    float getBalance();

    void addHistory(Transaction input);
    void displayHistory();

    void displayInterest(float time);
    void display();

  private:
    float interestRate;
    bool isa;
};

#endif