#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool Exst(double a, double c, double b)
{
    if (((a + b) > c) && ((a + c) > b) && ((b + c) > a)) {
        return 1;
    } 
    else 
    {
        return 0;
    }
}
double P(double a, double b, double c)
{
    return(a + b +c);
}
double S(double a, double b, double c)
{
    double p = P(a, b, c) / 2; 
    return sqrt(p * (p - a) * (p - b) * (p - c));
}