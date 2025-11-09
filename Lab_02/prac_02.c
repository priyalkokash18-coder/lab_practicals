#include <stdio.h>
#define MAX 5
int stack[MAX];
int top = -1;
void push() {
    int val;
    if (top == MAX - 1)
        printf("Stack Overflow!\n");
    else {
        printf("Enter element to push: ");
        scanf("%d", &val);
        stack[++top] = val;
        printf("%d pushed onto stack.\n", val);
    }
}
void pop() {
    if (top == -1)
        printf("Stack Underflow!\n");
    else
        printf("Popped element: %d\n", stack[top--]);
}
void display() {
    if (top == -1)
        printf("Stack is empty.\n");
    else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}
void checkPalindrome() {
    int i, flag = 1;
    for (i = 0; i <= top / 2; i++) {
        if (stack[i] != stack[top - i]) {
            flag = 0;
            break;
        }
    }
    if (flag)
        printf("Stack elements form a Palindrome.\n");
    else
        printf("Stack elements do NOT form a Palindrome.\n");
}
int main() {
    int choice;
    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Check Palindrome\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1: push(); break;
        case 2: pop(); break;
        case 3: display(); break;
        case 4: checkPalindrome(); break;
        case 5: return 0;
        default: printf("Invalid choice!\n");
        }
    }
}
