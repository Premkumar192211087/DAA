#include <stdio.h>
int isPrime(int n, int i);

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (isPrime(num, num / 2) == 1)
        printf("%d is a prime number.\n", num);
    else
        printf("%d is not a prime number.\n", num);

    return 0;
}
int isPrime(int n, int i) {
    if (i == 1)
        return 1;
    else {
        if (n % i == 0)
            return 0;
        else
            return isPrime(n, i - 1);
    }
}

