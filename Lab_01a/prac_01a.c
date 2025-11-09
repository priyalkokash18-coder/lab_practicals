#include <stdio.h>
int main() {
    int arr[100],sumeven=0,sumodd=0,n,i;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("enter the elements");
    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++) {
        if (i % 2 == 0)
            sumeven += arr[i];
        else
            sumodd += arr[i];
    }
    printf("Sum of numbers at even positions = %d\n", sumeven);
    printf("Sum of numbers at odd positions = %d\n", sumodd);
    return 0;
}
