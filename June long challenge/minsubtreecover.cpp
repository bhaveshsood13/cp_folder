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
ll ans=0;
int dfs(int v, int par, vi adj[],vi& height,int k){

    vi weights;

    for(auto i : adj[v]){
        if(i!=par){
            int c =dfs(i,v,adj,height,k);
            if(c>height[v]){
                height[v]=c;
            }
            weights.pb(c);
        }
    }
    sort(weights.begin(),weights.end(),greater<int>());
    int posa=1;
    int count=0;
    bool f=false;
    if(weights.size()==1) count++;
    for (int i = 0; i < weights.size(); i++)
    
    {
          count++;
        posa+=weights[i];
        if(posa>=k) { 
            // debug(v,i,adj[v],weights);
             f=true;break;
             }
    }
    if(ans>count and f) ans=count;
    height[v]++;
    return height[v];
}


int main(){
    int t;
    cin>>t;
    while(t--){
      int n,k;
      cin>>n>>k;
      vi adj[n+1];
      ans=INT_MAX;
      for (int i = 0; i < n-1; i++)
      {
          int x,y;
          cin>>x>>y;
          adj[x].pb(y);
          adj[y].pb(x);
      }
    vi height(n+1,0);
    dfs(1,-1,adj,height,k);
    cout<<ans<<"\n";

      
    }

  return 0;
  }