#include "graph.cpp"
#include <iostream>
using namespace std;

/*
Input: Graph
Output: is the graph connected?

A graph to be connected, a dfs visit, is supposed to visit 
every node of the graph.
*/

void dfs_visit(Graph* graph, int startVertex) {
    graph->visited[startVertex] = true;

    Node* neighbour = graph->adjacencyList[startVertex];
    while (neighbour != nullptr) {
        if (!graph->visited[neighbour->vertex - 'A']) {
            dfs_visit(graph, neighbour->vertex - 'A');
        }

        neighbour = neighbour->next;
    }
}
bool is_connected(Graph* graph, char startVertex){
    for(int i=0; i<MAX_VERTICES; i++){  
        graph->visited[i] = false;
    }

    int startIndex = startVertex - 'A';
    dfs_visit(graph, startIndex);

    for(int i=0; i<MAX_VERTICES; i++){
        if(!graph->visited[i])
            return false;
    }

    return true;
}


void printGraph(struct Graph* graph) {
    for (int i = 0; i < MAX_VERTICES; ++i) {
        printf("%c: ", 'A' + i);
        struct Node* current = graph->adjacencyList[i];
        while (current != NULL) {
            printf("%c ", current->vertex);
            current = current->next;
        }
        printf("\n");
    }
}
int main(){

    struct Graph* myGraph = createGraph();

    // Add vertices
    // addEdge(myGraph, 'A', 'B');
    // addEdge(myGraph, 'B', 'C');
    // addEdge(myGraph, 'C', 'D');
    // addEdge(myGraph, 'D', 'A');

    addEdge(myGraph, 'A', 'B');
    addEdge(myGraph, 'B', 'C');
    addEdge(myGraph, 'C', 'D');
    addEdge(myGraph, 'D', 'E'); 

    if(is_connected(myGraph, 'A'))
        cout << "Graph is connected";
    else
        cout << "Not connected";
    return 0;
}