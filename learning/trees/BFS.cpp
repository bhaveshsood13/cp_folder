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

void bfs( node * root){
    queue <node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        if(q.front()==NULL){
            cout<<"\n";
            q.pop();
            if(!q.empty()){
                   q.push(NULL);
            }
        }
        else{
            node *f =q.front();
            cout<<f->data<<",";
            q.pop();
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}


int main(){
 node * root= buildTree();
    bfs(root);
}