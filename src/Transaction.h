#ifndef TRANS_H
#define TRANS_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <iomanip> 
#include <chrono>
#include <ctime> 

class Transaction
{
  public:
    std::string toString(double input);
    std::string getDesc();
    void setDesc(std::string input);
    char* getTimeStamp();
    void setTimeStamp();
    double getValue();
    void setValue(double input);
    void displayTransaction();

    Transaction(std::string inputDesc , double inputValue);
  private:
    std::string desc;
    std::time_t timestamp;
    double value;

};


#endif
