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


int main(){
    tree* t =  new tree;
    t->root = nullptr;

    queue* q = new_queue();

    node* n1 = new_node(1);
    node* n2 = new_node(2);
    node* n3 = new_node(3);

    enqueue(q, n1);
    enqueue(q, n2);

    while(!is_empty_queue(q)){
        node* current_node = dequeue(q);
        cout << current_node->key << " "; 
    }



    return 0;
}