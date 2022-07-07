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
 
 
 
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vpl adj[n+1];
    for (int i = 0; i < m; i++)
    {
        ll x,y,z;
        cin>>x>>y>>z;
        adj[x].pb({y,z});
        adj[y].pb({x,z});
    }
    vi stor(n+1,0);
    queue<pl> qu;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin>>x;
        stor[x]=1;
        qu.push({x,0});
    }
    ll mindis=1e18;
    vl dis(n+1,1e18);
    vi vis(n+1,0);
    while(!qu.empty()){
        pl top=qu.front();
        qu.pop();
        vis[top.first]=1;
        // debug(top);
        if(top.second>mindis) continue;

        for(auto i : adj[top.first]){
            if(dis[i.first]>(top.second+i.second)){
                dis[i.first]=top.second+i.second;
                qu.push({i.first,dis[i.first]});
                if(stor[i.first]==0){
                mindis=min(mindis,dis[i.first]);
                // debug(mindis);
                }
            }
        }
    }
    if(mindis!=1e18){
        cout<<mindis<<"\n";
    }
    else cout<<-1;
  return 0;
  }