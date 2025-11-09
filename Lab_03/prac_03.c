#include <stdio.h>
#define MAX 5
char queue[MAX];
int front = -1, rear = -1;
void insert() {
    char val;
    if (rear == MAX - 1)
        printf("Queue Overflow!\n");
    else {
        printf("Enter character to insert: ");
        scanf(" %c", &val);
        if (front == -1)
            front = 0;
        queue[++rear] = val;
        printf("%c inserted into queue.\n", val);
    }
}
void delete() {
    if (front == -1 || front > rear)
        printf("Queue Underflow!\n");
    else
        printf("Deleted element: %c\n", queue[front++]);
}
void display() {
    if (front == -1 || front > rear)
        printf("Queue is empty.\n");
    else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%c ", queue[i]);
        printf("\n");
    }
}
int main() {
    int choice;
    while (1) {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1: insert(); break;
        case 2: delete(); break;
        case 3: display(); break;
        case 4: return 0;
        default: printf("Invalid choice!\n");
        }
    }
}
