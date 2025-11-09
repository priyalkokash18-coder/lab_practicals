#include <stdio.h>
#define MAX 10
int queue[MAX], front = -1, rear = -1;
int stack[MAX], top = -1;
void enqueue(int value) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = value;
}
int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}
void push(int value) {
    stack[++top] = value;
}
int pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}
void BFS(int adj[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    enqueue(start);
    visited[start] = 1;

    printf("\nBFS Traversal: ");
    while (front <= rear) {
        int node = dequeue();
        printf("%d ", node);
        for (int i = 1; i <= n; i++) {
            if (adj[node][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}
void DFS(int adj[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    push(start);

    printf("\nDFS Traversal: ");
    while (top != -1) {
        int node = pop();
        if (!visited[node]) {
            printf("%d ", node);
            visited[node] = 1;
        }
        for (int i = n; i >= 1; i--) {
            if (adj[node][i] && !visited[i])
                push(i);
        }
    }
    printf("\n");
}
int main() {
    int n, adj[MAX][MAX], start;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            scanf("%d", &adj[i][j]);
    }

    printf("Enter starting node: ");
    scanf("%d", &start);

    BFS(adj, n, start);
    DFS(adj, n, start);

    return 0;
}
