#include "Statzor.h"

double fact(double n)
    {
    double res = n;
    for(double i=(n-1); i>1; i--)
        {
        res *= i;
        }
    return res;
    }

