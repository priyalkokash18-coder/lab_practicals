#include<stdio.h>
#include<stdbool.h>
int* search(int arr[], int size, int target) {
    if (arr == NULL || size <= 0) {
        printf("Array is empty!\n");
        return NULL;
    }
    int beg = 0, end = size - 1;
    while (beg <= end) {
        int mid = (beg + end) / 2;
        printf("\nSearching between indexes [%d : %d]\n", beg, end);
        printf("Elements in this range: ");
        for (int i = beg; i <= end; i++) {
            if (i == mid)
                printf("[%d] ", arr[i]);
            else
                printf("%d ", arr[i]);
        }
        printf("\n");
        if (arr[mid] == target) {
            printf("Midpoint value %d matches target %d\n", arr[mid], target);
            return &arr[mid]; // return address if found
        } 
        else if (arr[mid] < target) {
            printf("Target %d is greater than midpoint %d â†’ Searching right side\n", target, arr[mid]);
            beg = mid + 1;
        } 
        else {
            printf("Target %d is less than midpoint %d â†’ Searching left side\n", target, arr[mid]);
            end = mid - 1;
        }
    }
    return NULL;
}
int main() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    if (size <= 0) {
        printf("Invalid or empty array!\n");
        return 0;
    }
    int arr[size];
    printf("Enter %d sorted elements:\n", size);
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    int target;
    printf("Enter search value: ");
    scanf("%d", &target);
    int *result = search(arr, size, target);
    if (result != NULL)
        printf("\n%d found in array!\n", target);
    else
        printf("\n%d not found in array.\n", target);
    return 0;
}
