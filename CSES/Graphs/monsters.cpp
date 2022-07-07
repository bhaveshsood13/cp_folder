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
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<grid[i][j];
    //     }
    //     cout<<"\n";
    // }
    
    queue<pi> qu;
    vector<vector<int>> vis(n,vi(m,0));
    vector<vector<int>> par(n,vi(m,0));
    bool ans=false;
    int dx[]={0,1,0,-1};//L D R U
    int dy[]={-1,0,1,0};

    for(int i=0;i<n;i++){
        if(grid[i][0]==0 and vis[i][0]!=1 and !ans){
            // debug("i ",i,0);
            bool fl=true;
            qu.push({i,0});
            while(!qu.empty() and fl){
                pi top=qu.front();
                vis[top.f][top.sec]=1;
                qu.pop();
                for(int i=0;i<4;i++){
                    int nexi=top.f+dx[i];
                    int nexj=top.sec + dy[i];
                    if(nexi<0 || nexj<0 || nexi>=n || nexj>=m){

                    }
                    else{
                       if(grid[nexi][nexj]==2){
                            ans=false;
                            fl=false;
                            while(!qu.empty()){
                                qu.pop();
                            }
                          
                            // debug("reached monster",top);
                            break;
                        }
                        else if(grid[nexi][nexj]==1){
                             vis[nexi][nexj]=1;
                            par[nexi][nexj]=i;
                            // debug("reached ans",top);
                            ans=true;
                             while(!qu.empty()){
                                qu.pop();
                            }
                            break;
                        }
                        if(grid[nexi][nexj]==0 and vis[nexi][nexj]==0){
                            qu.push({nexi,nexj});
                            vis[nexi][nexj]=1;
                            par[nexi][nexj]=i;
                        }
                    }
                }
            }
        }
    }
    if(!ans){
        // cout<<"here";
        vector<vector<int>> vis(n,vi(m,0));
        for(int i=0;i<n;i++){
            vector<vector<int>> vis(n,vi(m,0));
        if(grid[i][m-1]==0 and vis[i][m-1]!=1 and !ans){
            // debug("i ",i,m-1);
            bool fl=true;

            qu.push({i,m-1});
            while(!qu.empty() and fl ){
                pi top=qu.front();
                vis[top.f][top.sec]=1;
                qu.pop();
                for(int i=0;i<4;i++){
                    int nexi=top.f+dx[i];
                    int nexj=top.sec + dy[i];
                    if(nexi<0 || nexj<0 || nexi>=n || nexj>=m){

                    }
                    else{
                        if(grid[nexi][nexj]==2){
                            ans=false;
                            fl=false;
                            while(!qu.empty()){
                                qu.pop();
                            }
                          
                            // debug("reached monster",top);
                            break;
                        }
                        else if(grid[nexi][nexj]==1){
                             vis[nexi][nexj]=1;
                            par[nexi][nexj]=i;
                            // debug("reached ans",top);
                            ans=true;
                             while(!qu.empty()){
                                qu.pop();
                            }
                            break;
                        }
                        if(grid[nexi][nexj]==0 and vis[nexi][nexj]==0){
                            qu.push({nexi,nexj});
                            vis[nexi][nexj]=1;
                            par[nexi][nexj]=i;
                        }
                    }
                }
            }
        }
    }
    }
    if(!ans){

        for(int i=0;i<m;i++){
            vector<vector<int>> vis(n,vi(m,0));
        if(grid[0][i]==0 and vis[0][i]!=1 and !ans){
            // debug("i ",0,i);
            bool fl=true;

            qu.push({0,i});
            while(!qu.empty() and fl){
                pi top=qu.front();
                vis[top.f][top.sec]=1;
                qu.pop();
                for(int i=0;i<4;i++){
                    int nexi=top.f+dx[i];
                    int nexj=top.sec + dy[i];
                    if(nexi<0 || nexj<0 || nexi>=n || nexj>=m){

                    }
                    else{
                       if(grid[nexi][nexj]==2){
                            ans=false;
                            fl=false;
                            while(!qu.empty()){
                                qu.pop();
                            }
                          
                            // debug("reached monster",top);
                            break;
                        }
                        else if(grid[nexi][nexj]==1){
                             vis[nexi][nexj]=1;
                            par[nexi][nexj]=i;
                            // debug("reached ans",top);
                            ans=true;
                             while(!qu.empty()){
                                qu.pop();
                            }
                            break;
                        }
                        if(grid[nexi][nexj]==0 and vis[nexi][nexj]==0){
                            qu.push({nexi,nexj});
                            vis[nexi][nexj]=1;
                            par[nexi][nexj]=i;
                        }
                    }
                }
            }
        }
    }
    }
    if(!ans){
        for(int i=0;i<m;i++){
            vector<vector<int>> vis(n,vi(m,0));
        if(grid[n-1][i]==0 and vis[n-1][i]!=1 and !ans){
            debug("i ",n-1,i,ans);
                        bool fl=true;

            qu.push({n-1,i});
            while(!qu.empty() and fl){
                pi top=qu.front();
                vis[top.f][top.sec]=1;
                qu.pop();
                for(int i=0;i<4;i++){
                    int nexi=top.f+dx[i];
                    int nexj=top.sec + dy[i];
                    if(nexi<0 || nexj<0 || nexi>=n || nexj>=m){

                    }
                    else{
                        if(grid[nexi][nexj]==2){
                            ans=false;
                            fl=false;
                            while(!qu.empty()){
                                qu.pop();
                            }
                          
                            // debug("reached monster",top);
                            break;
                        }
                        else if(grid[nexi][nexj]==1){
                             vis[nexi][nexj]=1;
                            par[nexi][nexj]=i;
                            // debug("reached ans",top);
                            ans=true;
                             while(!qu.empty()){
                                qu.pop();
                            }
                            break;
                        }
                        
                       
                        if(grid[nexi][nexj]==0 and vis[nexi][nexj]==0){
                            debug(nexi,nexj,grid[nexi][nexj]);
                            qu.push({nexi,nexj});
                            vis[nexi][nexj]=1;
                            par[nexi][nexj]=i;
                        }
                    }
                }
            }
        }
    }
    }
    if(ans){
    cout<<"YES\n";
    int nexi=starti;
    int nexj=startj;
    // debug(nexi,nexj,par[nexi][nexj]);
    string path;
    while(nexi!=0 and nexj!=0 and nexi!=n-1 and nexj!=m-1){
        // debug(nexi,nexj);
        int dir=par[nexi][nexj];
        if(dir==0) path+="R";
        else if (dir==1)path +="U";
        else if (dir==2) path+="L";
        else path+="D";
        nexi-=dx[dir];
        nexj-=dy[dir];
    }
    // reverse(path.begin(),path.end());
    cout<<path.length()<<"\n";
    cout<<path;
    }
    else cout<<"NO";


  return 0;
  }