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
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    int t;
    cin>>t;
    while(t--){
      int n ,m;
      cin>>n>>m;
      int arr[n];
      for (int i = 0; i < n; i++)
      {
          cin>>arr[i];
      }
      int dest[m];
      for (int i = 0; i < m; i++)
      {
          cin>>dest[i];
      }
      vi sr(n,-1);
      int lp1=-1;
      for (int i = 0; i < n; i++)
      {     
          if(arr[i]==1){
              lp1=i;
              sr[i]=0;
          }
          else if (arr[i]==0){
              if(lp1!=-1)
              sr[i]=i-lp1;
              
          }
          
      }
      int lp2=-1;
      for (int i = n - 1; i >= 0; i--)
      {
          if(arr[i]==2){
              lp2=i;
              sr[i]=0;
          }
          else if (arr[i]==0){
              if(lp2!=-1 and sr[i]!=-1)
              sr[i]=min(lp2-i,sr[i]);
              else if (lp2!=-1 and sr[i]==-1) sr[i]= lp2-i;
              
          }
          
      }
    // debug(sr);

    // cout<<sr;
      for (int i = 0; i < m; i++)
      {
        if(dest[i]==1) cout<<0<<" ";
        else 
         cout<<sr[dest[i]-1]<<" ";
      }
      cout<<"\n";
      
      
      
      
      
    }

  return 0;
  }