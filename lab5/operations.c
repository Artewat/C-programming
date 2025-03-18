#include <stdio.h>
#include <stdlib.h>

double** create_matrix(int n) {
    double** matrix = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double*)malloc(n * sizeof(double));
    }
    return matrix;
}

void free_matrix(double** matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

double** add_matrices(double** a, double** b, int n) {
    double** result = create_matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    return result;
}

double** subtract_matrices(double** a, double** b, int n) {
    double** result = create_matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
    return result;
}

double** multiply_matrices(double** a, double** b, int n) {
    double** result = create_matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

double** perform_operation(double** a, double** b, int n, char operation) {
    switch (operation) {
        case '+':
            return add_matrices(a, b, n);
        case '-':
            return subtract_matrices(a, b, n);
        case '*':
            return multiply_matrices(a, b, n);
        default:
            return NULL;
    }
}