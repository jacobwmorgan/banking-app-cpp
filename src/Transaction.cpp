#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <iomanip> 
#include <chrono>
#include <time.h> 
#include "Transaction.h"

std::string Transaction::toString(float input)
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
  char* dt = ctime(&timestamp); //Gets the time from the computer
  return dt;
}

void Transaction::setTimeStamp()
{
  //std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  time_t now = time(0); //Sets timestamp to something that we can use
  timestamp = now;
}

float Transaction::getValue()
{
  return value;
}

void Transaction::setValue(float input)
{
  value = input;
}

void Transaction::displayTransaction()
{
  std::cout << std::fixed << std::setprecision(2);
  std::cout << "\n-----------\n" << getTimeStamp() << " >> " << getDesc() << " | " << getValue() <<"\n";
}

//Constructor for transaction
Transaction::Transaction(std::string inputDesc , float inputValue)
{
  setDesc(inputDesc);
  setTimeStamp();
  setValue(inputValue);
}