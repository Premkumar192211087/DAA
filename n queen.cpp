#include <stdio.h>

#define N 4

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%2d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

int isSafe(int board[N][N], int row, int col) {
    // Check for queens in the same row
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    // Check for queens in the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    // Check for queens in the lower left diagonal
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

int solveNQueensUtil(int board[N][N], int col) {
    if (col == N) {
        printSolution(board);
        return 1;
    }

    int res = 0;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            res += solveNQueensUtil(board, col + 1);
            board[i][col] = 0;
        }
    }

    return res;
}

void solveNQueens() {
    int board[N][N] = {0};

    int solutions = solveNQueensUtil(board, 0);

    if (solutions == 0) {
        printf("No solution exists for %d-Queens problem.\n", N);
    } else {
        printf("Number of solutions for %d-Queens problem: %d\n", N, solutions);
    }
}

int main() {
    solveNQueens();
    return 0;
}
