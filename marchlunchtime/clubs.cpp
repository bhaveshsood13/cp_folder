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


int find_set(int v, vi& par) {
    if (v == par[v])
        return v;
    return par[v] = find_set(par[v],par);
}

// void make_set(int v) {
//     parent[v] = v;
//     rank[v] = 0;
// }

void union_sets(int a, int b, vi& par, vi& rank) {
    a = find_set(a, par);
    b = find_set(b,par);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        par[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}


int main(){
    int t;
    cin>>t;
    debug(t);
    while(t--){
      ll c,n,m;
      cin>>c>>n>>m;
      debug(c,n,m);
      vi par(c,-1);
      for (int i = 0; i < c; i++)
      {
          par[i]=i;
      }
      
      vi rank(c,0);
      vector<pair<int,pi>> segments;
     for (int i = 0; i < c; i++)
     {
         int segno;
         cin>>segno;
          
         for (int j = 0; j < segno; j++)
         {       int l,r;
             cin>>l>>r;
             segments.pb({l,{r,i}});
             debug(segments);
         }
         
     }
     debug(segments);
      sort(segments.begin(),segments.end());
      debug(segments);
        vector<pair<int,pi>> maxinterval; 
        ll countnoclub=segments[0].f-1;
        ll  lel=segments[0].f,rr=segments[0].sec.f;
        for (int i = 0; i < segments.size()-1; i++)
        {   
            if(segments[i+1].f<=rr){
                if(segments[i+1].sec.f>=rr) rr =segments[i+1].sec.f;
            
                union_sets(segments[i].sec.sec ,segments[i+1].sec.sec, par, rank);
                debug(find_set(segments[i].sec.sec,par));
            }
            else {
                countnoclub+=segments[i+1].f- rr-1;
                lel=segments[i+1].f;
                rr=segments[i+1].sec.f;

            }
        }
        countnoclub+=(n-rr);
        set<int> sets;
        for (int i = 0; i < c; i++)
        {
            sets.insert(par[i]);
        }
        ll differentclubs=sets.size();
        ll modd=998244353;
        ll bb=countnoclub+differentclubs;
        ll ans=binpow(m,bb,modd)%modd;
        cout<<ans<<"\n";

      
    }

  return 0;
  }