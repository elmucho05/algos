#include <iostream>
using namespace std;

typedef struct node{
    int val;
    struct node* parent;
    struct node* left = nullptr;
    struct node* right = nullptr;
}albero; 

node* new_albero(){
    return nullptr;
}

bool is_empty_tree(node* t){
    if(t==nullptr || (t->left == nullptr && t->right == nullptr))
        return true;
    else
        return false;
}

node* new_node(int x){
    node* n = new node;
    n->val= x;
    n->parent = nullptr;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

void insert_left(node*& t, node* e){
    if(t != nullptr ){ 
        t->left = e;
    }else
        cout << "Error inserting into tree";
}

void insert_right(node*& t, node* e){
    if( t != nullptr)
        t->right = e;
    else
        cout << "errore nell'inserire a destra";
}

int main(){
    node* t = new_albero();
    t = new_node(0);
    
    node* n1 = new_node(1);
    node* n2 = new_node(2);
    
    insert_left(t, n1);
    insert_right(t, n2);
    
    cout << t->left->val << " " << t->right->val;
    return 0;
}