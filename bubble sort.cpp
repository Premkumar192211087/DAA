#include <stdio.h>

int main() {
	int n;
    int arr[n];
    n = sizeof(arr) / sizeof(arr[0]);
    int i, j, temp;
    printf("enter the elements:");
    for(i=0;i<=n;i++)
scanf("%d",&arr[i]);
    printf("Array before sorting: \n");
    for (i = 0; i <n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++)
		 {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Array after sorting: \n");
    for (i = 0; i <n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

