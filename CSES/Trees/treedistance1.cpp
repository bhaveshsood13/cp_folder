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



void dfs(vi adj[],vi& height,int v=0,int par=-1){
   

    for(auto i : adj[v]){
        if(i!=par){
            dfs(adj,height,i,v);
            height[v]=max(height[i]+1,height[v]);
         
        }
    }
    return;
}

void dfs2(vi adj[],vi & height,vi& dist, int v, int par){
    // set the max distance of the children of v;
    int max1=-1,max2=-1;
    //maxinum and second maximum distances in subtree of v;
    for(auto i: adj[v]){
        if(i!=par){
            if(height[i]>=max1){
                max2=max1;
                max1=height[i];
            }
            else if(height[i]>max2){
                max2=height[i];
            }
        }
    }
    // now we have node the height of each node and we already have the answer for root(v) node. we set answer for children of v.

    for(auto i : adj[v]){
        if(i!=par){
            // if this edge is the edge with max height
            if(max1==height[i]){
                dist[i]=1+ max(max2+1,dist[v]);
            }
            else{
                dist[i]=1+ max(max1+1,dist[v]);
            }

            // now call dfs2 for children since dist[i] is set;
            
            dfs2(adj,height,dist,i,v);
          
        }
         
    }

}




int main(){
    int n;
    cin>>n;

    vi adj[n];
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vi height(n,0);
    vi dist(n,0);

    dfs(adj,height);
    // debug(maxnode,maxdepth);
    // dist[0]=height[0];
    dfs2(adj,height,dist,0,-1);
    debug(height,dist);
    for(int i=0;i<n;i++){
        cout<<max(height[i],dist[i])<<" ";
    }
  return 0;
  }