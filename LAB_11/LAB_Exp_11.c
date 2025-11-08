#include <stdio.h>
#include <limits.h>

void print_parenthesis(int i, int j, int n, int bracket[][n], char *name) {
    if (i == j)
    {
        printf("%c", (*name)++);
        return;
    }
    printf("(");
    print_parenthesis(i, bracket[i][j], n, bracket, name);
    print_parenthesis(bracket[i][j] + 1, j, n, bracket, name);
    printf(")");
}
void matrix_chain_order(int p[], int n) {
    int m[n][n];
    int bracket[n][n];
    for (int i = 1; i < n; i++)
    {
        m[i][i] = 0;
    }
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }
    printf("minimum number of multiplications: %d\n", m[1][n - 1]);
    printf("Optimal parenthesization: ");
    char name = 'A';
    print_parenthesis(1, n - 1, n, bracket, &name);
    printf("\n");
}
int main() {
    int n;
    printf("enter  the number of matrices: ");
    scanf("%d", &n);
    int p[n + 1];
    printf("enter dimensions of the array (size %d): ", n + 1);
    for (int i = 0; i <= n; i++)
        scanf("%d", &p[i]);
    matrix_chain_order(p, n + 1);
    return 0;
}
