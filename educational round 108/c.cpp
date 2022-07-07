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
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      vector<vl> mat(n+1);
      vi utox(n);
      for (int i = 0; i < n; i++)
      {
          int x;
          cin>>x;
          utox[i]=x;
      }
      for (int i = 0; i < n; i++)
      {
          int x;
          cin>>x;
          int u=utox[i];
          mat[u].pb(x);
      }
    
      for (int i = 0; i <= n; i++)
      {
          sort(mat[i].begin(),mat[i].end(),greater<ll>());
      }
      debug(mat);
      vector<vl> prefix;
        int maxsize=0;
        int ptr=0;
        unordered_map<int,int> ptrtoi;
      for (int i = 0; i <= n; i++)
      {     
          if(mat[i].size()>0){
          prefix.pb(vl(0));
          ptrtoi[ptr]=i;
          debug("hello");
          for (int j = 0; j < mat[i].size(); j++)
          {     
              prefix[ptr].pb(0);
          }
          ptr++;
          }

          if(mat[i].size()>maxsize){
              maxsize=mat[i].size();
          }
      }
      debug("here",prefix,ptrtoi);


       for (int i = 0; i < ptr; i++)
      {     
        
          prefix[i][0]=mat[ptrtoi[i]][0];
          debug(mat[ptrtoi[i]][0],ptrtoi[i]);
          for (int j = 1; j < mat[ptrtoi[i]].size(); j++)
          {     
              prefix[i][j]+=prefix[i][j-1]+mat[ptrtoi[i]][j];
          }
    
      }
      
      debug(prefix);
        debug(mat);
    //   debug(mat);
      
      vl ans(n);
    //   for (int k = 1; k <= n; k++)
    //   {
    //       ll sum=0;
    //       if( k==1 or ans[ans.size()-1]!=0)
    //       for (int i = 0; i < ptr; i++)
    //       { 
    //             int rem=prefix[i].size()%k;
    //             int index=prefix[i].size()-rem-1;
    //             if(index>=0)
    //             sum+=prefix[i][index];
    //         //   debug(rem,index,i,sum,prefix[i][index]);
    //       }
    //       ans.pb(sum);

    //   }
    for (int i = 0; i < ptr; i++)
    {
        for (int k = 1; k <= int(prefix[i].size()) ; k++)
        {   
            int rem=prefix[i].size()%k;
            int index=prefix[i].size()-rem-1;
            if(index>=0)
            ans[k-1]+= prefix[i][index];
        }
        
    }
    

      for (int i = 0; i < n; i++)
      {
          cout<<ans[i]<<" ";
      }
      cout<<"\n";
      
      
      
    }

  return 0;
  }