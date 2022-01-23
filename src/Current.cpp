#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <cctype>
#include "Current.h"


//Constructor for Current account
Current::Current(float initialDeposit)
{
  std::cout<<"Current account created\n";
  overdraft = 500; //Sets the overdraft to 500
  if (initialDeposit > 0) //Checks if the deposit isn't nill
  {
    deposit(initialDeposit);// If not it deposits the amount
  }
}

std::string Current::toString(float input)
{
  return std::to_string(input); //Converts float to string
}


void Current::deposit(float amount)
{
  if(overdraft == 500) // Checks if the user is not in their overdraft
  {
    balance += amount;
  }
  else //If they are they add the amount to the overdraft
  {
    overdraft += amount;
    if(overdraft > 500) //Checks if the limit for the overdraft is reached , so the remainder must go into the standard account
    {
      float tempOverdraft = overdraft - 500; //Gets the difference
      overdraft = 500; //Sets overdraft back to 500
      balance += tempOverdraft; // Adds remainder to the balance
    }
  }
  Transaction transaction("Current Account Deposit",amount); //Creates new transaction
  addHistory(transaction); // Adds it to history
  std::cout << std::fixed << std::setprecision(2);
  std::cout << amount <<" added to your current account balance\nYour new balance is : "<< balance<<"\n";

}

//Withdraw for current account
void Current::withdraw(float amount)
{
  float tempAmount = balance - amount;
  if (tempAmount < 0) //Checks if you have enough money in your account
  {
    char userCommand;
    //UI for checking if the user wants to withdraw from their overdraft
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
      float tempOverdraft = overdraft - amount; //Checks if withdraw can be done
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
  //This function never gets called
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
    //Iterates through history and displays them
    for (int i = 0; i < history.size(); i++)
    {
      /* code */
      history[i].displayTransaction();
    }
  }
}