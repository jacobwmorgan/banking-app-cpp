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
    Saving();
  private:
    int interestRate;
    bool isa;
};

#endif