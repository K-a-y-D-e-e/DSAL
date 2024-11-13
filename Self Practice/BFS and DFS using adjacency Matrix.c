#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

// Graph represented as an adjacency matrix
int graph[MAX][MAX];
int visited[MAX];

// Function to implement Breadth First Search (BFS)
void BFS(int start, int vertices) {
    int queue[MAX], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;  // Enqueue the starting node

    printf("Breadth First Search starting from vertex %d: ", start);
    
    while (front != rear) {
        int current = queue[front++];
        
        printf("%d ", current);
        
        // Check for all adjacent vertices of the current vertex
        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                queue[rear++] = i; // Enqueue the unvisited adjacent vertex
                visited[i] = 1;     // Mark it as visited
            }
        }
    }
    printf("\n");
}

// Function to implement Depth First Search (DFS)
void DFS(int start, int vertices) {
    visited[start] = 1;
    printf("%d ", start);
    
    // Visit all adjacent vertices recursively
    for (int i = 0; i < vertices; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            DFS(i, vertices);
        }
    }
}

// Function to reset the visited array for DFS/BFS
void resetVisited(int vertices) {
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }
}

// Main function
int main() {
    int vertices, edges, u, v, start, choice;

    // Input the number of vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize the adjacency matrix to 0
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    // Input the edges
    printf("Enter the edges (u v) where u and v are vertices (0-based index):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // Directed graph
        graph[v][u] = 1; // For undirected graph, we need to add the reverse edge
    }

    // Menu-driven program
    do {
        printf("\nMenu:\n");
        printf("1. BFS Traversal\n");
        printf("2. DFS Traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // BFS
                resetVisited(vertices);
                printf("Enter the starting vertex for BFS: ");
                scanf("%d", &start);
                BFS(start, vertices);
                break;
                
            case 2:
                // DFS
                resetVisited(vertices);
                printf("Enter the starting vertex for DFS: ");
                scanf("%d", &start);
                printf("Depth First Search starting from vertex %d: ", start);
                DFS(start, vertices);
                printf("\n");
                break;
                
            case 3:
                printf("Exiting program.\n");
                break;
                
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}
