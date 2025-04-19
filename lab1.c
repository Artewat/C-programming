#include <stdio.h>
#include <math.h>
int main()
{
    int t = 1;
    while(t != 0)
    {
        printf("A program for finding x's of a quadratic equation using a discriminant.\n");
        int a, b, c;
        printf("Print a b c: ");
        scanf("%d %d %d", &a, &b, &c);
        int D = b * b - 4 * a * c;
        if(D >= 0)
        {
            float x1 = (-1*b + sqrt(D))/(2*a);
            float x2 = (-1*b - sqrt(D))/(2*a);
            printf("First x: %.2f\nSecond x: %.2f", x1, x2);
        }
        else
        {
            printf("The discriminant is less than zero.\n");
        }
        printf("Would you like to continue?(1/0)\n");
        scanf("%d", &t);
    }
}
