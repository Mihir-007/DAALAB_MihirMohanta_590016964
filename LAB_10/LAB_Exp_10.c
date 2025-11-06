#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}
int knapsack(int w[], int v[], int n, int cap) {
    int dp[n+1][cap+1];
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=cap; j++) {
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(w[i-1] <= j)
                dp[i][j] = max(v[i-1] + dp[i-1][j - w[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][cap];
}
int main() {
    int n = 4;
    int weight[] = {2, 3, 4, 5};
    int value[] = {3, 4, 5, 8};
    int capacity = 9;
    int max_val = knapsack(weight, value, n, capacity);
    printf("maximum value in knapsack = %d\n", max_val);
    return 0;
}