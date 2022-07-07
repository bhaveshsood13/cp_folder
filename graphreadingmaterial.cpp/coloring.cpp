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
 int cnt=0;

 void dfs(int v, vi adj[],int par, vi & col, vi & reqco){
     int coltofill=reqco[v];
     int curcol=col[v];
     int parcol=col[par];
    //    debug("11",v ,col[v],coltofill,parcol);
     if(parcol==coltofill){
        col[v]=coltofill;
     }
     else if( curcol!= coltofill){
        //  debug(v ,col[v],par,coltofill,parcol);
         col[v]=coltofill;
         cnt++;
     }
    for(auto i : adj[v]){
        if(i!=par){
            dfs(i,adj,v,col,reqco);
        }
    }
 }
 
 
int main(){
    int n;
    cin>>n;
    vi adj[n+1];
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin>>x;
        adj[i].pb(x);
        adj[x].pb(i);
    }
    vi reqco(n+1,0); 
    for (int i = 1; i <=n; i++)
    {
        cin>>reqco[i];
    }
    
    vector<int> vis(n+1,0);
    vector<int> col(n+1,0);
    dfs(1,adj,0,col,reqco);
    cout<<cnt;

  return 0;
  }