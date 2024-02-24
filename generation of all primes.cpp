#include <stdio.h>
#include <stdbool.h>

bool isPrime(int number, int divisor) {
    // Base cases
    if (number <= 1) 
        return false;
    if (divisor == 1) 
        return true;
    if (number % divisor == 0) 
        return false;
    
    // Recursive case
    return isPrime(number, divisor - 1);
}

void generatePrimes(int current, int limit) {
    // Base case
    if (current > limit) 
        return;
    
    // Check if current number is prime
    if (isPrime(current, current / 2)) 
        printf("%d ", current);
    
    // Recur to the next number
    generatePrimes(current + 1, limit);
}

int main() {
    int upperLimit;

    printf("Enter the upper limit: ");
    scanf("%d", &upperLimit);

    printf("Prime numbers up to %d are: ", upperLimit);
    generatePrimes(2, upperLimit);

    return 0;
}
