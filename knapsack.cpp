#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct Item {
    int value;
    int weight;
};

// Comparison function to sort items by value-to-weight ratio
int compare(const void *a, const void *b) {
    double ratioA = (double)(((struct Item *)a)->value) / ((struct Item *)a)->weight;
    double ratioB = (double)(((struct Item *)b)->value) / ((struct Item *)b)->weight;
    if (ratioA < ratioB)
        return 1;
    else if (ratioA > ratioB)
        return -1;
    else
        return 0;
}

// Function to solve fractional knapsack problem using greedy algorithm
double knapsack(struct Item items[], int n, int capacity) {
    // Sort items by their value-to-weight ratio in non-increasing order
    qsort(items, n, sizeof(struct Item), compare);
    
    double totalValue = 0.0;
    
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            // Take the whole item
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take a fraction of the item to fill the knapsack
            double fraction = (double)capacity / items[i].weight;
            totalValue += items[i].value * fraction;
            break; // Knapsack is full
        }
    }
    
    return totalValue;
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    double maxValue = knapsack(items, n, capacity);
    printf("Maximum value that can be obtained: %.2lf\n", maxValue);

    return 0;
}
