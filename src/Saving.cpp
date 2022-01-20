#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include "Saving.h"
#include "Transaction.h"


Saving::Saving(float initialDeposit, bool isaInput)
{
  setIsa(isaInput);
  setInterestRate();
  if(isaInput == false)
  {
    setType('s');
    std::cout << "Savings Account made\n";
  }
  else
  {
    setType('i');
    std::cout << "ISA Savings Account made\n";
  }
  
  if(initialDeposit > 0) deposit(initialDeposit);
}

float Saving::getInterestRate()
{
  return interestRate;
}

void Saving::setInterestRate()
{
 if(isa == true)
 {
   interestRate = 1.15;
 }else
 {
   interestRate = 0.85;
 }
}

bool Saving::getIsa()
{
  return isa;
}

void Saving::setIsa(bool input)
{
  isa = input;
}

std::string Saving::isaString()
{
  if(getIsa() == true)
  {
    return "Yes";
  }else
  {
    return "No";
  }
}

void Saving::deposit(float amount)
{
  setBalance(getBalance() + amount);
  Transaction transaction("Savings Account Deposit",amount);
  addHistory(transaction);
  std::cout << std::fixed << std::setprecision(2);
  std::cout << amount <<" added to your saving account balance\nYour new balance is : "<< getBalance()<<"\n";
}

void Saving::withdraw(float amount)
{
  if((getBalance() - amount) < 0)
  {
    std::cout << "Not enough money in account\nTransaction Canceled\n";
  }else
  {
    setBalance(getBalance() - amount);
    std::cout << amount << " withdrew from saving account balance\nYour new balance is : "<<getBalance()<<"\n";
  }
}

void Saving::displayInterest(float time)
{
  std::cout << computeInterest(getBalance(),getInterestRate(),time) << "\n";
}

void Saving::display()
{
  std::cout << std::fixed << std::setprecision(2);
  //std::cout << "-----------\nAccount Details\nName: "<< getName() <<"\nAccount Number: "<< getNumber() <<"\nAccount Type: "<<getType()<<"\n=========\nBalance: "<< getBalance() << "\nISA: "<<isaString()<<"\n";
  std::cout << "-----------\nAccount Details\nAccount Type : "<< getType() << "\nBalance : " << getBalance() << "\nInterest Rate : " << getInterestRate() << "\n";
}
