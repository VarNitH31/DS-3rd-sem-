#include <stdio.h>

#define MAX_NODES 100

int visited[MAX_NODES];
int adj_matrix[MAX_NODES][MAX_NODES];
int num_nodes;

void dfs(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < num_nodes; i++) {
        if (adj_matrix[vertex][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }

    for (int i = 0; i < num_nodes; i++) {
        visited[i] = 0;
    }

    printf("DFS Traversal: ");
    for (int i = 0; i < num_nodes; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    printf("\n");

    return 0;
}
