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

//return the pointer to the node in position i, otherwise nullptr
node* search(node*& l, int i){
    int j=0;
    node* tmp = l;
    
    while(j<i && tmp!=nullptr){
        tmp = tmp->next;
        j++;
    }

    return tmp;
}

//insert node e in position i
void insert_pos(node*& l, node* e, int i){
    node* correct_node = search(l, i);
    if(correct_node!=nullptr)
        insert_next(correct_node, e);
}

//delete 'e' from the list
void delete_node(node*& l, node* e){
    if(l == e)
        l = l->next;
    else{
        node* tmp = l;
        while(tmp!=nullptr && tmp->next!=e){
            tmp = tmp->next;
        }
        //if tmp, hasn't reached the end of the list, i have found the node
        if(tmp->next!=nullptr)
            tmp->next = e->next;
    }
}


int main(){

    node* mylist = new_list();
    cout <<"La lista e' vuota True 1, False 0 >> " << empty_list(mylist) << endl;
    node* mynode1 = new_node(1);
    insert_head(mylist, mynode1);
    cout <<"La lista e' vuota True 1, False 0 >> " << empty_list(mylist) << endl;
    
    node* mynode2 = new_node(2);
    node* mynode3 = new_node(3);
    node* mynode4 = new_node(4);

    insert_next(mynode1, mynode2);
    insert_next(mynode2, mynode3);
    insert_next(mynode3, mynode4);
    cout << "Printing the conents of the list"<< endl;
    //if you don't create the current node, you simply lose the pointer to the list
    node* current = mylist;
    while(current!=nullptr){
        cout << current->val << " ";
        current = current->next;
    }
    node* searched_node = search(mylist, 2);

    cout << "\n\nSearching for element in pos 2, they start form 0 >>" << searched_node->val;
    cout << "\nInserting node 6, after node in pos 2 (should be 3) : \n";
    node* node6 = new_node(6);
    insert_pos(mylist, node6, 2);
    current = mylist;
    while(current!=nullptr){
        cout << current->val << " ";
        current = current->next;
    }
    cout << "\n\nDeleting node6 from the list\n";
    delete_node(mylist, search(mylist,3));
    cout << "\n\n";
    current = mylist;
    while(current!=nullptr){
        cout << current->val << " ";
        current = current->next;
    }
    cout << "\n";
    return 0;
   
}