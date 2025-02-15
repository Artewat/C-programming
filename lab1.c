#include <stdio.h>
#include <math.h>
int main()
{
    int a, b, c;
    printf("Print a b c: ");
    scanf("%d %d %d", &a, &b, &c);
    int D = b * b - 4 * a * c;
    float x1 = (-1*b + sqrt(D))/(2*a);
    float x2 = (-1*b - sqrt(D))/(2*a);
    printf("First x: %.2f\nSecond x: %.2f", x1, x2);
}