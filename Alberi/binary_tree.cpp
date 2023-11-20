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
        e->parent = t;
    }else
        cout << "Error inserting into tree";
}

void insert_right(node*& t, node* e){
    if( t != nullptr){
        t->right = e;
        e->parent = t;
    }
    else
        cout << "errore nell'inserire a destra";
}

int conta_nodi(node* t){
    if(t == nullptr)
        return 0;
    else{
        int left=conta_nodi(t->left);
        int right=conta_nodi(t->right);
        cout<<"\nval=" << t->val;
        cout <<"left="<< left <<",right="<< right << endl;

        return (1+left+right); 
    }
}

int altezza_albero(node*t ){
    // if(t == nullptr)
    //     return 0;
    // else{
    //     int left_height = altezza_albero(t->left);
    //     int right_height = altezza_albero(t->right);
    //     //cout << left_height << " " << right_height;

    //     return max(left_height,right_height) +1;
    // }
    //----alternative---//
    // if(t->left == nullptr && t->right == nullptr)
    //     return 0;
    // if(t->left==nullptr)
    //     return 1+altezza_albero(t->right);
    // if(t->right == nullptr)
    //     return 1+altezza_albero(t->left);
    
    // return (1+max(altezza_albero(t->left),altezza_albero(t->right)));
    //------alternative---//
    if(t==nullptr)
        return -1;
    else{
        //return (1+max(altezza_albero(t->left), altezza_albero(t->right)));
        int left = altezza_albero(t->left);
        int right  = altezza_albero(t->right);
        cout << "\nval="<<t->val;
        cout << "left=" << left << ",right=" << right;
        return 1+max(left,right);
    }

}

void dfs(node* &t){
    if(t!= nullptr){
        dfs(t->left);
        cout << endl << t->val ;
        dfs(t->right);
    }
}

int main(){
    node* t = new_albero();
    t = new_node(0);
    
    node* n1 = new_node(1);
    node* n2 = new_node(2);
    node* n3 = new_node(3);

    insert_left(t, n1);
    insert_right(t, n2);
    /*
            0
    1               2
             
                3
            4

                            height = 3
    */

    insert_left(n2, n3);
    insert_left(n3, new_node(4));
    
    // cout << t->left->val << " " << t->right->val;
    // cout << " " << t->left->left->val << " poi " << t->left->left->left->val ;
    cout << "contanodi = "<< conta_nodi(t);
    cout << "\naltezza_albero = " << altezza_albero(t);
    dfs(t);
    cout << endl;
    return 0;
}