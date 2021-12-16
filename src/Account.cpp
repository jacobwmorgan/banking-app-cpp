#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include "Account.h"

Account::Account()
{
  std::string str;
  std::getline(std::cin,str);
  setName(str);
  //genAccountNumber();
  std::cout << "Account has been created\n"<<getName()<<"\n"<<getNumber()<<"\n";
}

Account::~Account()
{
  std::cout << "Account has been deleted\n";
}

Account::toString(string input)
{
  return std::to_string(input);
}

Account::deposit(int amount)
{
  std::cout << "WIP\n";
}

Account::withdraw(int amount)
{
  std::cout << "WIP\n";
  return 0;
}

Account::setName(string input)
{
  name = input;
}

Account::genAccountNumber(std::vector<Account> accounts)
{
  std::cout << "WIP\n";
  accountNumber = "0";  
}

Account::getName()
{
  return name;
}

Account::getNumber()
{
  return accountNumber;
}



