#include <stdio.h>

#define MAX 20

int visited[MAX] = {0};

void dfs(int graph[MAX][MAX], int n, int node, int isChar) {
    // Print node
    if (isChar)
        printf("%c ", node + 'A');
    else
        printf("%d ", node);

    visited[node] = 1;

    // Visit adjacent nodes
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && visited[i] == 0) {
            dfs(graph, n, i, isChar);
        }
    }
}

int main() {
    int n, graph[MAX][MAX], start, isChar;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter 1 for character (A,B,...) or 0 for numeric: ");
    scanf("%d", &isChar);

    if (isChar) {
        char ch;
        printf("Enter starting vertex (A,B,...): ");
        scanf(" %c", &ch);
        start = ch - 'A';
    } else {
        printf("Enter starting vertex (0,1,...): ");
        scanf("%d", &start);
    }

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("DFS Traversal: ");
    dfs(graph, n, start, isChar);

    return 0;
}