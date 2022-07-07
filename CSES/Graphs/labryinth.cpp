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
 
 int vis[1000][1000]={0};
  int dx[]={0,-1,1,0};
  int dy[]={1,0,0,-1};
   char grid[1000][1000];
 
void dfs(int i , int j,int n , int m){
      vis[i][j]=1;
      for (int k = 0; k < 4; k++)
      {
          int nexti=i+dy[k];
          int nextj=j+dx[k];
        //   debug(nexti,nextj);
          if(vis[nexti][nextj]==0 and nexti<n and nextj<m and nexti >=0 and nextj>=0){
              if(grid[nexti][nextj]!='#')
              dfs(nexti,nextj, n ,m);
          }
      }
      
  }


int main(){
     int n,m;
    cin>>n>>m;
    pi s, e;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <m;j++)
        {       
                cin>>grid[i][j];
                if(grid[i][j]=='A'){
                    s.f=i;
                    s.sec=j;
                }
                if(grid[i][j]=='B'){
                    e.f=i;
                    e.sec=j;
                }
                
        }   
    }

    dfs(s.f,s.sec,e.f,e.sec)

    
  return 0;
  }