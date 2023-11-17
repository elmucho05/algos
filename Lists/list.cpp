#include <iostream>
using namespace std;


struct node{
    int val;
    struct node* next;
};

node* new_node(int val){
    node* nodo = new node;
    nodo->next = nullptr;
    nodo->val = val;
    return nodo;
}

node* new_list(){
    return nullptr;
}

bool empty_list(node* l){
    return (l == nullptr);
}
//theoretically structs are passed by reference but just i case
void insert_head(node*& l, node* e) {
    e->next = l;
    l = e;
}

//insert e after p
void insert_next(node* p, node* e){
    e->next = p->next;
    p->next = e;
}

int main(){

    node* mylist = new_list();
    cout <<"La lista e' vuota True 1, False 0 >> " << empty_list(mylist) << endl;
    node* mynode1 = new_node(1);
    insert_head(mylist, mynode1);
    cout <<"La lista e' vuota True 1, False 0 >> " << empty_list(mylist) << endl;
    
    node* mynode2 = new_node(2);
    node* mynode3 = new_node(3);
    insert_next(mynode1, mynode2);
    cout << "Printing the conents of the list"<< endl;
    //if you don't create the current node, you simply lose the pointer to the list
    node* current = mylist;
    while(current!=nullptr){
        cout << current->val << " ";
        current = current->next;
    }
    
    cout << "\n";
    return 0;
   
}