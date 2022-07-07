// Preorder is root left right
// inorder is left root right
// postorder is left right root;
// levelorder is bfs
// printKthLevel is also used...
#include <iostream>
#include <queue>
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
void printPre(node * root){
    if(root==NULL){
        return;
    }
    cout<<root->data<< " ";
    printPre(root->left);
    printPre(root->right);
}
void printIn(node * root){
    if(root==NULL){
        return;
    }
    printIn(root->left);
     cout<<root->data <<" ";
    printIn(root->right);
}
void printPost(node * root){
    if(root==NULL){
        return;
    }
    printPost(root->left);
    printPost(root->right);
        cout<<root->data<<" ";

}

void printLevel(node * root, queue<node* > q){
    
    if(q.empty()){
        cout<<"empty";
        return;

    }
    root=q.front();
    cout<<root->data<<" ";
    if(root->left!=NULL)
    {q.push(root->left);
    //cout<<"LEft pushed << "<<root->left->data;
    }
     if(root->right!=NULL)
     q.push( root->right);
    q.pop();
    printLevel(root,q);

}

int height(node * root){
    if(root==NULL){
        return 0;
    }
    int lsubtree=height(root->left);
    int rsubtree=height(root->right);
    return max(lsubtree,rsubtree)+1;
}

void printKthlevel(node * root, int k){
    if(root==NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" " ;
        return;
    }
    printKthlevel(root->left,k-1);
    printKthlevel(root->right,k-1);
    return;
}

void printALLlevels(node * root){
    int h=height(root);
    for(int i=0;i<=h;i++){
    printKthlevel(root,i);
    }
    
    return;
}

int main(){
 node * root= buildTree();
 cout<<"PRE ";
 printPre(root);
 cout<<"IN ";
 printIn(root);
 cout<<"Post ";
 printPost(root);
 cout<<"\nLevel Order ";
 queue<node *> q ;
 q.push(root);
 printLevel(root,q);
 cout<<"Height "<<height(root);
 cout<<"\nCB way of O(N^2) Level order ";printALLlevels(root);
}
