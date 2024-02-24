#include <stdio.h>

void printPattern(int n) {
    if (n > 0) {
        printPattern(n - 1); // Recursively call printPattern with n-1 to print the previous row
        for (int i = 1; i <= n; i++) {
            printf("%d ", i); // Print numbers from 1 to n
        }
        printf("\n"); // Move to the next line after printing each row
    }
}

int main() {
    int rows;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printPattern(rows);

    return 0;
}
