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


ll gans(int bits[]){
    ll ans=0;
      for (int i = 0; i < 32; i++)
      {
          if(bits[i]>=1){
              ans+=pow(2,31-i);
          }
      }
      return ans;
}


int main(){
    int t;
    cin>>t;
    while(t--){
      int n,q;
      cin>>n>>q;
      int arr[n];
      int hold[n];
      for (int i = 0; i < n; i++)
      {
          cin>>arr[i];
          hold[i]=arr[i];
      }
      int bits[32]={0};
    //   debug("0>>1",0>>1);
      for (int i = 0; i < n; i++)
      {     
            bits[31]+=1&(arr[i]);
            // debug(arr[i]&1);

          for (int j = 1; j <=31; j++)
          {   
              bits[31-j]+=(1&(arr[i]>>1));
              arr[i]=arr[i]>>1;
            //   debug(arr[i],(arr[i]>>1),1&(arr[i]>>1));
          }
          
      }
    //   for (int i = 0; i < 32; i++)
    //   {
    //       cout<<bits[i]<<" ";
    //   }
    
      cout<<gans(bits)<<'\n';
      
      for (int i = 0; i < q; i++)
      {
          int x,v;
          cin>>x>>v;
          int ini=hold[x-1];

          bits[31]-=1&(ini);
          for (int j = 1; j <=31; j++)
          {   
              bits[31-j]-=(1&(ini>>1));
              ini=ini>>1;
            //   debug(arr[i],(arr[i]>>1),1&(arr[i]>>1));
          }
    //         for (int i = 0; i < 32; i++)
    //   {
    //       cout<<bits[i]<<" ";
    //   }

          hold[x-1]=v;
          int fin=hold[x-1];
         bits[31]+=1&(v);
          for (int j = 1; j <=31; j++)
          {   
              bits[31-j]+=(1&(v>>1));
              v=v>>1;
            //   debug(arr[i],(arr[i]>>1),1&(arr[i]>>1));
          }
            // cout<<"\n";
    //       for (int i = 0; i < 32; i++)
    //   {
    //       cout<<bits[i]<<" ";
    //   }

         cout<<gans(bits)<<"\n";
          
      }
      
      
      
    }

  return 0;
  }