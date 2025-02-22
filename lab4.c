#include <stdio.h>
#include <math.h>
int P(int a, int b, int c)
{
    return(a + b +c);
}
int S(int a, int b, int c)
{
    return(sqrt(P(a, b, c)/2 * ((P(a, b, c)/2) - a) * ((P(a, b, c)/2) - b) * ((P(a, b, c)/2) - c)));
}
int main()
{
    int a, b, c;
    printf("Введите длины сторон треугольника: ");
    scanf("%d %d %d", &a, &b, &c);
    if(!(((a + b) <= c) | ((a + c) <= b) | ((b + c) <= a)))
    {
        printf("Плошадь треугольника: %d\nПериметр треугольника: %d\n", S(a, b, c), P(a, b, c));
    }
}