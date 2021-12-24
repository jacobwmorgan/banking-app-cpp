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
    int overdraft;
    void deposit(float amount);
    float withdraw(float amount);
    bool checkOverDraft();
    Current();
};

#endif