#include <stdio.h>
#define MAX 10

int adj[10][10]; 
int visited[10];
int queue[MAX], front = -1, rear = -1;
int stack[MAX], top = -1;

void enqueue(int x) {
    if(rear == MAX - 1) return;
    if(front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if(front == -1 || front > rear) return -1;
    return queue[front++];
}

void push(int x) {
    if(top == MAX - 1) return;
    stack[++top] = x;
}

int pop() {
    if(top == -1) return -1;
    return stack[top--];
}

void createGraph() {
    int i;
    for(i = 1; i <= 9; i++) {
        if(i - 3 > 0) adj[i][i - 3] = 1; 
        if(i + 3 <= 9) adj[i][i + 3] = 1; 
        if(i % 3 != 1) adj[i][i - 1] = 1; 
        if(i % 3 != 0) adj[i][i + 1] = 1; 
    }
}

void BFS(int start) {
    for(int i = 1; i <= 9; i++) visited[i] = 0;
    front = rear = -1;
    enqueue(start);
    visited[start] = 1;
    printf("BFS Order: ");
    while(front <= rear) {
        int node = dequeue();
        printf("%d ", node);
        for(int j = 1; j <= 9; j++) {
            if(adj[node][j] && !visited[j]) {
                enqueue(j);
                visited[j] = 1;
            }
        }
    }
    printf("\n");
}

void DFS(int start) {
    for(int i = 1; i <= 9; i++) visited[i] = 0;
    top = -1;
    push(start);
    printf("DFS Order: ");
    while(top != -1) {
        int node = pop();
        if(!visited[node]) {
            printf("%d ", node);
            visited[node] = 1;
            for(int j = 9; j >= 1; j--) {
                if(adj[node][j] && !visited[j])
                    push(j);
            }
        }
    }
    printf("\n");
}

int main() {
    createGraph();
    printf("Undirected Graph: 3x3 Grid (Nodes 1 to 9)\n");
    BFS(1);
    DFS(1);
    return 0;
}