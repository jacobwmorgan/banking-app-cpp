#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <iomanip> 
#include <chrono>
#include <time.h> 
#include "Transaction.h"

std::string Transaction::toString(double input)
{ 
  return std::to_string(input);
}

std::string Transaction::getDesc()
{
  return desc;
}

void Transaction::setDesc(std::string input)
{
  desc = input;
}

char* Transaction::getTimeStamp()
{
  char* dt = ctime(&timestamp);
  return dt;
}

void Transaction::setTimeStamp()
{
  //std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  time_t now = time(0);
  timestamp = now;
  std::cout<<"Time Stamp set\n";
}

double Transaction::getValue()
{
  return value;
}

void Transaction::setValue(double input)
{
  value = input;
}

void Transaction::displayTransaction()
{
  std::cout << "omg kill me | " << getDesc() << " | " << toString(getValue()) <<"\n";
  //std::cout << getTimeStamp() << "\n";
  std::cout << "ffs\n";
}

Transaction::Transaction(std::string inputDesc , double inputValue)
{
  setDesc(inputDesc);
  setTimeStamp();
  setValue(inputValue);
  std::cout << "Transation logged\n";
}