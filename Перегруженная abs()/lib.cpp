#include "lib.h"

#include <cstdio>

namespace Trankova
{

//перегруженная функция abs: печатает модуль числа

int abs(int  x)	
{
    return x < 0 ? -x: x;
}


long abs(long int x); 
{
    return x < 0 ? -x: x;
}


long long abs(long long x); 
{
    return x < 0 ? -x: x;
}


double abs(double x)
{
    return x < 0.0 ? –x: x;
}


float abs(float x); 
{
    return x < 0.0 ? –x: x;
}

}