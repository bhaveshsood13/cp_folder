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

bool good(ll mid, vi& req, vi& price, vi& given,ll r){

    ll amountneeded=0;

    for (int i = 0; i < 3; i++)
    {
        ll tpieces=mid*req[i];
        amountneeded+=max(0ll,(tpieces-given[i])*price[i]) ;
    }

    if(amountneeded<=r) return true;
    else return false;
}

int main(){
    string s;
    cin >> s;
    int nb, ns, nc, pb, ps, pc;
    vi price(3,0);
    vi given(3,0);
    cin >> given[0] >> given[1] >> given[2] >> price[0] >> price[1] >> price[2];
    nb=given[0];
    ns=given[1];
    nc=given[2];
    ll ri;
    cin >> ri;
    int cb = 0, cs = 0, cc = 0;
    vi req(3,0);
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'B')
        {
            cb++;req[0]++;
        }

        if (s[i] == 'S')
        {
            cs++;req[1]++;
        }

        if (s[i] == 'C')
        {
            cc++;req[2]++;
        }
    }

    ll l=0,r=1e13;
    while(l<=r){
        ll mid=(l+r)/2;
        debug(l,r,mid);
        if(good(mid,req,price,given,ri)){
            l=mid+1;
        }
        else r=mid-1;
    }

    cout<<l-1;

  return 0;
  }