#ifndef SAVING_H
#define SAVING_H


#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>

#include "Account.h"
#include "Interest_Earning.h"

class Saving : public Account , public Interest_Earning
{
  public:
    Saving(float initialDeposit,bool isaInput);
    float getInterestRate();
    void setInterestRate();
    bool getIsa();
    void setIsa(bool input);
    std::string isaString();

    void deposit(float amount);
    void withdraw(float amount);
    void displayInterest(float time);
    void display();
  private:
    float interestRate;
    bool isa;
};

#endif