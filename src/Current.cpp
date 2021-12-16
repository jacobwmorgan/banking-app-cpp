#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include "Current.h"


Curent::virtual void deposit(int amount)
{
  std::cout << "WIP\n";
};

Current::Current() : Account()
{
  overdraft = 0;
};

