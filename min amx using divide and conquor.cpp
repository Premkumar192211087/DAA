#include <stdio.h>

// Function to find maximum and minimum values using Divide and Conquer
void findMaxMin(int arr[], int low, int high, int *max, int *min) {
    int mid, max1, min1, max2, min2;

    // If there is only one element
    if (low == high) {
        *max = arr[low];
        *min = arr[low];
        return;
    }

    // If there are two elements
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            *max = arr[low];
            *min = arr[high];
        } else {
            *max = arr[high];
            *min = arr[low];
        }
        return;
    }

    // If there are more than two elements
    mid = (low + high) / 2;
    findMaxMin(arr, low, mid, &max1, &min1);
    findMaxMin(arr, mid + 1, high, &max2, &min2);

    // Compare minimums of two parts
    if (min1 < min2)
        *min = min1;
    else
        *min = min2;

    // Compare maximums of two parts
    if (max1 > max2)
        *max = max1;
    else
        *max = max2;
}

int main() {
    int arr[100], n, i, max, min;

    // Input the size of the array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input the elements of the array
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Find maximum and minimum
    findMaxMin(arr, 0, n - 1, &max, &min);

    // Print the maximum and minimum
    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

    return 0;
}
