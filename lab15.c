#include <stdio.h>

void ForwardWrite(int N)
{
    if (N < 10)
    {
        printf("%d ", N);
    }
    else
    {
        ForwardWrite(N / 10);
        printf("%d ", N % 10);
    }
}

void BackWrite(int N)
{
    if (N < 10)
    {
        printf("%d ", N);
    }
    else
    {
        printf("%d ", N % 10);
        ForwardWrite(N / 10);
    }
}

int main()
{
    int Num;
    printf("Введите число: ");
    scanf("%d", &Num);

    printf("Число в обычном порядке: ");
    ForwardWrite(Num);

    printf("\nЧисло в обратном порядке: ");
    BackWrite(Num);
    printf("\n");

}