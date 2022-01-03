#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include "Saving.h"
#include "InterestEarning.h"

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



Saving::Saving(bool isaInput)
{
  isa = isaInput;
}