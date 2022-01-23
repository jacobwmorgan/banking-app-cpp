#ifndef TRANSACTION_H
#define TRANSACTION_H


#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <iomanip> 
#include <chrono>
#include <time.h> 

/*
Transaction is an object used for storing the users "transactions" in a vector in the other classes
*/

class Transaction
{
  public:
    std::string toString(float input);
    std::string getDesc();
    void setDesc(std::string input);
    char* getTimeStamp();
    void setTimeStamp();
    float getValue();
    void setValue(float input);
    void displayTransaction();

    Transaction(std::string inputDesc, float inputValue);
  private:
    float value;
    time_t timestamp; //Time_t allows c++ to grab the accurate time of the machine
    std::string desc;

};


#endif