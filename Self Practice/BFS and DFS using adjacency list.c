#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a node of the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Graph structure to hold the adjacency list
struct Graph {
    int vertices;
    struct Node** adjList;
};

// Function to create a new adjacency list node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with 'vertices' number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    // Create an array of adjacency lists
    graph->adjList = (struct Node**)malloc(vertices * sizeof(struct Node*));

    // Initialize each adjacency list as NULL
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph (directed graph)
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // For undirected graph, also add an edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to implement Breadth First Search (BFS)
void BFS(struct Graph* graph, int start) {
    bool* visited = (bool*)malloc(graph->vertices * sizeof(bool));

    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = false;
    }

    // Create a queue for BFS
    int queue[graph->vertices], front = 0, rear = 0;
    
    // Enqueue the start vertex and mark it as visited
    visited[start] = true;
    queue[rear++] = start;

    printf("Breadth First Search starting from vertex %d: ", start);

    while (front != rear) {
        int current = queue[front++];
        printf("%d ", current);

        struct Node* temp = graph->adjList[current];
        while (temp) {
            if (!visited[temp->data]) {
                visited[temp->data] = true;
                queue[rear++] = temp->data;
            }
            temp = temp->next;
        }
    }
    printf("\n");
    free(visited);
}

// Function to implement Depth First Search (DFS)
void DFS(struct Graph* graph, int start) {
    bool* visited = (bool*)malloc(graph->vertices * sizeof(bool));

    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = false;
    }

    printf("Depth First Search starting from vertex %d: ", start);
    DFSUtil(graph, start, visited);
    printf("\n");
    free(visited);
}

// Helper function for DFS
void DFSUtil(struct Graph* graph, int vertex, bool* visited) {
    visited[vertex] = true;
    printf("%d ", vertex);

    struct Node* temp = graph->adjList[vertex];
    while (temp) {
        if (!visited[temp->data]) {
            DFSUtil(graph, temp->data, visited);
        }
        temp = temp->next;
    }
}

// Main function
int main() {
    int vertices, edges, u, v, start, choice;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    struct Graph* graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (u v) where u and v are vertices (0-based index):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
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
                printf("Enter the starting vertex for BFS: ");
                scanf("%d", &start);
                BFS(graph, start);
                break;

            case 2:
                // DFS
                printf("Enter the starting vertex for DFS: ");
                scanf("%d", &start);
                DFS(graph, start);
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 3);

    // Free the memory for graph
    for (int i = 0; i < vertices; i++) {
        struct Node* temp = graph->adjList[i];
        while (temp) {
            struct Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(graph->adjList);
    free(graph);

    return 0;
}
