#include <stdio.h>

// Function prototype for min function
int min(int a, int b);

// Function to calculate the binomial coefficient of given n and k
int binomialCoefficient(int n, int k) {
    int C[n + 1][k + 1];
    int i, j;

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    return C[n][k];
}

// Function to find the minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n, k;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of k: ");
    scanf("%d", &k);
    printf("Binomial coefficient C(%d, %d) is: %d\n", n, k, binomialCoefficient(n, k));
    return 0;
}
