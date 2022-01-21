#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <cctype>
#include "Current.h"

Current::Current(float initialDeposit)
{
  std::cout<<"Current account created\n";
  overdraft = 500;
  if (initialDeposit > 0)
  {
    deposit(initialDeposit);
  }
}

std::string Current::toString(float input)
{
  return std::to_string(input);
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
  Transaction transaction("Current Account Deposit",amount);
  addHistory(transaction);
  std::cout << std::fixed << std::setprecision(2);
  std::cout << amount <<" added to your current account balance\nYour new balance is : "<< balance<<"\n";

}


//TO DO , LEGIT DO THE OVERDRAFT THING YOU SEE EVERY SINGLE DAY 
void Current::withdraw(float amount)
{
  float tempAmount = balance - amount;
  if (tempAmount < 0)
  {
    char userCommand;
    while(userCommand != 'y')
    {
      std::cout << "Do you want to withdraw from your overdraft ? [Y/N]\n>>";
      std::cin >> userCommand;
      userCommand = std::tolower(userCommand);
      if (userCommand != 'n' && userCommand != 'y')
      {
        std::cout << "\nInvalid input\n";
      }
      else if(userCommand == 'n')
      {
        std::cout << "Withdraw canceled\n";
        break;
      }
    }  
    if (userCommand == 'y')
    {
      float tempOverdraft = overdraft - amount;
      if (tempOverdraft > 0)
      {
        overdraft -= amount;
      }else{
        std::cout << "Not enough money in overdraft\n";
      }
    }
  }else{
    balance -= amount;
  }
  std::cout << "Balance : "<< balance << "\nOverdraft : "<< overdraft << "\n"; 
}

void Current::displayInterest(float time)
{
  std::cout <<"\n";
}

void Current::display()
{
  std::cout << std::fixed << std::setprecision(2);
  //std::cout << "-----------\nAccount Details\nName: "<< getName() <<"\nAccount Number: "<< getNumber() <<"\nAccount Type: "<<getType()<<"\n=========\nBalance: "<< balance << "\nOverdraft: "<< overdraft <<"\n";
  std::cout  << "-----------\nAccount Type : "<< getType() << "\n" << "Balance : "<< balance << "\n" <<"Overdraft : " << overdraft << "\n\n";
}

std::string Current::getType()
{
  return "Current";
}

float Current::getBalance()
{
  return balance;
}

void Current::addHistory(Transaction input)
{
  history.push_back(input);
}

void Current::displayHistory()
{
  if(history.size() == 0)
  {
    std::cout << "You have no history of transactions \n";
  }else
  {
    std::cout << "-----------\nDate & Time | Description | Amount";
    for (int i = 0; i < history.size(); i++)
    {
      /* code */
      history[i].displayTransaction();
    }
  }
}