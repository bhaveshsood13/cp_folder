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
ll minans;
void solve(string s, int c1,int c2,int l1,int l2, ll ind){
    // debug(minans,ind,c1,c2,l1,l2);
    if(ind==10){
        ll ten=10;
        minans=min(minans,ten);
        return;   
    }
    if(c1+l1<c2 or c2+l2<c1){
        minans=min(minans,ind);
        return;
    }
    if(s[ind]=='1'){
        if(ind%2==0){
            solve(s,c1+1,c2,l1-1,l2,ind+1);
        }
        else  solve(s,c1,c2+1,l1,l2-1,ind+1);
    }
    else if(s[ind]=='0'){
        if(ind%2==0){
            solve(s,c1,c2,l1-1,l2,ind+1);
        }
        else  solve(s,c1,c2,l1,l2-1,ind+1);
    }
    else {
        if(ind%2==0){
            solve(s,c1,c2,l1-1,l2,ind+1);
            solve(s,c1+1,c2,l1-1,l2,ind+1);
        }
        else  {
            solve(s,c1,c2,l1,l2-1,ind+1);
            solve(s,c1,c2+1,l1,l2-1,ind+1);
            }
    }
    

} 
 
 
int main(){
    int t;
    cin>>t;
    while(t--){
      string s;
      cin>>s;
      minans=11;
      solve(s,0,0,5,5,0);
      cout<<minans<<"\n";
    }
 
  return 0;
  }