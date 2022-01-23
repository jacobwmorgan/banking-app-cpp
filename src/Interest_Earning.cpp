
#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <math.h>
#include "Interest_Earning.h"

//p = Amount , r = rate of interest , t = time period 

float Interest_Earning::computeInterest(float p , float r, float t)
{
  //Here ive used the math library to implement the interest rate equation
  return p*pow((1+r/100),t);
}