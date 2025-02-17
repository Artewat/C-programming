#include <stdio.h>
int main()
{
    double arr1[3][3] = {};
    for(int i = 0; i< 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            scanf("%lf",&arr1[i][j]);
        }
    }
    printf("Сумма элементов на главной диагонали: %lf\nСумма элементов на побочной диагонали: %lf\n", arr1[0][0]+arr1[1][1]+arr1[2][2], arr1[0][2]+arr1[1][1]+arr1[2][0]);
    int arr2[2][2] = {};
    for(int i = 0; i< 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            scanf("%d",&arr2[i][j]);
        }
    }
    printf("Квадрат матрицы: \n%d %d\n%d %d\n", (arr2[0][0]*arr2[0][0])+(arr2[0][1]*arr2[1][0]), (arr2[0][0]*arr2[0][1])+(arr2[0][1]*arr2[1][1]), (arr2[0][0]*arr2[1][0]) + (arr2[1][1]*arr2[1][0]), (arr2[1][0]*arr2[0][1]) + (arr2[1][1]*arr2[1][1]));
}