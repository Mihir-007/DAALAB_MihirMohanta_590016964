#include <stdio.h>
#include <stdlib.h>

int** allocate_matrix(int n) {
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }
    return matrix;
}
void free_matrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
void print_matrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}
int** square_matrix_multiply_naive(int** A, int** B, int n) {
    int** C = allocate_matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}
int main() {
    int n = 2;

    int** A = allocate_matrix(n);
    int** B = allocate_matrix(n);
    
    int A_values[2][2] = {
        {1, 2},
        {3, 4}
    };
    int B_values[2][2] = {
        {5, 6},
        {7, 8}
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = A_values[i][j];
            B[i][j] = B_values[i][j];
        }
    }
    printf("Matrix A:\n");
    print_matrix(A, n);
    printf("\nMatrix B:\n");
    print_matrix(B, n);

    printf("\nMatrix Multiplication Result:\n");
    int** C = square_matrix_multiply_naive(A, B, n);
    print_matrix(C, n);

    free_matrix(A, n);
    free_matrix(B, n);
    free_matrix(C, n);

    return 0;
}
