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
vi par;
vi r;
vector<list<int>> graph;

int get(int a){
    if(par[a]==a) return a;
    else return par[a]=get(par[a]);
}

void unionn(int a, int b){
    a=get(a);
    b=get(b);
    if(a!=b){
    if(r[a]==r[b]){
        r[b]++;
    }
    if(r[a]>r[b]){
        par[b]=a;
    }
    else {
        par[a]=b;
    }
    }
}


int main(){ 

    int n,m;
    cin>>n>>m;
    par.resize(n+1);
    r.resize(n+1,0);
    graph.resize(n+1);
    vpi hands(n+1);
    for (int i = 0; i < n+1; i++)
    {
            par[i]=i;
    }
    
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        hands[i+1]={x,y};
        if(x!=-1){
            graph[i+1].pb(x);
            graph[x].pb(i+1);
        }
         if(y!=-1){
            graph[i+1].pb(y);
            graph[y].pb(i+1);
        }

    }
    vpi queries;
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        queries.pb({x,y});
        int cutv;
        if(y==1){
            cutv=hands[x].f;
        }
        else cutv=hands[x].sec;
        graph[x].remove(cutv);
        graph[cutv].remove(x);
    }

    for (int i = 1; i < n+1; i++)   
    {
        for( auto x : graph[i]){
            unionn(x,i);
        }
    }
    debug("orignal parents",par);
    vi ans(n+1,-1);
    vi connected(n+1,0);
    connected[1]=1;
    int parent1=par[1];
    
    for (int i = 0; i < n+1; i++)
    {
        if(par[i]==parent1){
            connected[i]=1;
        }
    }
    


    for (int i = m-1; i>=0; i--)
    {   
          int x=queries[i].f;
          int y=queries[i].sec;
          int cutv;
          if(y==1){
            cutv=hands[x].f;
            }
          else cutv=hands[x].sec;
          
         int parx=get(x);
         int par1=get(1);
         int parcutv=get(cutv);

         if(parx==par1  ){
             for (int j = 0; j < n+1; j++)
             {
                 if(par[j]==parx){
                     ans[j]=i;
                 }
             }
             
         }
        
         if(parcutv== par1 ){
             for (int j = 0; j < n+1; j++)
             {
                 if(par[j]==parcutv){
                     ans[j]=i;
                 }
             }
             
         }
         unionn(x,cutv);
        //  if(  connected[parcutv]!=1 and connected[parx]!=1)
        //   unionn(parx,parcutv);
         
        //  if(connected[parcutv]==1 and connected[parx]!=1){
        //     debug("here");
        //      ans[parx]=i;
        //     connected[parx]=1;
        //  }
         
        // else if(connected[parcutv]!=1 and connected[parx]==1){
        //     debug("here");
        //      ans[parcutv]=i;
        //      connected[parcutv]=1;
        //  }
          debug("dd",par,ans,parcutv,par1,parx,connected);
    }
    debug(ans,par);
    // cout<<"-1\n";
    for (int i = 1; i < n+1; i++)
    {
        cout<<ans[i]<<"\n";
    }
    
    
    
    


  return 0;
  }