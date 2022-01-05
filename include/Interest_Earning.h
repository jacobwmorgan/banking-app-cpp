#ifndef INTEREST_EARNING_H
#define INTEREST_EARNING_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>


//p = Amount , r = rate of interest , t = time period 

class Interest_Earning
{
  public:
    float computeInterest(float p , float r , float t);
};


#endif