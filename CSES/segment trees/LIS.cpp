/**
 * author: Bhavesh
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define cinarr(ar, n)           \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> ar[i];           \
    }
#define car(ar, n)              \
    for (int i = 0; i < n; i++) \
    {                           \
        cout << ar[i] << " ";   \
    }
#define forn(i, a, b) for (int i = (a); i < ll(b); ++i)
#define fo(i, a) forn(i, 0, ll(a))
#define rforn(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define ro(i, a) rforn(i, 0, a)
#define trav(a, x) for (auto &a : x)

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second

void __print(int x)
{
    cerr << x;
}
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
const ll INF = 1e18;
void update( ll arr[],ll *segtree , int st , int e ,int tidx , int idx , int v ){
    if(st==e){
       arr[idx]=v;
        segtree[tidx]=v;
        return ;
    }
    
    int mid= (st+e)/2;
    if(idx>mid ){
        update( arr,segtree, mid+1, e, 2*tidx+1,idx, v);
    }
    else{
        update(arr,segtree, st, mid, 2*tidx,idx, v);

    }
    segtree[tidx]= max(segtree[2*tidx],segtree[2*tidx+1]);
}

ll query(ll * segtree, int st , int e , int tidx, int left , int right){
    if(st> right or e<left){
        // complete outside
        return 0;
    }
    if(st>= left and e<=right){
        // complete inside
        return segtree[tidx];
        }

    // else partial case left
    int mid= (st+e)/2;
    ll a1=query(segtree, st, mid, 2*tidx, left, right);
    ll a2=query(segtree, mid+1, e, 2*tidx+1, left, right);
    return max(a1,a2);
}

bool comp(pi i, pi j){
    if(i.f<j.f){
        return true;
    }
    else if(i.f==j.f){
        if(i.s>j.s)
        return true;
        else return false;
    }
    else 
    return false;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    pi sortarr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        sortarr[i]=mp(arr[i],i);
      
    }
    ll lis[n+1]={0};
    ll segtree[4*n]={0};
    sort(sortarr,sortarr+n,comp);
    // cout<<"sortarr\n";
//    for (int i = 0; i < n; i++)
//    {
//        cout<<"("<<sortarr[i].f<<","<<sortarr[i].s<<")"<<" ";
//    }
   
    
    for (int i = 0; i < n; i++)
    {
        ll v=query(segtree, 0, n-1,1,0, sortarr[i].s-1);
        // debug("v= ",v,sortarr[i].s-1);
        update(lis,segtree,0,n-1,1,sortarr[i].s,v+1);
    }
    
    ll ans=-1;
    for (int i = 0; i < n; i++)
    {
        if(ans<lis[i]){
            ans=lis[i];
        }
        // cout<<lis[i]<<" ";
    }
    cout<<ans<<"\n";
    

    return 0;
}