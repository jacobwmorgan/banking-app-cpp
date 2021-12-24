#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include "Current.h"

Current::Current()
{
  std::cout<<"Current account created\n";
  overdraft = 500;
  setType('c');
}

void Current::deposit(float amount)
{
  if(overdraft == 500)
  {
    balance += amount;
  }
  else
  {
    overdraft += amount;
    if(overdraft > 500)
    {
      float tempOverdraft = overdraft - 500;
      overdraft = 500;
      balance += tempOverdraft;
    }
  }
  std::cout<<"lmao\n";
}

float Current::withdraw(float amount)
{
  std::cout<<"lmao\n";
  return 0;
}

