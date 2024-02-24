#include <stdio.h>
#include <limits.h>

// Function to find the sum of frequencies from i to j
int sumFreq(int freq[], int i, int j) {
    int sum = 0;
    for (int k = i; k <= j; k++) {
        sum += freq[k];
    }
    return sum;
}

// Function to find the optimal cost of constructing an optimal BST
int optimalBST(int keys[], int freq[], int n) {
    // Create a 2D array to store optimal costs
    int cost[n + 1][n + 1];
    
    // Initialize the cumulative frequencies
    int cumFreq[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
        cumFreq[i][i] = freq[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cumFreq[i][j] = cumFreq[i][j - 1] + freq[j];
        }
    }

    // Calculate the optimal costs
    for (int length = 1; length <= n; length++) {
        for (int i = 1; i <= n - length + 1; i++) {
            int j = i + length - 1;
            cost[i][j] = INT_MAX;
            for (int r = i; r <= j; r++) {
                int temp = ((r > i) ? cost[i][r - 1] : 0) +
                           ((r < j) ? cost[r + 1][j] : 0) +
                           sumFreq(freq, i, j);
                if (temp < cost[i][j]) {
                    cost[i][j] = temp;
                }
            }
        }
    }
    
    // Return the optimal cost
    return cost[1][n];
}

int main() {
    int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    int keys[n + 1], freq[n + 1];
    printf("Enter the keys:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &keys[i]);
    }
    printf("Enter the frequencies:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &freq[i]);
    }

    int optimalCost = optimalBST(keys, freq, n);
    printf("Optimal cost of constructing the optimal BST: %d\n", optimalCost);

    return 0;
}
