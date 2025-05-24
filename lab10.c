#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX(a, b) ((a)/(b))

int main()
{
    char string[256];
    printf("Введите числа через пробел: ");
    fgets(string, sizeof(string), stdin);

    char *token = strtok(string, " ");
    int sum = 0;
    int c = 0;

    while(token)
    {
       int num = atol(token);
       sum += num;
       c++;
       token = strtok(NULL, " ");
    }

    printf("Среднее арифметическое число - %d\n", MAX(sum, c));
}