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
    setBalance(getBalance() + amount);
  }
  else
  {
    overdraft += amount;
    if(overdraft > 500)
    {
      float tempOverdraft = overdraft - 500;
      overdraft = 500;
      std::cout << overdraft;
      setBalance(getBalance() + tempOverdraft);
    }
  }
  Transaction transaction("Current Account Deposit",amount);
  addHistory(transaction);
  std::cout << std::fixed << std::setprecision(2);
  std::cout<< amount << " deposited\n";

}

float Current::withdraw(float amount)
{
  std::cout<<"WIP\n";
  return 0;
}

