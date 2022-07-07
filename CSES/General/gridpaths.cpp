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

ll ans = 0;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int vis[7][7] = {0};

bool emp(int i, int j, int k)
{
    if (i > 6 or j > 6 or i < 0 or j < 0 or k > 48 or vis[i][j]==1)
    {
        return false;
    }
    else
        return true;
}
string s;
void dfs(int i, int j, int k )
{

    if (i == 0 and j ==6)
    {
        // debug(ans,i, j, k);
        if (k == 48)
        {
            // debug(ans, i, j, k);
            ans += 1;
        }
       return;
    }
    // debug(i,j,k,ans);
    vis[i][j] = 1;

    if(s[k]=='?' or s[k]=='L'){
        if(i&&vis[i-1][j]==0){
            // if (!(emp(i-1,j,k+1) and emp (i+1,j,k+1) and (!emp(i,j+1,k+1) and !emp(i,j-1,k+1)))) 
                if(!(!emp(i-2,j,k+1) and emp(i-1,j+1,k+1) and emp(i-1,j-1,k+1)))
                dfs(i-1,j,k+1);
            // }  
            // else {
            //     vis[i][j] = 0;
            //     return;
            // }
        }
    }
    
    if(s[k]=='?' or s[k]=='D'){
        if(j<6 and vis[i][j+1]==0){
            // if (!(emp(i,j+1,k+1) and emp (i,j-1,k+1) and (!emp(i+1,j,k+1) and !emp(i-1,j,k+1)))) 
                 if(!(!emp(i,j+2,k+1) and emp(i+1,j+1,k+1) and emp(i-1,j+1,k+1)))
                dfs(i,j+1,k+1);
            // }  
            //  else {
            //     vis[i][j] = 0;
            //     return;
            // }
        }
    }
    
    if(s[k]=='?' or s[k]=='R'){
        if(i<6 and vis[i+1][j]==0){
            // debug( (!emp(i,j+1,k+1) or !emp(i,j-1,k+1)) ,(j==0 or j==6) );
            //  if (!(emp(i-1,j,k+1) and emp (i+1,j,k+1) and (!emp(i,j+1,k+1) and !emp(i,j-1,k+1)))) 
                 if(!(!emp(i+2,j,k+1) and emp(i+1,j+1,k+1) and emp(i+1,j-1,k+1)))
                dfs(i+1,j,k+1);
            // }  
            //  else {
            //     vis[i][j] = 0;
            //     return;
            // }
        }
    }
    
    if(s[k]=='?' or s[k]=='U'){
        if(j and vis[i][j-1]==0){
            // if (!(emp(i,j+1,k+1) and emp (i,j-1,k+1) and (!emp(i+1,j,k+1) and !emp(i-1,j,k+1)))) 
            if(!(!emp(i,j-2,k+1) and emp(i+1,j-1,k+1) and emp(i-1,j-1,k+1)))
                dfs(i,j-1,k+1);
            // }  
            //  else {
            //     vis[i][j] = 0;
            //     return;
            // }
            
        }
    }
    vis[i][j] = 0;
}

// L , U, R ,D
int main()
{   
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // string s;
    cin >> s;

    dfs(0, 0, 0);
    cout << ans;

    return 0;
}