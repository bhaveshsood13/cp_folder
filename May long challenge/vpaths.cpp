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
const ll siz=1e6;
vi adj[siz];
vi par;
vl dp,tot;
ll mod=1e9+7;
 ll sum=0;
void dfs(int v,int parent){
    dp[v]=1;
     par[v]=parent;
    tot[v]=1;
   
    sum=0;
    debug(sum);
    for (auto i : adj[v])
    {
        if(i!=par[v]){
            dfs(i, v);
            dp[v]+=(2*dp[i])%mod;
            dp[v]%=mod;
           
            tot[v]+=tot[i];
            tot[v]%=mod;
            tot[v]+=dp[i];
            tot[v]%=mod;
            sum+=dp[i];
        }
    }
    debug("1",sum);

    for(auto i : adj[v]){
        if(i!=parent){
            tot[v]+=dp[i]*((sum- dp[i]+mod)%mod)%mod;
            tot[v]%=mod;
        }
    }
}

void init( int n){
    for (int i = 0; i < n+1; i++)
    {
        adj[i].clear();
        
        par[i]=-1;
    }
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      dp.resize(n+1); tot.resize(n+1);par.resize(n+1);
      init(n);
      for (int i = 0; i < n-1; i++)
      {
          int u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);

      }
      dfs(1,-1);
      debug("here");
      ll ans=tot[1]%mod;
      cout<<ans<<"\n";
      dp.clear();tot.clear();

      
    }

  return 0;
  }