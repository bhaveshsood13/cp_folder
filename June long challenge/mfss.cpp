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
    //  ios_base::sync_with_stdio(false);
    // cin.tie(NULL);   
    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      int arr[n];
      for (int i = 0; i < n; i++)
      {
          cin>>arr[i];
      }
      ll maxans=-INT_MAX;
 
     map <vector<int> , int > m;
      for (int i = 0; i < n; i++)
      {  
          for(int j=i;j<n;j++){
            //   ll ans=0;
            //   ll sum=0;
             vector<int> a;
                for(int k=i;k<=j;k++){
                   
                    // sum+=arr[k];
                    a.pb(arr[k]);
                }
            
               if(m.find(a) == m.end()){m[a] = 1;}

               else{m[a]++;}
            //    debug(a,m[a]);
               a.clear();
            //  ans =sum*m[a];
          }
      }

      for(int i=0;i<n;i++){
          

          for(int j=i;j<n;j++){
          vi b;
          ll sum=0;
          ll ans=0;
          for (int k = i; k <=j; k++)
          { 
              b.pb(arr[k]);
              sum+=arr[k];
          }
          int aa=m[b];
          
        ans=sum*aa;
        // debug(b,aa,sum,ans,maxans);
         maxans=max(ans,maxans);
            
          }
      }


      cout<<maxans<<"\n";
      
    }

  return 0;
  }