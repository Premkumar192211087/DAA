#include <stdio.h>
#include <time.h>
#define MAX_SIZE 10
void multiplyMatrices(int firstMatrix[MAX_SIZE][MAX_SIZE], int secondMatrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowFirst, int colFirst, int rowSecond, int colSecond) {
 int i,j,k;
    for (i = 0; i < rowFirst; ++i) {
        for (j = 0; j < colSecond; ++j) {
            result[i][j] = 0;
        }
    }

    for (i = 0; i < rowFirst; ++i) {
        for (j = 0; j < colSecond; ++j) {
            for (k = 0; k < colFirst; ++k) {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

int main() {
    int rowFirst, colFirst, rowSecond, colSecond;

    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &rowFirst, &colFirst);

    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &rowSecond, &colSecond);
    if (colFirst != rowSecond) {
        printf("Matrices cannot be multiplied.\n");
        return 0;
    }

    int firstMatrix[MAX_SIZE][MAX_SIZE], secondMatrix[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

    printf("\nEnter elements of matrix 1:\n");
    int i,j,k;
    for (i = 0; i < rowFirst; ++i) {
        for (j = 0; j < colFirst; ++j) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &firstMatrix[i][j]);
        }
    }

    printf("\nEnter elements of matrix 2:\n");
    for (i = 0; i < rowSecond; ++i) {
        for (j = 0; j < colSecond; ++j) {
            printf("Enter element b%d%d: ", i + 1, j + 1);
            scanf("%d", &secondMatrix[i][j]);
        }
    }
    clock_t start_time = clock();

    multiplyMatrices(firstMatrix, secondMatrix, result, rowFirst, colFirst, rowSecond, colSecond);

    clock_t end_time = clock();
    double time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("\nProduct of matrices:\n");
    for (i = 0; i < rowFirst; ++i) {
        for (j = 0; j < colSecond; ++j) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }

    printf("\nTime taken: %f seconds\n", time_taken);

    return 0;
}
