#include <stdio.h>
unsigned long long binomialCoefficient(int n, int k) {
    unsigned long long dp[n + 1][k + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i && j <= k; j++) {
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    return dp[n][k];
}
int main() {
    int n, k;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of k: ");
    scanf("%d", &k);
    printf("Binomial coefficient of %d choose %d is %llu\n", n, k, binomialCoefficient(n, k));
    return 0;
}
