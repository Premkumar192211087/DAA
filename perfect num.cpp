#include <stdio.h>

int main() {
    int n, i, sum = 0;
    
    // Input a number from the user
    printf("Enter a number: ");
    scanf("%d", &n);
    
    // Find sum of divisors
    for (i = 1; i <= n/2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    
    // Check if the number is perfect
    if (sum == n) {
        printf("%d is a perfect number.\n", n);
    } else {
        printf("%d is not a perfect number.\n", n);
    }
    
    return 0;
}
