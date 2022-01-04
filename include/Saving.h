#ifndef SAVING_H
#define SAVING_H


#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>

#include "Account.h"
#include "InterestEarning.h"

class Saving : public Account , public InterestEarning
{
  public:
    Saving();
    float getInterestRate();
    void setInterestRate();
  private:
    float interestRate;
    bool isa;
};

#endif