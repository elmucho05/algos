#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

struct Node {
    char vertex;
    struct Node* next;
};

struct Graph {
    struct Node* adjacencyList[MAX_VERTICES];
    bool visited[MAX_VERTICES];
};

struct Graph* createGraph() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    for (int i = 0; i < MAX_VERTICES; ++i) {
        graph->adjacencyList[i] = NULL;
        graph->visited[i] = false;
    }
    return graph;
}

struct Node* createNode(char vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Graph* graph, char vertex1, char vertex2) {
    // Assuming an undirected graph     A               B
    struct Node* newNode = createNode(vertex2); //B
    newNode->next = graph->adjacencyList[vertex1]; //b.next = graph
    graph->adjacencyList[vertex1] = newNode;//insert_next
    //i just inserted node B into the adjacency list of the node A
    //insert in head, then head points to newNode
    
    //same thing, add nodeA in the list of adjacent nodes of nodeB
    newNode = createNode(vertex1);
    newNode->next = graph->adjacencyList[vertex2];
    graph->adjacencyList[vertex2] = newNode;
}

// void dfsVisit(struct Graph* graph, char currentVertex) {
//     printf("%c\n", currentVertex);
//     graph->visited[currentVertex] = true;

//     struct Node* neighbor = graph->adjacencyList[currentVertex];
//     while (neighbor != NULL) {
//         if (!graph->visited[neighbor->vertex]) {
//             dfsVisit(graph, neighbor->vertex);
//         }
//         neighbor = neighbor->next;
//     }
// }

// void dfs(struct Graph* graph, char startVertex) {
//     for (int i = 0; i < MAX_VERTICES; ++i) {
//         graph->visited[i] = false;
//     }

//     dfsVisit(graph, startVertex);
// }

// int main() {
//     struct Graph* myGraph = createGraph();

//     // Add vertices
//     addEdge(myGraph, 'A', 'B');
//     addEdge(myGraph, 'B', 'C');
//     addEdge(myGraph, 'C', 'D');
//     addEdge(myGraph, 'D', 'A');

//     // Perform DFS starting from vertex 'A'
//     printf("Depth-First Search:\n");
//     dfs(myGraph, 'A');

//     return 0;
// }
