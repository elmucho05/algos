#include <iostream>
using namespace std;

typedef struct node{
    int key;
    struct node* left;
    struct node* right;
}node;

typedef struct tree{
    struct node* root;
}tree;


struct queue_node{
    struct node* data;
    struct queue_node* next;
};

struct queue
{
    struct queue_node* front;
    struct queue_node* rear;
};

queue* new_queue(){
    queue* q = new queue;
    q->front = nullptr;
    q->rear = nullptr;
    return q;
}

bool is_empty_queue(queue* q){
    return (q->front == nullptr);
}

void enqueue(queue* q, node* e){
    queue_node* n = new queue_node;
    n->data = e; //n.data is a node type
    n->next = nullptr;

    if(is_empty_queue(q)){
        q->front = q->rear = n;
    }else{
        q->rear->next = n; //insert n into the queue
        q->rear = n; //move the pointer to point to n
    }
}


node* dequeue(queue* q){
    if(is_empty_queue(q))
        return nullptr;

    queue_node* frontNode = q->front;
    q->front = q->front->next;
    if(q->front==nullptr)
        q->rear = nullptr; //now the queue is empty

    node* nodeToReturn = frontNode->data;
    delete frontNode;

    return nodeToReturn;
}

tree* new_tree(){
    return nullptr;
}

node* new_node(int x){
    node* n = new node;
    n->key = x;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}
/*
                0
            1       2
        3       6        4
                    1        5

*/

void insert_left(node* t, node* n){
    if(t == nullptr)
        cout << "error, everything nullptr";
    t->left = n;
}
void insert_right(node* t, node* n){
    if(t == nullptr)
        cout << "error";
    t->right = n;
}

void bfs(tree* t){
    if(t->root != nullptr){
        queue* q = new_queue();
        enqueue(q, t->root);
        while(!is_empty_queue(q)){
            node* e = dequeue(q);
            cout << e->key << " ";
            if(e->left != nullptr)
                enqueue(q, e->left);
            if(e->right != nullptr)
                enqueue(q, e->right);
        }
    }
}


int main(){
    tree* t =  new tree;
    t->root = new_node(0);
    node* n1 = new_node(1);
    node* n2 = new_node(2);
    node* n3 = new_node(3);
    node* n4 = new_node(4);
    node* n5 = new_node(5);
    node* n6 = new_node(6);
    node* n7 = new_node(7);

    insert_left(t->root, n1);
    insert_left(n1, n3);
    insert_right(t->root, n2);
    insert_left(n2, n6);
    insert_right(n2, n4);
    insert_left(n4, n7);
    insert_right(n4, n5);
    cout << "Printing elements of the queue: ";
    /*
                0
    1                    2
3                   6            4
                            7         5

bfs should print : 0 1 2 3 6 4 7 5
*/
    bfs(t);
    

    return 0;
}