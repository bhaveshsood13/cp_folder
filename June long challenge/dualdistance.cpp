/**
 * author: Bhavesh
**/

#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define cinarr(ar,n) for(int i=0;i<n;i++){cin>>ar[i];}
#define car(ar,n) for(int i =0;i<n;i++){cout<<ar[i]<<" ";}
#define forn(i,a,b) for (int i = (a); i < ll(b); ++i)
#define fo(i,a) forn(i,0,ll(a))
#define rforn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ro(i,a) rforn(i,0,a)
#define trav(a,x) for (auto& a: x)

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define sec second
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
const ll INF = 1e18;

void preprocessing(int src, int par,vi adj[],vl & subtreeAns, vl & subtrsize , vl & height,vl &lvl ,int l)
{
    int numOfNodes = 1;
    ll ansForSubtree = 0;
    int c=0;
    for(int child : adj[src])
    {
        if(child != par)
        {
            preprocessing(child, src,adj,subtreeAns,subtrsize,height,lvl,l+1);
            c=max(height[child]+1,c)
            numOfNodes += subtrsize[child];
            ansForSubtree += subtrsize[child] + subtreeAns[child];
        }
    }
    lvl[src]=l;
    subtrsize[src] = numOfNodes;
    subtreeAns[src] = ansForSubtree;
    height[src]=c;

}
 
 
 
void dfs2(int src, int par, ll par_ans, int& totalNodes,vi adj[],vl &  subtrsize, vl & subtreeAns,vl & dist)
{
    dist[src] = subtreeAns[src] + (par_ans + (totalNodes - subtrsize[src]));
 
    for(int child : adj[src])
    {
        if(child != par)
            dfs2(child, src, dist[src] - (subtreeAns[child] + subtrsize[child]), totalNodes,adj,subtrsize,subtreeAns,dist);
    }
}


int  l;


int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p,vi adj[])
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v,adj);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root,vi adj[],int n) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root,vi adj[]);
}













int main(){
    int t;
    cin>>t;
    while(t--){
      int n,q;
      cin>>n>>q;
      vi adj[n+1];
      for (int i = 0; i < n-1; i++)
      {
          int x,y;
          cin>>x>>y;
          adj[x].pb(y);
          adj[y].pb(x);
      }
      vl subtreeAns(n+1,0), subtrsize(n+1,0),dist(n+1,0),height(n+1,0),lvl(n+1,0);
     preprocessing(1, 0,adj,subtreeAns,subtrsize,height,lvl,1);
     dfs2(1, 0, 0, n,adj,subtrsize,subtreeAns,dist);
     preprocess(1,adj,n+1);

     while(q--){
         int u,v;
         cin>>u>>v;
         int nlca=lca(u,v);
         int lu=lvl[u],lv=lvl[v],llca=lvl[nlca];
         if(lv<lu){
             swap(u,v);
             swap(lu,lv);
         }
         //u is always above v .//lu < lv always;
         ll alldist=dist[nlca];
         for (auto ch : adj[nlca])
         {
            if(is_ancestor(ch,u) or is_ancestor(ch,v)){
                alldist= alldist - subtreeAns[ch]-subtrsize[ch];
            }
         }
         int difflu= llca-lu;


     }


      
    }

  return 0;
  }