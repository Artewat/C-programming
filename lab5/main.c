#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

double** perform_operation(double** a, double** b, int n, char operation);

int main() {
    int n;
    printf("Введите размерность матриц (n): ");
    scanf("%d", &n);

    double** matrix_a = (double**)malloc(n * sizeof(double*));
    double** matrix_b = (double**)malloc(n * sizeof(double*));

    for (int i = 0; i < n; i++) {
        matrix_a[i] = (double*)malloc(n * sizeof(double));
        matrix_b[i] = (double*)malloc(n * sizeof(double));
    }

    printf("Введите элементы первой матрицы:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix_a[i][j]);
        }
    }

    printf("Введите элементы второй матрицы:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix_b[i][j]);
        }
    }

    char operation;
    printf("Введите знак операции (+, -, *): ");
    scanf(" %c", &operation);

    double** result = perform_operation(matrix_a, matrix_b, n, operation);

    if (result != NULL) {
        printf("Результат:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%.2lf ", result[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Ошибка: неверный знак операции.\n");
    }

    for (int i = 0; i < n; i++) {
        free(matrix_a[i]);
        free(matrix_b[i]);
    }
    free(matrix_a);
    free(matrix_b);
    free(result);
}