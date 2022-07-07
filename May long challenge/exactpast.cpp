#include <bits/stdc++.h>
using namespace std;
#define int long long
struct TreeNode
{
    int data,lvl;
    vector<TreeNode *> child;
    TreeNode(int x){
        data=x;
        lvl=0;
    }
};
void buildTree(TreeNode *root, vector<vector<int>> &adj , vector<bool> &visited){
    visited[root->data]=1;
    for (int i = 0; i < adj[root->data].size(); i++)
    {
        if(!visited[adj[root->data][i]]){
            TreeNode *temp= new TreeNode(adj[root->data][i]);
            root->child.push_back(temp);
        }
    }
    for (int i = 0; i < root->child.size(); i++)
    {
        buildTree(root->child[i],adj,visited);
    }
}
void DFS(TreeNode *root, int l){
    root->lvl=l;
    for (int i = 0; i < root->child.size(); i++)
    {
        TreeNode * cur= root->child[i];
        DFS(cur, l+1);
    }
    
}
vector<pair <int, int>> leaves;
void DFS2(TreeNode *root){
    for (int i = 0; i < root->child.size(); i++)
    {
        TreeNode * current=root->child[i];
        DFS2(current);
    }
    if(root->child.size()==0){
        leaves.push_back({root->lvl,root->data +1});
    }
    
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int >> adj(n);
    for (int i = 0; i < n-1; i++)
    {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    TreeNode * root= new TreeNode(0);
    vector<bool> visited(n,0);
    buildTree(root,adj, visited);
    DFS(root, 0);
    vector<pair<int, int>> ans;
    for (int  i = 0; i < root->child.size(); i++)
    {
        DFS2(root->child[i]);
        vector<pair<int,int>>v;
        pair <int,int> p;
        bool f=0;
        sort(leaves.begin(),leaves.end());
        p=leaves[0];
        v.push_back(p);
        int val=p.first;
        int j=1;
        while(j<leaves.size()){
            
                while (j < leaves.size() && leaves[j].first == val)
                {
                    if (f)
                        v.push_back({p.first + 1, leaves[j].second});
                    else
                        v.push_back(leaves[j]);
                    j++;
                }
                if (j < leaves.size())
                {
                    v.clear();
                    f = 1;
                    p.second = leaves[j].second;
                    v.push_back({p.first + 1, leaves[j].second});
                    val = leaves[j].first;
                    j++;
                }
        }
        leaves.clear();
        for(auto x: v){
            ans.push_back(x);
        }
    }
    sort(ans.begin(),ans.end());
    int day=ans[0].first;
    vector<int>AA;
    for (int i = 0; i < ans.size(); i++)
    {
        if(ans[i].first==day) AA.push_back(ans[i].second);
        else break;
    }
    cout<<AA.size()<<" "<< day<<"\n";
    for(auto x: AA){
        cout<<x<<" ";
    }
cout<<"\n";
    
    
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        solve();    }
}