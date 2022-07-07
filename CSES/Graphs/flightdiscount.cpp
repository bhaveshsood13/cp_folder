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
 
void dijkstra(int source,vpi adj[],vl & dis){
    priority_queue<pl> qu;
    dis[source]=0;
    qu.push({0,source});
    while(!qu.empty()){
        pl top=qu.top();
        qu.pop();
        //  debug(top.sec, dis[top.sec]);
        if((-top.f)!=dis[top.sec]) continue;
        for(auto i : adj[top.sec]){
           
            if(dis[i.f] > dis[top.sec]+i.sec){
                dis[i.f]=dis[top.sec]+i.sec;
                qu.push({(-dis[i.f]),i.f});
            }
        }
    }
}
 
int main(){
   int n,m;
   cin>>n>>m;
   vpi adj[n+1];
   vpi adjrev[n+1];
   for(int i=0;i<m;i++){
       int a,b,c;
       cin>>a>>b>>c;
       adj[a].push_back({b,c});
       adjrev[b].push_back({a,c});
   }
   //find distances from 1 to all other nodes;
   vl dis1(n+1,1e18);
   vl dis2(n+1,1e18);
   dijkstra(1,adj,dis1);
   dijkstra(n,adjrev,dis2);
   ll ans=1e18;
   for(int i=1;i<=n;i++){
       for(auto v : adj[i]){
           ll to=v.f;
           ll w=v.sec;
           ll pos=dis1[i]+(w/2)+dis2[to];
           ans=min(ans,pos);
       }
   }
    cout<<ans;
 
  return 0;
  }