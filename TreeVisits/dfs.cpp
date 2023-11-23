#include <iostream>
using namespace std;


struct node{
    int key;
    struct node* left;
    struct node* right;
};

struct tree{
    struct node* root;
};

node* new_node(int x){
    node* n = new node;
    n->key = x;
    n->left = n->right = nullptr;
    return n;
}

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

void dfs_pre_order(node* t){
    if(t != nullptr){
        cout << t->key << endl;
        dfs_pre_order(t->left);
        dfs_pre_order(t->right);
    }
}

int main(){
    tree* t = new tree;
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
/*
                0
        1                 2
3                   6            4
                            7         5

*/
    dfs_pre_order(t->root);
    return 0;
}