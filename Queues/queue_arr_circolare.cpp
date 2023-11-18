#include <iostream>
using namespace std;

struct coda
{
    int *arr;
    int head; //front
    int current_elem; //rear
    int dim; //capacity
};

coda* new_queue(int dimensione){
    coda* c = new coda;
    c->dim = dimensione+1;
    c->arr = new int[dimensione];
    c->head = 0;
    c->current_elem = 0;

    return c;
}

bool is_empty_queue(coda* q){
    return (q->head == q->current_elem);
}

bool is_full(coda* q){
    return(q->current_elem+1)%q->dim == q->head;
}

int top(coda* c){
    if(!is_empty_queue(c))
        return c->arr[c->head];
}

void enqueue(coda*& q, int x){
    if(!is_full(q)){
        q->arr[q->current_elem] = x;
        q->current_elem = (q->current_elem+1)% q->dim;
    }
}

int dequeue(coda*& q){

    if (is_empty_queue(q)) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return -1;  // You can choose a different value to indicate an error condition
    }

    int value = q->arr[q->head];
    q->head = (q->head + 1) % q->dim;
    return value;
}

void destroyCircularQueue(coda* q) {
        delete[] q->arr;
        delete q;
}
int main() {
    coda* myQueue = new_queue(5);

    enqueue(myQueue, 1);
    enqueue(myQueue, 2);
    enqueue(myQueue, 3);

    cout << "Top element: " << top(myQueue) << endl;

    while (!is_empty_queue(myQueue)) {
        cout << "Dequeued: " << dequeue(myQueue) << endl;
    }
   
    destroyCircularQueue(myQueue);
    return 0;
}
