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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        vi ari, arj, xx, yx;
        for (int i = 0; i < n - 1; i++)
        {
            int x = gcd(arr[i], arr[i + 1]);
            if (x != 1)
            {
                if (arr[i] <= arr[i + 1])
                {

                    ari.pb(i + 1);
                    arj.pb(i + 2);
                    xx.pb(arr[i]);
                    yx.pb(arr[i] + 1);
                    arr[i + 1] = arr[i] + 1;
                }
                else
                {
                    int temp = arr[i + 1] + 1;
                    if (i >= 1)
                    {
                        int prev = arr[i - 1];
                        debug(gcd(prev, temp)==1);
                        if (gcd(prev, temp) == 1)
                        {
                            debug("here");
                            ari.pb(i + 1);
                            arj.pb(i + 2);
                            xx.pb(temp);
                            yx.pb(arr[i + 1]);
                            arr[i] = temp;
                        }
                        else
                        {
                            int tt =gcd(prev,temp);
                            int ty=gcd(temp,arr[i+1]);
                            debug("rea",tt,ty);
                            while ( tt!= 1 or ty!= 1)
                            {
                                debug("gere",temp);
                                temp++;
                                tt =gcd(prev,temp);
                            ty=gcd(temp,arr[i+1]);
                            }
                            ari.pb(i + 1);
                            arj.pb(i + 2);
                            xx.pb(temp);
                            yx.pb(arr[i + 1]);
                            arr[i] = temp;
                        }
                    }
                    else
                    {
                        ari.pb(i + 1);
                        arj.pb(i + 2);
                        xx.pb(temp);
                        yx.pb(arr[i + 1]);

                        arr[i] = temp;
                    }
                }
            }
        }

        debug(yx, ari.size());
        cout << ari.size() << "\n";
        for (int i = 0; i < ari.size(); i++)
        {
            cout << ari[i] << " " << arj[i] << " " << xx[i] << " " << yx[i] << "\n";
        }
    }

    return 0;
}