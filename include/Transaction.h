#ifndef TRANSACTION_H
#define TRANSACTION_H


#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <iomanip> 
#include <chrono>
#include <time.h> 

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
    time_t timestamp;
    std::string desc;

};


#endif