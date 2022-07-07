//PREORDER TRAVERSAL


#include<iostream>
using namespace std;

class node {
    public: 
    int data;
     node * left; 
     node * right;
     node (int d){
         data =d;
         left=NULL;
         right=NULL;
     }
};
void print(node * root){
    if(root==NULL){
        return;
    }
    cout<<root->data;
    print(root->left);
    print(root->right);
}
node *  buildTree(){
    int in;
        cin>>in;
        if(in==-1){
            return NULL;
        }
     node * root = new node(in);
        root->left= buildTree() ;
        root->right= buildTree() ;
        return root;
}

int main(){
       node * root=
        buildTree() ;
       print(root);

}