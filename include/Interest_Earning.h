#ifndef INTEREST_EARNING_H
#define INTEREST_EARNING_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>

/*
This is an interface used to work out the projection of the balance
It implements the interest rate equation in the function Interest_Earning and returns it to the user
*/

class Interest_Earning
{
  public:
    float computeInterest(float p , float r , float t);
};

#endif