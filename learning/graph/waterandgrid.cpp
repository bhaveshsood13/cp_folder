

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

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int arr[10000][10000];
int counter=0;
int floodfill(int arr[][10000],int visited[][10000],int i, int j,int m ,int n,int count){
    // debug(i,j,count);
    if(i<0||j<0|| i>=m || j>=n){
        return count;
    }
    if(arr[i][j]!=0){
        
        return count;
        
    }
    if(visited[i][j]!=0){
        
        return count;
        
    }
    visited[i][j]=1;
    if(i==0 or j==0 or i==m-1 or j==n-1){
        counter=0;
        return 0;
    }
    counter++;
    for(int k=0;k<4;k++){
      count=floodfill(arr,visited, i+dx[k],j+dy[k],m,n,count+1);
      
    }
    return counter;
}

int main(){
    int m,n;
    cin>>m>>n;

    int visited[m][10000]={0};

    for(int i =0;i<m ;i++){
        string s;
        cin>>s;
        for (int j = 0; j < n; j++)
        {   
            if(s[j]=='*'){
            arr[i][j]=1;
            visited[i][j]=-1;
            }
            else arr[i][j]=0;
        }
        
    }
    // for(int i =0;i<m ;i++){
        
    //     for (int j = 0; j < n; j++)
    //     {   
    //         cout<<arr[i][j];
    //     }
    //     cout<<"\n";
        
    // }
    long long ans=0;;
    // int ans=floodfill(arr,visited,2,2,m,n,0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {   
            if(visited[i][j]==-1){
            continue;
        }
            else if(visited[i][j]!=1){
                counter=0;
                ans+=floodfill(arr,visited,i,j,m,n,0);
                debug(ans,i, j,counter);
            }
        }
        
    }
    
    cout<<ans<<"\n";
    for(int i =0;i<m ;i++){
        
        for (int j = 0; j < n; j++)
        {   
            cout<<visited[i][j];
        }
        cout<<"\n";
        
    }
  return 0;
  }