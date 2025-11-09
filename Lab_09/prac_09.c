#include <stdio.h>
#define SIZE 7
int main() {
    int table[SIZE], i, key, n, index;
    for (i = 0; i < SIZE; i++)
        table[i] = -1;
    printf("Enter number of keys: ");
    scanf("%d", &n);
    printf("Enter %d keys:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        index = key % SIZE;
        while (table[index] != -1)
            index = (index + 1) % SIZE;

        table[index] = key;
    }
    printf("\nFinal Hash Table:\n");
    for (i = 0; i < SIZE; i++)
        printf("Slot %d: %d\n", i, table[i]);
    return 0;
}
