#include <stdio.h>

int main() {
    int number, remainder, sum = 0;

    // Input the number
    printf("Enter a number: ");
    scanf("%d", &number);

    // Calculate the sum of digits
    while (number != 0) {
        remainder = number % 10; // Get the last digit
        sum += remainder; // Add it to the sum
        number /= 10; // Remove the last digit
    }

    // Print the sum of digits
    printf("Sum of digits: %d\n", sum);

    return 0;
}
