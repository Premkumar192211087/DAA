#include <stdio.h>

// Function to perform standard matrix multiplication
void standardMatrixMultiplication(int n, int A[][], int B[][n], int C[][n]) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = 0;
            for (k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to add two matrices
void addMatrix(int n, int A[][n], int B[][n], int C[][n]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrix(int n, int A[][n], int B[][n], int C[][n]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to perform Strassen's matrix multiplication
void strassenMatrixMultiplication(int n, int A[][n], int B[][n], int C[][n]) {
    if (n <= 64) { // Base case for standard multiplication
        standardMatrixMultiplication(n, A, B, C);
        return;
    }

    // Initializing submatrices
    int size = n / 2;
    int A11[size][size], A12[size][size], A21[size][size], A22[size][size];
    int B11[size][size], B12[size][size], B21[size][size], B22[size][size];
    int C11[size][size], C12[size][size], C21[size][size], C22[size][size];
    int P1[size][size], P2[size][size], P3[size][size], P4[size][size], P5[size][size], P6[size][size], P7[size][size];
    int temp1[size][size], temp2[size][size];

    int i, j;

    // Dividing matrices A and B into submatrices
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + size];
            A21[i][j] = A[i + size][j];
            A22[i][j] = A[i + size][j + size];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + size];
            B21[i][j] = B[i + size][j];
            B22[i][j] = B[i + size][j + size];
        }
    }

    // Calculating seven products recursively
    subtractMatrix(size, B12, B22, temp1);
    strassenMatrixMultiplication(size, A11, temp1, P1);

    addMatrix(size, A11, A12, temp1);
    strassenMatrixMultiplication(size, temp1, B22, P2);

    addMatrix(size, A21, A22, temp1);
    strassenMatrixMultiplication(size, temp1, B11, P3);

    subtractMatrix(size, B21, B11, temp1);
    strassenMatrixMultiplication(size, A22, temp1, P4);

    addMatrix(size, A11, A22, temp1);
    addMatrix(size, B11, B22, temp2);
    strassenMatrixMultiplication(size, temp1, temp2, P5);

    subtractMatrix(size, A12, A22, temp1);
    addMatrix(size, B21, B22, temp2);
    strassenMatrixMultiplication(size, temp1, temp2, P6);

    subtractMatrix(size, A11, A21, temp1);
    addMatrix(size, B11, B12, temp2);
    strassenMatrixMultiplication(size, temp1, temp2, P7);

    // Calculating C matrices
    addMatrix(size, P5, P4, temp1);
    subtractMatrix(size, temp1, P2, temp2);
    addMatrix(size, temp2, P6, C11);

    addMatrix(size, P1, P2, C12);

    addMatrix(size, P3, P4, C21);

    addMatrix(size, P5, P1, temp1);
    subtractMatrix(size, temp1, P3, temp2);
    subtractMatrix(size, temp2, P7, C22);

    // Combining C matrices
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            C[i][j] = C11[i][j];
            C[i][j + size] = C12[i][j];
            C[i + size][j] = C21[i][j];
            C[i + size][j + size] = C22[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(int n, int matrix[][n]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, i, j;
    printf("Enter the size of the matrices: ");
    scanf("%d", &n);

    int A[n][n], B[n][n], C[n][n];

    printf("Enter elements of matrix A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Performing Strassen's multiplication
    strassenMatrixMultiplication(n, A, B, C);

    printf("Resultant matrix C:\n");
    displayMatrix(n, C);

    return 0;
}

