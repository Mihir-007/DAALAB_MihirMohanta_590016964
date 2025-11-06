#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
int knapsack_dp(int w[], int v[], int n, int cap) {
    int dp[n+1][cap+1];
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=cap; j++)
        {
            if(i==0 || j==0) {
                dp[i][j]=0;
            }
            else if(w[i-1]<=j) {
                dp[i][j]=max(v[i-1]+dp[i-1][j-w[i-1]], dp[i-1][j]);
            }
            else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][cap];
}
void knapsack_greedy(int w[], int v[], int n, int cap) {
    float ratio[n];
    for(int i=0;i<n;i++)
        ratio[i]=(float)v[i]/w[i];
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(ratio[i]<ratio[j])
            {
                float t=ratio[i];
                ratio[i]=ratio[j];
                ratio[j]=t;
                int x=w[i];
                w[i]=w[j];
                w[j]=x;
                x=v[i];
                v[i]=v[j];
                v[j]=x;
            }
        }
    }
    int tw=0, tv=0;
    for(int i=0;i<n;i++)
    {
        if(tw+w[i]<=cap) {
            tw+=w[i];
            tv+=v[i];
        }
    }
    printf("Value by greedy approach = %d\n", tv);
}
int main() {
    int n=4, cap=9;
    int w1[]={2,3,4,5}, v1[]={3,4,5,8};
    int w2[]={2,3,4,5}, v2[]={3,4,5,8};
    printf("Max value by dynamic programming = %d\n", knapsack_dp(w1,v1,n,cap));
    knapsack_greedy(w2,v2,n,cap);
    return 0;
}
