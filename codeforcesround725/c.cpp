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
        int l, r;
        cin >> l >> r;
        vi arr(n);
        for (int i = 0; i < n; i++)
        {
          int x;
          cin>>x;
          arr[i]=x;
        }
        // debug(arr,n,l,r);
        sort(arr.begin(), arr.end());
        ll ans = 0;
        // debug(arr);
        for (int i = 0; i < n; i++)
        {
            int a = arr[i];
            int gte = l - a;
            int ste = r - a;
            // debug(arr[i],a,gte,ste);
            int ig = -1, is = -1;
            int s = i+1, e = n - 1;
            while (s <= e)
            {
                int mid = (s + e) / 2;
                if (arr[mid] >= gte)
                {
                    ig = mid;
                    e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }
            s = i+1, e = n - 1;
            while (s <= e)
            {
                int mid = (s + e) / 2;
                if (arr[mid] <= ste)
                {
                    is = mid;
                    s = mid + 1;
                }
                else
                {
                    e = mid - 1;
                }
            }
            // debug(i, is, ig);
            if(is!=-1 and ig!=-1)
            ans += is - ig + 1;
        }

        cout << ans << "\n";
    }

    return 0;
}