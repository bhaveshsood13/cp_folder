#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <stack>
#include<list>
#include <map>
#include <set>
#include <functional>
#include <utility>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cassert>
#include <sstream>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db;
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
 
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL) 
#define cinarr(ar,n) for(int i=0;i<n;i++){cin>>ar[i];}
#define car(ar,n) for(int i =0;i<n;i++){cout<<ar[i]<<" ";}
#define forn(i,a,b) for (int i = (a); i < ll(b); ++i)
#define fo(i,a) forn(i,0,ll(a))
#define rforn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ro(i,a) rforn(i,0,a)
#define trav(a,x) for (auto& a: x)
 
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define rsz resize
#define ins insert
 
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second
 
ll mod = 1000000007;
inline ll fast_expo(ll base,ll power,ll modulo=mod){
    base%=modulo;
    if (base<0) base+=modulo;
    ll x=base,cnt=power,ans=1;
    while(cnt){
        if (cnt&1) ans=(ans*x)%modulo;
        x=(x*x)%modulo;
        cnt>>=1;
    }
    return ans;
}
 
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
//=========================CODE STARTS HERE=============================//
 
 int main(){
  int t;
  cin>>t;
  while(t--){
      int n;
      cin>>n;
      int n2=2*n;
      int co=0,ce=0,ar[n2];
      list <int> odar,evar;
      int op=0,ep=0;
      for (int i = 0; i <2*n; i++)
      {    cin>>ar[i];
          if(ar[i]&1){
              odar.push_back(i+1);
              op++;
              co++;
          }
          else {evar.push_back(i+1);
          ep++;
              ce++;}
      }
      if(co&1 and ce&1){
          odar.pop_back();
          int i=0;
          while(odar.size()!=0){
              cout<<odar.front();
              odar.pop_front();
              cout<<" "<<odar.front()<<endl;
              odar.pop_front();
          }
           evar.pop_back();
          
          while(evar.size()!=0){
              cout<<evar.front();
              evar.pop_front();
              cout<<" "<<evar.front()<<endl;
              evar.pop_front();
          } 

          }
    else{
        if(odar.size()>=evar.size())
         {odar.pop_back();
         odar.pop_back();}
         else{
            evar.pop_back();
            evar.pop_back();
         }
         int i=0;
          while(odar.size()!=0){
              cout<<odar.front();
              odar.pop_front();
              cout<<" "<<odar.front()<<endl;
              odar.pop_front();
          }
          
          while(evar.size()!=0){
              cout<<evar.front();
              evar.pop_front();
              cout<<" "<<evar.front()<<endl;
              evar.pop_front();
          } 
    }

      }
      
  
 

  return 0;
 }