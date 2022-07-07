/**
 * author: Bhavesh
**/
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
#define cinarr(ar,n) for(int i=0;i<n;i++){cin>>ar[i];}
#define car(ar,n) for(int i =0;i<n;i++){cout<<ar[i]<<" ";}
#define forn(i,a,b) for (int i = (a); i < ll(b); ++i)
#define fo(i,a) forn(i,0,ll(a))
#define rforn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ro(i,a) rforn(i,0,a)
#define trav(a,x) for (auto& a: x)
 
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define sec second
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
const ll INF = 1e18;
 
 
 
int main(){
    int n,m;
    cin>>n>>m;
    int grid[n][m];
    int starti=-1,startj=-1;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
           char c=s[j];
            if(c=='#'){ grid[i][j]=-1; }
            else if(c=='.') grid[i][j]=0;
            else if(c=='A') {grid[i][j]=1; starti=i,startj=j;}
            else grid[i][j]=2;
        }
    }
    queue<pi> qu;
    vector <vi> monstertime(n,vi(m,1e9));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                qu.push({i,j});
                monstertime[i][j]=0;
            } 
            if(grid[i][j]==-1){
              
                monstertime[i][j]=-1;
            }
        }
    }
    int dx[]={0,1,0,-1};
    int dy[]={1,0,-1,0}; //R D L U;
    while(!qu.empty()){
        pi top=qu.front();
        qu.pop();
        for(int i=0;i<4;i++){
            int nexti=top.f+dx[i];
            int nextj=top.sec+ dy[i];
            if(nexti<0 or nextj<0 or nexti>=n or nextj>=m) continue;
            else if(monstertime[nexti][nextj]==1e9){
                qu.push({nexti,nextj});
                monstertime[nexti][nextj]=monstertime[top.f][top.sec]+1;
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout<<monstertime[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // qu.push({starti,startj});
    queue <pair<pi,int>> qu2;
    qu2.push({{starti,startj},0});
    vector<vi>  path (n,vi (m,-1));
    // int timer=0;
    int endi=-1,endj=-1;
    bool ans=false;
    vector<vi> vis(n, vi(m,0));
    while(!qu2.empty()){
        pair<pi,int> top=qu2.front();
        if(top.f.f==0 or top.f.sec==0 or top.f.f==n-1 or top.f.sec==m-1) {
            debug("ans ",top);
            ans=true;
            endi=top.f.f; endj=top.f.sec;
            break;
        }
        vis[top.f.f][top.f.sec]=1;
        debug(top);
        qu2.pop();
        for(int i=0;i<4;i++){
            int nexti=top.f.f+dy[i];
            int nextj=top.f.sec+dx[i];
            // debug(i, monstertime[nexti][nextj]);
            if(nextj<0 or nexti<0 or nexti>=n or nextj>=m) continue;
            else if(grid[nexti][nextj]==0 and vis[nexti][nextj]==0 and monstertime[nexti][nextj] >top.sec+1 ){
              
                qu2.push({{nexti,nextj},top.sec+1});
                path[nexti][nextj]=i;
            }
        }
    }
    
    debug(ans);
    if(ans){
        string stans="";
        while(endi!=starti or endj!=startj){
            // debug(stans,endi,endj,starti,startj);
            int dir=path[endi][endj];
            if(dir==0)stans+="D";
            if(dir==1) stans+="R";
            if(dir==2) stans+="U";
            if(dir==3) stans+="L";
            endi-=dy[dir];
            endj-=dx[dir];
        }

        reverse(stans.begin(),stans.end());
        cout<<"YES"<<"\n";
        cout<<stans.length()<<"\n";
        cout<<stans;
    }
    else cout<<"NO";



  return 0;
  }