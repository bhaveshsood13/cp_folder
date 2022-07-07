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
#define sec second

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

vi par;

int get(int a)
{
    return par[a] = (par[a] == a ? a : get(par[a]));
}

void unionn(int a, int b)
{   
    bool flag=false;
    int par1=get(1);
    a = get(a);
    b = get(b);
    if(b==par1);
    flag=true;
    if (a != b)
    {
        if (a > b and flag==false)
            par[b] = a;
        else
            par[a] = b;
    }
}

int main()
{
    int n;
    cin >> n;
    par.resize(n + 1);
    for (int i = 0; i < n + 1; i++)
    {
        par[i] = i;
    }
    vi wantspot(n + 1, 0);
    vi visited(n + 1, 0);
    vi ans(n + 1, -1);
    for (int i = 1; i < n + 1; i++)
    {
        cin >> wantspot[i];
    }

    for (int i = 1; i < n + 1; i++)
    {
        if (visited[wantspot[i]] == 0)
        {
            visited[wantspot[i]] = 1;
            ans[i] = wantspot[i];
            debug(i, wantspot[i]);
            if (wantspot[i] != n)
                unionn(wantspot[i], wantspot[i] + 1);
            else
                unionn(wantspot[i], 1);
        }
        else
        {
            int khushi = wantspot[i];
            // if(khushi!=n)
            //  unionn(khushi,khushi+1);
            // else{
            //  unionn(khushi,1);
            //  debug("here");
            //  }
            int avail = get(khushi);
            
                visited[avail] = 1;
                ans[i] = avail;
                if (avail != n)
                    unionn(avail, avail + 1);
                else
                    unionn(avail, 1);
    
            debug(i, avail, par, khushi);
        }
    }
    debug(ans);

    for (int i = 1; i < n + 1; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}