//https://www.codechef.com/COOK127B/problems/WATRA

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
vector<vector<pi>> mat;

unordered_map<int, pi> dir;

bool good(ll mid, int k, int n, int m)
{

    vector<vector<pi>> graph[n];
    vector<vector<int>> dis(n, vi(m, 2e9));
    priority_queue < pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>> q;
    q.push({0, {0, 0}});

    dis[0][0] = 0;
    while (!q.empty())
    {
        int curdis = q.top().f;
        int curi = q.top().sec.f;
        int curj = q.top().sec.sec;
        q.pop();

        if (curdis != dis[curi][curj])
            continue;

        for (int i = 0; i < 4; i++)
        {
            pi direct = dir[i];
            if (curi + direct.f < 0 or curj + direct.sec >= m or curi + direct.f >= n or curj + direct.sec < 0)
                continue;
            else
            {
                int newi = curi + direct.f;
                int newj = curj + direct.sec;
                int curdir = mat[curi][curj].sec;
                if (i == curdir)
                {   if (mat[curi][curj].f >= mid){
                    if (curdis < dis[newi][newj])
                    {
                        dis[newi][newj] = curdis;
                        q.push({curdis, {newi, newj}});
                    }}
                }
                else
                {
                    int op = i - curdir;
                    if (op < 0)
                    {
                        op += 4;
                    }
                    if (mat[curi][curj].f - op >= mid)
                    {
                        if (curdis +op < dis[newi][newj])
                        {   
                            dis[newi][newj] = curdis+op;
                            q.push({curdis+op, {newi, newj}});
                        }
                    }
                }
            }
        }
    }
    debug(dis);
    if(dis[n-1][m-1]<=k) return true;
    else return false;
}

int main()
{   
    dir[0] = {-1, 0};
dir[2] = {1, 0};
dir[3] = {0, -1};
dir[1] = {0, 1};

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        mat.resize(n, vpi(m));
        int maxel=-1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j].f;
                if(mat[i][j].f>maxel){
                    maxel=mat[i][j].f;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char c;
                cin >> c;
                if (c == 'U')
                    mat[i][j].sec = 0;
                if (c == 'R')
                    mat[i][j].sec = 1;
                if (c == 'D')
                    mat[i][j].sec = 2;
                if (c == 'L')
                    mat[i][j].sec = 3;
            }
        }
        debug(mat);
        ll l = 0, r =maxel+1;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            bool chek=good(mid,k,n,m);
            debug(l,r,mid,chek);
            if (chek)
            {   
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        if(l==0) cout<<l <<"\n";
        else 
        cout << l - 1 << "\n";
    }

    return 0;
}