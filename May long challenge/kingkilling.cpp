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
const ll siz = 1e6;
// vi adj[siz];
vi par;
vi lvl;
vpi leaves;

struct Tree
{
    int data, level;
    vector<Tree *> child;
    Tree(int x)
    {
        data = x;
        level = 0;
    }
};

// void dfs(int v, int parent, int height){
//     par[v]=parent;
//     lvl[v]=height;
//     for(auto i : adj[v]){
//         if(i!=par[v]){
//             dfs(i, v,height+1);
//         }
//     }

// }
// void dfs2(int v){

//     for(auto i : adj[v]){
//         if(i!=par[v]){
//             dfs2(i);
//         }
//     }
//     if(adj[v].size()==1){
//         leaves.pb({lvl[v],v});
//     }
// }

// void init( int n){
//     par.resize(n+1);lvl.resize(n+1);
//     leaves.clear();
//         for (int i = 0; i < n+1; i++)
//     {
//         adj[i].clear();
//         lvl[i]=0;
//         par[i]=-1;
//     }

// }

void depthfs(Tree *root, int l)
{

    root->level = l;
    for (int i = 0; i < root->child.size(); i++)
    {
        Tree *cur = root->child[i];
        depthfs(cur, l + 1);
    }
}

void depthfs2(Tree *root)
{
    for (int i = 0; i < root->child.size(); i++)
    {
        Tree *cur = root->child[i];
        depthfs2(cur);
    }
    if (root->child.size() == 0)
    {
        leaves.pb({root->level, root->data + 1});
    }
}

void createTree(Tree *root, vector<vi> &adj, vector<bool> &vis)
{

    vis[root->data] = 1;
    for (int i = 0; i < adj[root->data].size(); i++)
    {
        if (!vis[adj[root->data][i]])
        {
            Tree *temp = new Tree(adj[root->data][i]);
            root->child.pb(temp);
        }
    }

    for (int i = 0; i < root->child.size(); i++)
    {
        createTree(root->child[i], adj, vis);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vi> adj(n);
        //   init(n);
        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        //   dfs(1,-1,0);
        Tree *root = new Tree(0);
        vector<bool> vis(n, 0);

        createTree(root, adj, vis);
        depthfs(root, 0);

        vpi ans;
        for (int i = 0; i < root->child.size(); i++)
        {
            //   dfs2(adj[1][i]);
            depthfs2(root->child[i]);
            vpi v;
            pi p;
            bool flag = false;
            sort(leaves.begin(), leaves.end());
            p = leaves[0];
            v.push_back(p);
            int val = p.first;
            int j = 1;
            while (j < leaves.size())
            {
                while (j < leaves.size() && leaves[j].first == val)
                {
                    if (flag)
                        v.pb({p.f + 1, leaves[j].sec});
                    else
                        v.pb(leaves[j]);
                    j++;
                }
                if (j < leaves.size())
                {
                    v.clear();
                    flag = 1;
                    p.sec = leaves[j].sec;
                    v.pb({p.f + 1, leaves[j].sec});
                    val = leaves[j].f;
                    j++;
                }
            }
            leaves.clear();
            for (auto x : v)
            {
                ans.pb(x);
            }
        }
        sort(ans.begin(), ans.end());
        int day = ans[0].f;
        vi sortans;
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i].f == day)
            {
                sortans.pb(ans[i].sec);
            }
            else
            {
                break;
            }
        }
        cout << sortans.size() << " " << day << endl;
        for (auto x : sortans)
        {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}