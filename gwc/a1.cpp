
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
void showpq(priority_queue<ll> gq)
{
    priority_queue<ll> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';
}
void showpq2(
    priority_queue<ll, vector<ll>, greater<ll>> gq)
{
    priority_queue<ll, vector<ll>,
                   greater<ll>>
        g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';
}
int main()
{

    /*
    3
5 10
5 5 5 5 5
10 0
1 2 3 4 5 6 7 8 9 10
7 2 
1 1 1 4 7 7 7
    */
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int k;
        cin >> k;
        ll arr[n];
   
        unordered_map <ll , ll> v;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            v[arr[i]]++;
        }
        priority_queue<int, vector<int>, greater<int>> minh(arr, arr + n);
        priority_queue<int> maxh(arr, arr + n);

        // showpq2(minh);
        // showpq(maxh);
        ll curdiff=maxh.top()- minh.top();
        ll count=0;
        while(curdiff!=k){
            ll maxc=maxh.top();
            
            ll minc=minh.top();
            if(minc==0 or maxc==0 or v[minc]==n or v[maxc]==n){
                count=0;
                break;
            }
            if(v[maxc]>v[minc]){
                minh.pop();
                minh.push(minc+1);
                maxh.push(minc+1);
                v[minc+1]++;
                v[minc]--;
                // cout<<"o"<<minc+1<<endl;
                count++;
            }
            else if(v[maxc]<=v[minc]){
                maxh.pop();
                maxh.push(maxc-1);
                minh.push(maxc-1);
                v[maxc-1]++;
                v[maxc]--;
                count++;
                // cout<<"o"<<maxc-1<<endl;
            }
            curdiff=maxh.top()- minh.top();
        }
        cout<<count<<endl;
        // while()
    }

    return 0;
}