#include <iostream>
using namespace std;

typedef struct node{
    int val;
    struct node* next;
}node;

node* new_list(){
    return nullptr;
}

node* new_stack(){
    return new_list();
}

bool is_empty_stack(node* s){
    return (s==nullptr);
}

int top(node* S){
    if(S!=nullptr)
        return S->val;
    else
        return -1;
}

void push(node*& S, int x){
    node* nodo = new node;
    nodo->val = x;
    nodo->next = S;
    S = nodo;

}

int pop(node*& S){
    int to_return;
    if(S!=nullptr){
        to_return = top(S);
        S = S->next;
        return to_return;
    }
    return -1;
}

int main(){
    node* pila = new_stack();
    cout << "Is empty_stack? >> " << is_empty_stack(pila);
    push(pila, 1);
    push(pila, 2);

    cout << "\nPrinting contents of the queue : \n";
    node* current = pila;
    while(current != nullptr){
        cout << current->val << " ";
        current = current->next;
    }
    
    cout << "\nPopping an element from the queue : \n";
    pop(pila);
    current = pila;
    while(current!=nullptr){
        cout << current->val << " ";
        current = current->next;
    }

    return 0;
}