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
vi r;
vector<list<int>> graph;
int getpar(int a)
{
    if (par[a] == a)
    {
        return a;
    }
    else
        return par[a]=getpar(par[a]);
}

void unionn(int a, int b)
{

    // par[b]=a;

    a = getpar(a);
    b = getpar(b);
    if (a != b)
    {
        if (r[a] == r[b])
        {
            r[a]++;
        }
        if (r[a] > r[b])
        {
            par[b] = a;
        }
        else
        {
            par[a] = b;
        }
    }
}



// void cut(int a, int b)
// {
//     int pa = par[a];
//     int pbb = par[b];
//     // debug(a, b, pa, pbb, par);
//     if (pa == b)
//     {
//         list<int>::iterator it;
//         graph[a].remove(b);
//         graph[b].remove(a);
        
//         if (graph[a].size() >= 1)
//         {
//             int temp = 0;
//             for (it = graph[a].begin(); it != graph[a].end(); ++it)
//             {
//                 if (*it != b)
//                 {
//                     temp = *it;
//                     break;
//                 }
//             }
//             if(par[temp]!=a)
//             par[a] = temp;
//             else par[a]=a;
//         }
//         else
//             par[a] = a;
//     }
//     if (pbb == a)
//     {
//         list<int>::iterator it;
//         graph[b].remove(a);
//         graph[a].remove(b);
//         if (graph[b].size() >= 1)
//         {
//             int temp = 0;
//             for (it = graph[b].begin(); it != graph[b].end(); ++it)
//             {
//                 if (*it != a)
//                 {
//                     temp = *it;
//                     break;
//                 }
//             }
//             if(par[temp]!=b)
//             par[b] = temp;
//             else par[b]=b;
//         }
//         else
//             par[b] = b;
//     }
//     debug(par);
// }



int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    graph.resize(n+1);
    par.resize(n + 1);
    r.resize(n + 1, 0);
    for (int i = 0; i < n + 1; i++)
    {
        par[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        // graph[x].pb(y);
        // graph[y].pb(x);   can be used if final graph isn't completely disconnected , here we would store the final state of the graph.
       
    }
    vector <pair<int, pair<int,int>>> queries;
    for (int i = 0; i < k; i++)
    {
        string s;
        cin >> s;

        if (s[0] == 'a')
        {
            int x, y;
            cin >> x >> y;
            queries.pb({0,{x,y}});
            // int aa = getpar(x);
            // int bb = getpar(y);
            // debug(aa, bb, x, y);
            // if (aa == bb)
            // {
            //     cout << "YES\n";
            // }
            // else
            //     cout << "NO\n";
        }
        else
        {
            int x, y;
            cin >> x >> y;
            queries.pb({1,{x,y}});
            // graph[x].remove(y);
            // graph[y].remove(x);
        }
    }
    vector<string> ans;
    for (int i = k-1; i >=0; i--)
    {
        if(queries[i].f==0){
            int x=queries[i].sec.f;
                int y=queries[i].sec.sec;
                 int aa = getpar(x);
            int bb = getpar(y);
            // debug(aa, bb, x, y,par);
            if (aa == bb)
            {
               ans.pb("YES");
            }
            else
                ans.pb("NO");
        }
        else{
                int x=queries[i].sec.f;
                int y=queries[i].sec.sec;
                 unionn(x, y);
        }
        
    }
    int size=ans.size();
    for (int i = size-1; i >=0; i--)
    {
        cout<<ans[i]<<"\n";
        
    }
    
    

    return 0;
}