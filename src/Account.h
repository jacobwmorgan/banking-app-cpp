#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip> 
#include <string.h>

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

    Account();

  protected:
    double balance;
    std::vector<std::string> history;
  
  private:
    std::string name;
    int number;
    char type;
};

#endif
