#include <iostream>
#include <chrono>
#include <sstream>
#include <vector>
#include <string.h>
#include <iomanip> 
#include "Account.h"
#include "Transaction.h"



// void Account::deposit(float amount)\
// {
//   Transaction transaction("Deposit",amount);
//   addHistory(transaction);
//   setBalance(getBalance() + amount);
//   std::cout << toString(amount) <<" added to your balance\nYour new balance is : "<< getBalance()<<"\n";
// }

// void Account::withdraw(float amount)
// {
//   balance -= amount;
// }

std::string Account::toString(float input)
{
  return std::to_string(input);
}

void Account::setType(char input)
{
  type = input;
}

std::string Account::getType()
{
  if(type == 'c')
  {
    return "Current";
  }
  else if (type == 's')
  {
    return "Savings";
  }
  else if (type == 'i')
  {
    return "ISA Savings";
  }
  else
  {
    return NULL;
  }
}

void Account::setBalance(float input)
{
  balance = input;
}

float Account::getBalance()
{
  return balance;
}

void Account::addHistory(Transaction input)
{
  history.push_back(input);
}

void Account::displayHistory()
{
  if(history.size() == 0)
  {
    std::cout << "You have no history of transactions \n";
  }else
  {
    std::cout << "Date & Time | Description | Amount\n";
    for (int i = 0; i < history.size(); i++)
    {
      /* code */
      history[i].displayTransaction();
    }
  }
}