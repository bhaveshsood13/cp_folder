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
const int siz=3*(1e5)+4;
vl adj[siz];
  vl height2(siz, 0);
  vl par(siz, -1);
int dfs2(int v, vl adj[], vl &height2, vl &par, ll parent)
{

    par[v] = parent;
    int subchildren=0;
    for (auto i : adj[v])
    {
        if (i != parent)
        {
           int x =dfs2(i, adj, height2, par, v);
           if(x>subchildren) subchildren=x;
        }
    }
    height2[v]=subchildren+1;
    return height2[v];
}

int dfs(int v, vl adj[], vl &height, vl &par, ll parent)
{

    par[v] = parent;
    // debug("Here",v,adj[v]);
    int subchildren=0;
    for (auto i : adj[v])
    {
        if (i != parent)
        {
           int x =dfs(i, adj, height, par, v);
           subchildren+=x+1;
        }
    }
    height[v]=subchildren;
    return height[v];
}
ll mod=1e9+7;

struct mycomp{
    bool operator() (pair<pl,ll>& a,pair<pl,ll>& b){
        if(a.f.f==b.f.f){
            //whichever subtree has lesser immediate children first... usko 2 dena hain.
            int na=a.f.sec;
            int nb=b.f.sec;
            queue <int > qa;
            vector <int>  qca;
            vi qcb;
            queue < int >qb;
            qca.pb(-1);qcb.pb(-1);
            qa.push(na);
            qa.push(-1);
            qb.push(nb);
            qb.push(-1);
            int lamin=1e6;
            int lbmin=1e6;
            while(!qa.empty()){
                int top=qa.front();
                qa.pop();
                debug("here");
                if(top!=-1){
                    int counter=0;
                    for (auto i : adj[top])
                    {
                        if(i!=par[top]){
                            counter++;
                            qa.push(i);
                            // qca.pb(i);
                        }
                    }
                    if(counter!=0)
                    qca.pb(counter);
                    
                }
                else if(top==-1){
                    if(!qa.empty()) {qa.push(-1); qca.pb(-1);}
                }
            }
            while(!qb.empty()){
                int top=qb.front();
                qb.pop();
                if(top!=-1){
                    int counter=0;
                    for (auto i : adj[top])
                    {
                        if(i!=par[top]){
                            counter++;
                            qb.push(i);
                           
                        }
                    }
                   if(counter!=0)
                    qcb.pb(counter);
                    
                }
                else if(top==-1){
                    if(!qb.empty()) {qb.push(-1); qcb.pb(-1);}
                }
            }

            debug(na,nb,qca,qcb);
            bool asmall=true;
            int ca=0,cb=0;
             int amin=1e6,bmin=1e6;
            int ptra=qca.size()-2 , ptrb=qcb.size()-2;

            while(ptra>0 and ptrb>0){

                int la=qca[ptra];
                int lb=qcb[ptrb];
                while(la!=-1){
                     la=qca[ptra];
                       if(la<amin and la!=0 ) amin=la;
                       if(ptra!=0)
                      ptra--;
                }
                while(lb!=-1){
                     lb=qcb[ptrb];
                       if(lb<amin and lb!=0 ) bmin=lb;
                       if(ptrb!=0)
                      ptrb--;
                }
                debug(amin, bmin, "bahar");
                if(ptra!=0 ) ptra--;
                if(ptrb!=0) ptrb--;
                if(amin>bmin){
                    debug(amin, bmin);
                     asmall=false;
                     break;
                }
                if( bmin<amin) break;
                if(amin==bmin){
                    amin=0;bmin=0;
                }
            }





            // for (int i = qca.size()-1; i >=0 ; i--)
            // {
            //     int la=qca[i];
            //     int lb=qcb[i];
            //     if(la==-1 and lb==-1){
            //         ca++;cb++;
            //          debug(amin,bmin);
            //         if(amin==bmin)
            //         {      
            //         }
            //         else{
            //            debug("here");
            //             if(amin<bmin ) asmall=false;
            //             break;
            //         }
            //     }
            //     else{
            //     if(la<amin and la!=0 ) amin=la;
            //     if(lb<bmin and lb!=0 ) bmin=lb;
            //     }
            // }
            if (asmall)
                return false;
            else
                return true;
        }
        else return a.f.f<b.f.f;
    }
};

void bfs(int v, vl adj[], vl &height,vl & height2, vl &par,vl& val,ll x){

    ll sum =0;
    queue<ll> qu;

    priority_queue < pair<pl,ll> , vector<pair<pl,ll>> ,mycomp> pq;
    qu.push(1);
    val[v]=x%mod;
    while(!qu.empty()){
        int v= qu.front();
        qu.pop();
        for (auto i : adj[v])
        {
            if(i!=par[v]){
                qu.push(i);
                pq.push({{height[i],i},height2[i]});
            }
        }
        int count=1;
        while(!pq.empty()){
             pair<pl,ll> t=pq.top();
             val[t.f.sec]=(val[v]*count) %mod;
             count++;
             pq.pop();
        }
    }

}

void init( int n){
    for (int i = 0; i < n+1; i++)
    {
        adj[i].clear();
        height2[i]=0;
        par[i]=-1;
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
        ll n, x;
        cin >> n >> x;
        init( n);
        vl height(n + 1, 0);
      
        
        vl val(n+1,0);
        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        dfs(1, adj, height, par, -1);
        dfs2(1, adj, height2, par, -1);
        debug(height);
        // debug(height, par,height2);
        bfs(1, adj, height,height2, par,val,x);
        ll ans=0;
        for (int i =1; i < n+1; i++)   
        {
            ans+=val[i];
            ans%=mod;
        }
        debug(val);
        cout<<ans<<"\n";
    }

    return 0;
}