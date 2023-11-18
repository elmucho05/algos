#include <iostream>
using namespace std;

typedef struct node{
    int val;
    struct node* next;
}node;

typedef struct queue
{
    struct node* head;
    struct node* tail;
}queue;


queue* new_queue(){
    queue* q = new queue;
    q->head = nullptr;
    q->tail = nullptr;
    return q;
}

bool is_empty_queue(queue* q){
    return (q->head==nullptr);
}

void enqueue(queue*& q, int x){
    node* e = new node;
    e->val = x;
    e->next = nullptr;

    if(q->head == nullptr){
        q->head = e;
    }else
        q->tail->next = e; //if there is already an element on the queue

    q->tail = e;
}

int first(queue*& q){
    if(q->head!=nullptr)
        return q->head->val;
    else
        return -1;
}

int dequeue(queue*& q){
    int to_return;    
    if(q->head != nullptr){
        to_return = first(q);
        q->head = q->head->next;

        //if by moving the pointer by 1, is now the queue empty?
        if(q->head == nullptr)
            q->tail = nullptr;
        
        return to_return;
    }else
        return -1;
}