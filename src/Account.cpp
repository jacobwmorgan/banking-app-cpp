#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <iomanip> 
#include "Account.h"




void Account::deposit(double amount)
{
  setBalance(getBalance() + amount);
  std::cout << toString(amount) <<" added to your balance\nYour new balance is : "<< toString(getBalance())<<"\n";
}

double Account::withdraw(double amount)
{
  balance -= amount;
  return amount;
}

std::string Account::toString(double input)
{
  return std::to_string(input);
}

void Account::display()
{
  std::cout << std::fixed << std::setprecision(2);
  std::cout << "-----------\nAccount Details\nName: "<< getName() <<"\nAccount Number: "<< getNumber() <<"\nAccount Type: "<<getType()<<"\n=========\nBalance: "<< getBalance() << "\n";
}

void Account::setName(std::string input)
{
  name = input;
}

std::string Account::getName()
{
  return name;
}

void Account::setNumber()
{
  number = 2;
}

int Account::getNumber()
{
  return number;
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
  else
  {
    return NULL;
  }
}

void Account::setBalance(double input)
{
  balance = input;
}

double Account::getBalance()
{
  return balance;
}




Account::Account()
{
  balance = 0;
  std::string tempName;
  std::cout<<"Name: ";
  std::cin >> tempName;
  setName(tempName);
  setNumber();
  std::cout<<"Account created\n";
}
