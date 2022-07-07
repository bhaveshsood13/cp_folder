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

struct segmentnode
{
    ll attr1;
    ll attr2;
};

void build(int arr[], segmentnode *segtree, int st, int e, int tidx)
{
    // base case
    if (st == e)
    {
        segtree[tidx].attr1 = arr[st];
        segtree[tidx].attr2 = 1;
        return;
    }
    int mid = (st + e) / 2;
    build(arr, segtree, st, mid, 2 * tidx);
    build(arr, segtree, mid + 1, e, 2 * tidx + 1);

    //self work
    segtree[tidx].attr1 = min(segtree[2 * tidx].attr1, segtree[2 * tidx + 1].attr1);
    if (segtree[2 * tidx].attr1 == segtree[2 * tidx + 1].attr1)
    {
        segtree[tidx].attr2 = segtree[2 * tidx].attr2 + segtree[2 * tidx + 1].attr2;
    }
    else {
        if(segtree[2 * tidx].attr1 > segtree[2 * tidx + 1].attr1)
        segtree[tidx].attr2 =segtree[2 * tidx + 1].attr2;
        else
        {
            segtree[tidx].attr2 =segtree[2 * tidx].attr2;
        }
        
    }
}

void update(int arr[], segmentnode *segtree, int st, int e, int tidx, int idx, int v)
{
    if (st == e)
    {
        arr[idx] = v;
        segtree[tidx].attr1= v;
        segtree[tidx].attr2=1;
        return;
    }

    int mid = (st + e) / 2;
    if (idx > mid)
    {
        update(arr, segtree, mid + 1, e, 2 * tidx + 1, idx, v);
    }
    else
    {
        update(arr, segtree, st, mid, 2 * tidx, idx, v);
    }
    segtree[tidx].attr1 = min(segtree[2 * tidx].attr1, segtree[2 * tidx + 1].attr1);
    if (segtree[2 * tidx].attr1 == segtree[2 * tidx + 1].attr1)
    {
        segtree[tidx].attr2 = segtree[2 * tidx].attr2 + segtree[2 * tidx + 1].attr2;
    }
    else {
        if(segtree[2 * tidx].attr1 > segtree[2 * tidx + 1].attr1)
        segtree[tidx].attr2 =segtree[2 * tidx + 1].attr2;
        else
        {
            segtree[tidx].attr2 =segtree[2 * tidx].attr2;
        }
        
    }

}

segmentnode query(segmentnode *segtree, int st, int e, int tidx, int left, int right)
{
    if (st > right or e < left)
    {   segmentnode a ={INF, 0};
        // complete outside
        return a;
    }
    if (st >= left and e <= right)
    {
        // complete inside
        return segtree[tidx];
    }

    // else partial case left
    int mid = (st + e) / 2;
    segmentnode a1 = query(segtree, st, mid, 2 * tidx, left, right);
    segmentnode a2 = query(segtree, mid + 1, e, 2 * tidx + 1, left, right);
    segmentnode ans;
    ans.attr1=min(a1.attr1,a2.attr1);
    if(a1.attr1==a2.attr1)
    ans.attr2= a1.attr2 +a2.attr2;
    else if(a1.attr1<a2.attr1)
    ans.attr2=a1.attr2;
    else 
    ans.attr2=a2.attr2;
   return ans;
    
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int q;
    cin >> q;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    segmentnode segtree[4 * n];
    build(arr, segtree, 0, n - 1, 1);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 2)
        {
            int l, r;
            cin >> l >> r;
            segmentnode ans=query(segtree, 0, n - 1, 1, l, r - 1) ;
            cout <<ans.attr1<<" "<<ans.attr2 << "\n";
        }
        else
        {
            int i, v;
            cin >> i >> v;
            update(arr, segtree, 0, n - 1, 1, i, v);
        }
    }

    return 0;
}