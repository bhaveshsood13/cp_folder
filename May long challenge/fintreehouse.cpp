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
const int siz=4*(1e5)+4;
vl adj[siz];
vl val(siz, 0);
vl par(siz, -1);
ll mod=1e9+7;
ll dfs(ll v,ll parent){

    par[v]=parent;

    vl weights;
    weights.clear();
    for(auto i : adj[v]){
        if(i!=par[v]){
           ll x= dfs(i , v);
           weights.pb(x);
        }
    }

    sort(weights.begin(),weights.end(),greater<ll>());
    ll ans=0;
    ll counter=1;
    for (int i = 0; i < weights.size(); i++)
    {   
        ans+=(weights[i]*counter);
        counter++;
    }
    
    return (ans+1);
}








void init( int n){
    for (int i = 0; i < n+1; i++)
    {
        adj[i].clear();
        val[i]=0;
        par[i]=-1;
    }
    
}


int main()
{   
      ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t;
    cin >> t;
    while (t--)
    {
        ll n, X;
        cin >> n >> X;
        init( n);
        vl height(n + 1, 0);
      
        
      
        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
      ll ans=dfs(1,-1)%mod;
      ll y=X%mod;
       cout<< (ans*y)%mod<<"\n";

        // ll ans=0;
        // for (int i =1; i < n+1; i++)   
        // {
        //     ans+=val[i];
        //     ans%=mod;
        // }
        // debug(val);
        // cout<<ans<<"\n";
    }

    return 0;
}