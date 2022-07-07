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

int dfs(int v, int par, vi & heights, vi adj[]){
    int hh=0;
    int c=0;
    for(auto i: adj[v]){
        if (i!=par) 
        c=dfs(i,v,heights,adj);
        hh=max(c,hh);
    }
    heights[v]=hh+1;
    return heights[v];
}

void dfs2(int v, int par, vi & heights, vi adj[],vi & counter, int cnt){
    int subh=0;
    bool last=true;
     bool f=true;
    for(auto i : adj[v]){
        if (i!=par) {
            last=false;
            subh=max(heights[i],subh);
        }
    }
    if(last) {counter.pb(cnt); 
    return ;}
   
    for(auto i  : adj[v]){
        if(i!=par){
            if(subh==heights[i] and f ){
                 f=false;
                dfs2(i,v,heights,adj,counter,cnt+1);
               
            }
            else dfs2(i,v,heights,adj,counter,1);
        }
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
      int n,k;
      cin>>n>>k;
      
    
      vi adj[n+1];
      for (int i = 0; i < n-1; i++)
      {
          int u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
      }
      if(k==1) {cout<<"1\n";}
      else{
      queue<int> qu;
      qu.push(1);
      int fnode;
      int lvl=0;
      vi vis(n+1,0);
      while(!qu.empty()){
          int siz=qu.size();
          lvl++;
          for (int i = 0; i < siz; i++)
          {
              int top=qu.front();qu.pop();
              vis[top]=1;
              fnode=top;
              for (auto i : adj[top])   
              {
                  if(vis[i]==0){
                    vis[i]=1;
                    qu.push(i);
                  }
              }
          }
      }

      vi heights(n+1,0);
      dfs(fnode,-1,heights,adj);
      vi counter;
      dfs2(fnode, -1, heights,adj,counter,1);
      sort(counter.begin(),counter.end(),greater<int>());
      int ans=1; int nodes=0;
      int pos=0;
      while(nodes<k){
         nodes+=counter[pos];pos++;
         ans++;
      } 
      cout<<ans<<"\n";
      }
    }

  return 0;
  }