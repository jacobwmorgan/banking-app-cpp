
#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <math.h>
#include "Interest_Earning.h"

//p = Amount , r = rate of interest , t = time period 

float Interest_Earning::computeInterest(float p , float r, int t)
{
  t *= 12;
  return p*pow((1+r/100),t);
}