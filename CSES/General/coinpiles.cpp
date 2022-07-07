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
 
 
 //  let them be equal then if a and b are equal then only when a%3==0 or b%3==0 then they can both be 0
 // if they are not equal then to make them equal note , say a>b
 // a-2*steps=b*steps
 // steps=a-b;
 // therefore after a-b , both are equal , now check for %3.


// if(2*a>=b and 2*b>=a) and (a+b)%3==0 then yes else no.
int main(){
    int t;
    cin>>t;
    while(t--){
      int a,b;
      cin>>a>>b;
      int ae=(a%2==0);
      int be=(b%2==0);
    //   if(a<=2 or b<=2){
    //       if(a==2)
    //   }
      int dif=abs(a-b);
      int dife=(dif%2==0);
      if(a>b){
        if(b<dif) cout<<"NO\n";
        else {
            int newa=a-2*dif;
            int newb=b-dif;
            if(newa==newb){
                if(newa%3==0){
                    cout<<"YES\n";
                }
                else cout<<"NO\n";
            }
        }
      }
      else {
          if(a<dif) cout<<"NO\n";
        else {
            int newa=a-dif;
            int newb=b-2*dif;
            if(newa==newb){
                if(newa%3==0){
                    cout<<"YES\n";
                }
                else cout<<"NO\n";
            }
        }
      }
        
    }
 
  return 0;
  }