#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL; 
void createList() {
    int val;
    struct Node *newNode, *temp;
    printf("Enter numbers to add to the list (enter 0 to stop):\n");
    while (1) {
        scanf("%d", &val);
        if (val == 0)
            break;
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        if (head == NULL)  
            head = newNode;
        else {              
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}
void displayList() {
    struct Node *temp = head;
    int count = 0;

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("\nLinked List elements:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("NULL\n");
    printf("Total number of nodes = %d\n", count);
}
int main() {
    createList();
    displayList();
    return 0;
}
