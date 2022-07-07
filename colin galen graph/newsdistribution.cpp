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

vi par,r;

int getpar(int a){
    return par[a]=(par[a]==a) ? a : getpar(par[a]);
}

void unionn(int a, int b){
    a=getpar(a);
    b=getpar(b);
    if(a!=b){
        if(r[a]==r[b]){
            r[a]++;
        }
       if(r[a]>r[b]){
           par[b]=a;
       }
       else par[a]=b;
    }
}
 
 
int main(){
    int n,m;
    cin>>n>>m;
    par.assign(n+1,0);
    r.assign(n+1,0);
    for (int i = 0; i < n+1; i++)
    {
        par[i]=i;
    }
    
    for (int i = 0; i < m; i++)
    {
        int x;
        cin>>x;
        int first;
        if(x!=0)
        cin>>first;
        // debug(x,first);
        for (int j = 1; j < x; j++)
        {   int nxt;
            cin>>nxt;
            // debug("unioning",first,nxt);
            unionn(first,nxt);
        }
    }
    unordered_map <int,int> map;
    for (int i = 1; i < n+1; i++)
    {   int parr=getpar(i);
        map[parr]++;
    }
    vi ans(n+1);
    // debug(par);
    for (int i = 1; i <= n; i++)
    {
        int parr=getpar(i);
        cout<<map[parr]<<" ";
    }
    
    
 
  return 0;
  }