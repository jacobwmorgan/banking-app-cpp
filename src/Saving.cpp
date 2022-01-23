#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include "Saving.h"
#include "Transaction.h"

//Constructor for Savings Class
Saving::Saving(float initialDeposit, bool isaInput)
{
  setIsa(isaInput); //Sets isa to isaInput
  setInterestRate(); //Checks the isa and sets interestrate
  if(isaInput == false)
  {
    std::cout << "Savings Account made\n";
  }
  else
  {
    std::cout << "ISA Savings Account made\n";
  }
  //Checks if there is an initial deposit , if so the amount will be deposited
  if(initialDeposit > 0) deposit(initialDeposit);
}

std::string Saving::toString(float input)
{
  return std::to_string(input);
}

float Saving::getInterestRate()
{
  return interestRate;
}

void Saving::setInterestRate()
{
 if(isa == true)interestRate = 1.15;
 else interestRate = 0.85;
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
  if(getIsa() == true) return "Yes";
  else return "No";
  
}

void Saving::deposit(float amount)
{
  //Adds the money into the account
  balance += amount;
  Transaction transaction("Savings Account Deposit",amount);
  addHistory(transaction);
  std::cout << std::fixed << std::setprecision(2);
  std::cout << amount <<" added to your saving account balance\nYour new balance is : "<< balance<<"\n";
}

void Saving::withdraw(float amount)
{
  //Checks if they have enough money for the transaction
  if((balance - amount) < 0) std::cout << "Not enough money in account\nTransaction Canceled\n";
  else
  {
    balance -= amount;
    Transaction transaction("Savings Account Withdraw",amount);
    addHistory(transaction);
    std::cout << amount << " withdrew from saving account balance\nYour new balance is : "<<balance<<"\n";
  }
}

std::string Saving::getType()
{
  if(getIsa() == true) return "ISA Savings";
  else return "Saving";
}

float Saving::getBalance()
{
  return balance;
}

void Saving::addHistory(Transaction input)
{
  history.push_back(input);
}

void Saving::displayHistory()
{
  //Checks if the user has any history 
  if(history.size() == 0) std::cout << "You have no history of transactions \n";
  else
  {
    std::cout << "Date & Time | Description | Amount\n";
    for (int i = 0; i < history.size(); i++)
    {
      /* code */
      history[i].displayTransaction();
    }
  }
}

void Saving::displayInterest(float time)
{
  //Displays the interest
  std::cout << computeInterest(balance,getInterestRate(),time) << "\n";
}

void Saving::display()
{
  std::cout << std::fixed << std::setprecision(2);
  //std::cout << "-----------\nAccount Details\nName: "<< getName() <<"\nAccount Number: "<< getNumber() <<"\nAccount Type: "<<getType()<<"\n=========\nBalance: "<< balance << "\nISA: "<<isaString()<<"\n";
  std::cout << "-----------\nAccount Details\nAccount Type : "<< getType() << "\nBalance : " << balance << "\nInterest Rate : " << getInterestRate() << "\n";
}

