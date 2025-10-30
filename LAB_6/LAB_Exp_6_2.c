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
int** add_matrices(int** A, int** B, int n) {
    int** C = allocate_matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}
int** square_matrix_multiply_recursive(int** A, int** B, int n) {
    if (n == 1) {
        int** C = allocate_matrix(1);
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }
    int sub_n = n / 2;
    int** A11 = allocate_matrix(sub_n);
    int** A12 = allocate_matrix(sub_n);
    int** A21 = allocate_matrix(sub_n);
    int** A22 = allocate_matrix(sub_n);
    int** B11 = allocate_matrix(sub_n);
    int** B12 = allocate_matrix(sub_n);
    int** B21 = allocate_matrix(sub_n);
    int** B22 = allocate_matrix(sub_n);
    
    for (int i = 0; i < sub_n; i++) {
        for (int j = 0; j < sub_n; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + sub_n];
            A21[i][j] = A[i + sub_n][j];
            A22[i][j] = A[i + sub_n][j + sub_n];
            
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + sub_n];
            B21[i][j] = B[i + sub_n][j];
            B22[i][j] = B[i + sub_n][j + sub_n];
        }
    }
    int** C11_prod1 = square_matrix_multiply_recursive(A11, B11, sub_n);
    int** C11_prod2 = square_matrix_multiply_recursive(A12, B21, sub_n);
    int** C11 = add_matrices(C11_prod1, C11_prod2, sub_n);

    int** C12_prod1 = square_matrix_multiply_recursive(A11, B12, sub_n);
    int** C12_prod2 = square_matrix_multiply_recursive(A12, B22, sub_n);
    int** C12 = add_matrices(C12_prod1, C12_prod2, sub_n);

    int** C21_prod1 = square_matrix_multiply_recursive(A21, B11, sub_n);
    int** C21_prod2 = square_matrix_multiply_recursive(A22, B21, sub_n);
    int** C21 = add_matrices(C21_prod1, C21_prod2, sub_n);

    int** C22_prod1 = square_matrix_multiply_recursive(A21, B12, sub_n);
    int** C22_prod2 = square_matrix_multiply_recursive(A22, B22, sub_n);
    int** C22 = add_matrices(C22_prod1, C22_prod2, sub_n);

    int** C = allocate_matrix(n);
    for (int i = 0; i < sub_n; i++) {
        for (int j = 0; j < sub_n; j++) {
            C[i][j] = C11[i][j];
            C[i][j + sub_n] = C12[i][j];
            C[i + sub_n][j] = C21[i][j];
            C[i + sub_n][j + sub_n] = C22[i][j];
        }
    }

    free_matrix(A11, sub_n);
    free_matrix(A12, sub_n);
    free_matrix(A21, sub_n);
    free_matrix(A22, sub_n);
    free_matrix(B11, sub_n);
    free_matrix(B12, sub_n);
    free_matrix(B21, sub_n);
    free_matrix(B22, sub_n);
    free_matrix(C11_prod1, sub_n);
    free_matrix(C11_prod2, sub_n);
    free_matrix(C12_prod1, sub_n);
    free_matrix(C12_prod2, sub_n);
    free_matrix(C21_prod1, sub_n);
    free_matrix(C21_prod2, sub_n);
    free_matrix(C22_prod1, sub_n);
    free_matrix(C22_prod2, sub_n);
    free_matrix(C11, sub_n);
    free_matrix(C12, sub_n);
    free_matrix(C21, sub_n);
    free_matrix(C22, sub_n);
    
    return C;
}
int main() {
    int n = 4;

    int** A = allocate_matrix(n);
    int** B = allocate_matrix(n);

    int A_values[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 1, 2, 3},
        {4, 5, 6, 7}
    };
    int B_values[4][4] = {
        {8, 7, 6, 5},
        {4, 3, 2, 1},
        {9, 8, 7, 6},
        {5, 4, 3, 2}
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = A_values[i][j];
            B[i][j] = B_values[i][j];
        }
    }
    printf("Matrix A:\n");
    print_matrix(A, n);
    printf("Matrix B:\n");
    print_matrix(B, n);

    printf("--- Recursive Matrix Multiplication ---\n");
    int** C_recursive = square_matrix_multiply_recursive(A, B, n);
    print_matrix(C_recursive, n);
    free_matrix(C_recursive, n);

    free_matrix(A, n);
    free_matrix(B, n);

    return 0;
}