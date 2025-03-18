#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "S&P.h"

int main()
{
    double a, b, c;
    printf("Введите длины сторон треугольника: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    if (Exst(a, b, c)) 
    {
        printf("Площадь треугольника: %lf\n", S(a, b, c));
        printf("Периметр треугольника: %lf\n", P(a, b, c));
    } 
    else {
        printf("Треугольник не существует\n");
    }
}