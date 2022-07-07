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

ll finans = 0;

bool good(int ans[], ll T, int t[], int z[], int y[], int n, int m)
{

    ll ttcount = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = T;
        int count = 0;
        int tcount = 0;
        int t2i = t[i] * z[i] + y[i];
        ll a = T / t2i;

        if (a * t2i == T)
        {
            a--;
        }
        ll b = (a)*t2i;
        ll ff = b / t2i;
        if (a == 0)
            b = 0;
        tcount += (a)*z[i];
        ll c = T - b;
        ll d = c / t[i];
        ll e = d;
        if (e > z[i])
        {
            e = z[i];
        }
        tcount += e;
        // debug(T, i, t2i, a, b, c, ff, d, e, t[i], tcount);
        // while(temp>0){
        //     // debug(T,temp);
        //     temp-=t[i];
        //     if(temp<0) break;
        //     count++;
        //     tcount++;
        //     if(count==z[i]){
        //         temp-=y[i];
        //         count=0;
        //     }
        // }

        ttcount += tcount;
    }
    if (ttcount >= m)
    {
        int tacount = 0;
        for (int i = 0; i < n; i++)
        {
            int temp = T;
            int count = 0;
            ll tcount = 0;
            int t2i = t[i] * z[i] + y[i];
            int a = T / t2i;

            if (a * t2i == T)
            {
                a--;
            }
            int b = (a)*t2i;
            int ff = b / t2i;
            if (a == 0)
                b = 0;
            tcount += (a)*z[i];
            int c = T - b;
            int d = c / t[i];
            int e = d;
            if (e > z[i])
            {
                e = z[i];
            }
            tcount += e;
            // debug(T, i, t2i, a, b, c, ff, d, e, t[i], tcount);
            if (tacount+tcount <= m)
                ans[i] = tcount;
            else if( tacount+tcount>=m and tacount<m){
                    ans[i]=m-tacount;
            }   
            else
                ans[i] = 0;
            tacount += tcount;
            ttcount += tcount;
        }

        return true;
    }

    else
        return false;
}

int main()
{
    int m, n;
    cin >> m >> n;
    int t[n], z[n], y[n];
    for (int i = 0; i < n; i++)
    {
        cin >> t[i] >> z[i] >> y[i];
    }
    int ans[n] = {0};
    ll r = 1e9, l = -1;
    // while(!good(ans,r,t,z,y,n,m)){
    //     r*=2;
    // }
    // // cout<<"Starting while";
    while (r >= l)
    {
        ll mid = (r + l) / 2;
        // debug(r, l, mid);
        if (good(ans, mid, t, z, y, n, m))
        {
            finans = mid;

            // debug("mid-1", r);
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    cout << finans << "\n";

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}