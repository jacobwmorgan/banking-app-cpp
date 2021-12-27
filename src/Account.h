#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <iomanip> 
#include <chrono>
#include <ctime> 
#include "Transaction.h"

/*
Header file for Account class
*/

class Account
{
  public:

    virtual void deposit(double amount);
    virtual double withdraw(double amount);
    std::string toString(double input);

    
    //Function to display account details (Balance , name , account type etc)
    void display();
    //Getters and Setters for the account details
    void setName(std::string input);
    std::string getName();
    void setNumber();
    int getNumber();
    void setType(char input);
    std::string getType();


    void setBalance(double input);
    double getBalance();

    void addHistory(Transaction input);
    void displayHistory();

    Account();

  protected:
    double balance;
    std::vector<Transaction> history;
  
  private:
    std::string name;
    int number;
    char type;
};

#endif
