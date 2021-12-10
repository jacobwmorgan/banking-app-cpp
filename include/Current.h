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
    Current();
};

#endif