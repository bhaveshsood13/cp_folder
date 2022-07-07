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
vi experience;
int get(int a)
{   
    if(par[a]==a)
    return a;
    else{
        
        int c=get(par[a]);
        if(c!=par[a])
        experience[a]+=experience[par[a]];
        par[a]=c;
        
        return c;
    }

    //or if(par[a]==a)
    //return a;
    // else par[a]=get(par[a]);
    //return par[a]
}
void unionn(int a, int b)
{
    a = get(a);
    b = get(b);
    if (a != b)
    {
        if (r[a] == r[b])
            r[a]++;
        if (r[a] > r[b])
        {
            par[b] = a;
            experience[b]-=experience[a];
             // we have already done get(a) so a= root of node of a //  so par[b]= root of a

        }
        else
        {
            par[a] = b;
            experience[a]-=experience[b];
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int n, m;
    cin >> n >> m;
    par.resize(n + 1);
    r.resize(n + 1, 0);
    experience.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        par[i] = i; //making each set its own root...
        // this is the condition for finding the leader of the set too
    }
    for (int i = 0; i < m ; i++)
    {
        string s;
        cin >> s;
        if (s[0] == 'a')
        {   
            int x,v;

            cin>>x>>v;
                int aa=get(x);
                experience[aa]+=v;

        }
        else if (s[0] == 'j')
        {
            int x,y;
            cin>>x>>y;
            unionn(x,y);
        }
        else
        {
            int x;
            cin>>x;
            debug(experience,par);
            if(par[x]==x){
                cout<<experience[x]<<"\n";
            }
            else{
            int aaa=get(x);
            debug(experience[x],experience[aaa],aaa,x);
        
            int ans=experience[x]+experience[aaa];
            cout<<ans<<"\n";}
        }
    }

    return 0;
}