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
      setBalance(getBalance() + tempOverdraft);
    }
  }
  Transaction transaction("Current Account Deposit",amount);
  addHistory(transaction);
  std::cout << std::fixed << std::setprecision(2);
  std::cout << amount <<" added to your balance\nYour new balance is : "<< getBalance()<<"\n";

}


//TO DO , LEGIT DO THE OVERDRAFT THING YOU SEE EVERY SINGLE DAY 
void Current::withdraw(float amount)
{
  float tempAmount = getBalance() - amount;
  if (tempAmount < 0)
  {
    float tempOverdraft = overdraft - amount;
    if (tempOverdraft > 0)
    {
      overdraft -= amount;
    }else{
      std::cout << "Not enough money in overdraft\n";
    }
  }else{
    setBalance(getBalance() - amount);
  }
  std::cout << "Balance : "<< getBalance() << "\nOverdraft : "<< overdraft << "\n"; 
}

