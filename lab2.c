#include <stdio.h>
int main()
{
    const int n = 3;
	printf("Программа расчета суммы элементов главной и побочной диагонали матрицы 3x3 и расчета квадрата матрицы 2x2\n");
    double arr1[n][n] = {};
	printf("Введите значения матрицы(после ввода каждого значения нажимайте Enter):\n");
    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            scanf("%lf",&arr1[i][j]);
        }
    }
    double sum1 = 0, sum2 = 0;
    for(int i = 0; i < n; i++)
    {
        sum1 += arr1[i][i];
        sum2 += arr1[i][n - 1 - i];
    }
    printf("Сумма элементов на главной диагонали: %lf\nСумма элементов на побочной диагонали: %lf\n", sum1, sum2);
	printf("Введите значения матрицы(после ввода каждого значения нажимайте Enter):\n");	
    int arr2[2][2] = {};
    int arr[2][2] = {};
    for(int i = 0; i< 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            scanf("%d",&arr2[i][j]);
        }
    }
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
        {
            arr[i][j] = 0;
            for(int k = 0; k < 2; k++)
                arr[i][j] += arr2[i][k] * arr2[k][j];
        }

    printf("Квадрат матрицы: \n%d %d\n%d %d\n", arr[0][0], arr[0][1], arr[1][0], arr[1][1]);
}
