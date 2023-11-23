#include <iostream>
using namespace std;


struct node{
    int val;
    struct node* next;
};

struct lista{
    struct node* head;
};

node* new_node(int x){
    node* e = new node;
    e->val = x;
    e->next = nullptr;
    return e;
}
node* new_list(){
    return nullptr;
}

void insert_head(lista* l, node* e){
    e->next = l->head;
    l->head = e;
}

//insert e after p
void insert_next(node* p, node* e){
    e->next = p->next;
    p->next = e;
}

void delete_list(lista* l) {
    node* current = l->head;
    while (current != nullptr) {
        node* next = current->next;
        delete current;
        current = next;
    }
    l->head = nullptr;  // Set the head to nullptr after deleting all nodes
}


void delete_graph(lista* G[], int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        delete_list(G[i]);
    }
}
void dfs_visit(lista* G[], bool* visited, int v) {
    visited[v] = true;
    cout << v << " ";
    node* current = G[v]->head;
    while (current != nullptr) {
        int neighbour = current->val;
        if (!visited[neighbour]) {
            dfs_visit(G, visited, neighbour);
        }
        current = current->next;
    }
}

void dfs(lista* G[], bool* visited, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i])
            dfs_visit(G, visited, i);
    }
}
int main(){

    node* n1 = new_node(1);
    node* n2 = new_node(2);
    node* n3 = new_node(3);
    node* n4 = new_node(4);

    lista* l1 = new lista;
    insert_head(l1, n1);
    insert_next(l1->head, n2);
    insert_next(l1->head->next, n3);

    lista* l2 = new lista;
    insert_head(l2, n4);

    lista* l3 = new lista;
    insert_head(l3, n2);

    lista* l4 = new lista;
    insert_head(l4, n2);
    insert_next(l4->head, n3);

    lista* G[] = {l1, l2, l3, l4};
    bool* visited = new bool[4]{false, false, false, false};
    dfs(G, visited, 4);
    ///delete_graph(G, 4);

    delete[] visited;
    return 0;
}