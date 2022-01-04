#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include "Saving.h"


Saving::Saving()
{
  char userCommand;
  std::cout << "Do you want your account to be an isa? [Y/N]\n>>";
  while (userCommand != 'y' || userCommand != 'n')
  {
    std::cin >> userCommand;
    userCommand = std::tolower(userCommand);
    if (userCommand != 'n' && userCommand != 'y')
    {
      std::cout << "\nInvalid input\n";
    }
  }
  setIsa(userCommand);
  setInterestRate();
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

void Saving::setIsa(char input)
{
  if(input == 'y')
  {
    isa = true;
  }
  else
  {
    isa = false;
  }
}

//depo

//with

//display

void Saving::display()
{
  std::cout << std::fixed << std::setprecision(2);
  std::cout << "-----------\nAccount Details\nName: "<< getName() <<"\nAccount Number: "<< getNumber() <<"\nAccount Type: "<<getType()<<"\n=========\nBalance: "<< getBalance() << "\nISA: "<<std::noboolalpha << getIsa()<<"\n";
}
