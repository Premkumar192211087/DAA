#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100
void printSubset(int subset[], int size) {
    printf("Subset: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");
}
void findSubsets(int set[], int subset[], int n, int sum, int index, int subsetSize, int targetSum) {
    if (sum == targetSum) {
        printSubset(subset, subsetSize);
        return;
    }

    if (index == n || sum > targetSum) {
        return;
    }
    subset[subsetSize] = set[index];
    findSubsets(set, subset, n, sum + set[index], index + 1, subsetSize + 1, targetSum);

    findSubsets(set, subset, n, sum, index + 1, subsetSize, targetSum);
}
void subsetSum(int set[], int n, int targetSum) {
    int subset[MAX_SIZE];
    findSubsets(set, subset, n, 0, 0, 0, targetSum);
}

int main() {
    int n, targetSum;
    int set[MAX_SIZE];

    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    subsetSum(set, n, targetSum);

    return 0;
}
