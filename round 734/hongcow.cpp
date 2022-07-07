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
ll numberofedges=0;
bool containssp=false;
int dfs(int v, vi adj[], vi& vis ,vi &spn){
    vis[v]=1;
    if(spn[v]==1) containssp=true;
    int numberofnodes=0;
    for(auto i : adj[v]){
        numberofedges++;
        if(vis[i]!=1){
           numberofnodes+=dfs(i,adj,vis,spn);
        }
    }
    return numberofnodes+1;
}
 
 
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vi adj[n+1];
    vi spn(n+1,0);
    for (int i = 0; i < k; i++)
    {   int x;
        cin>>x;
        spn[x]=1;
    }
    
    for (int i = 0; i <m ; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vi vis(n+1,0);
    int components=0;
    ll additions=0;
    ll maxcont=-1;
    ll maxnoncon=0;
    for (int i = 1; i <= n; i++)
    {   
         if(vis[i]!=1 and spn[i]==1){
            numberofedges=0;
            containssp=false;
            int numberofnn=dfs(i,adj,vis,spn);
            numberofedges/=2;
            ll totaled=(numberofnn*(numberofnn-1)/2);
            additions+=totaled-numberofedges;
               maxcont=max(maxcont,(long long)numberofnn);
         }
    }
    
    for (int i = 1; i <= n; i++)
    {
        if(vis[i]!=1){
            components++;
            numberofedges=0;
            containssp=false;
            int numberofnn=dfs(i,adj,vis,spn);
            numberofedges/=2;
            ll totaled=(numberofnn*(numberofnn-1)/2);
            additions+=totaled-numberofedges;
            // debug(i,numberofnn,numberofedges,containssp,additions);
         
            if(!containssp){
                additions+=numberofnn*maxcont;
                maxcont+=numberofnn;
                maxnoncon+=numberofnn;
            }
        }
    }
    // additions+=maxcont*maxnoncon;
    cout<<additions<<"\n";
    
    
    
  return 0;
  }