#include <stdio.h>
int main() {
    int arr[10],i ;
    printf("enter the elments:");
    for(i=0;i<=10;i++)
	scanf("%d",&arr[i]);
    
    int size = sizeof(arr) / sizeof(arr[0]); 
    int largest = arr[0];
    for ( i = 1; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    printf("The largest element in the array is: %d\n", largest);

    return 0;
}
