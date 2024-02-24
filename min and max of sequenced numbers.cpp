#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    int list[n];

    printf("Enter the elements of the list: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &list[i]);

    printf("Minimum and maximum values for each sequence:\n");

    // Print minimum and maximum values for each sequence
    for (int i = 0; i < n - 2; i++) {
        int min = list[i], max = list[i];
        for (int j = i + 1; j <= i + 2; j++) {
            if (list[j] < min)
                min = list[j];
            if (list[j] > max)
                max = list[j];
        }
        printf("Sequence {%d, %d, %d}: Minimum = %d, Maximum = %d\n", list[i], list[i + 1], list[i + 2], min, max);
    }

    return 0;
}
