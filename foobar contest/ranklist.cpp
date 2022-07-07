/**
 * author: Bhavesh
**/

#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db;
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
 
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL) 
#define cinarr(ar,n) for(int i=0;i<n;i++){cin>>ar[i];}
#define car(ar,n) for(int i =0;i<n;i++){cout<<ar[i]<<" ";}
#define forn(i,a,b) for (int i = (a); i < ll(b); ++i)
#define fo(i,a) forn(i,0,ll(a))
#define rforn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ro(i,a) rforn(i,0,a)
#define trav(a,x) for (auto& a: x)
 
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define rsz resize
#define ins insert
 
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second
 
ll mod = 1000000007;
inline ll fast_expo(ll base,ll power,ll modulo=mod){
    base%=modulo;
    if (base<0) base+=modulo;
    ll x=base,cnt=power,ans=1;
    while(cnt){
        if (cnt&1) ans=(ans*x)%modulo;
        x=(x*x)%modulo;
        cnt>>=1;
    }
    return ans;
}
 
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
//=========================CODE STARTS HERE=============================//
 
 class score{
     public:
     int ans;
     string ss;
     int rank;
     ll penalty;
     score(){
         ans=0;
         ss="";
         rank=0;
         penalty=0;
     };

 };

bool compare (score a, score b){
    if (a.ans>b.ans){
        return true;
    }
    else if(a.ans==b.ans){
        if(a.penalty<b.penalty){
            return true;
        }
        else return false;
    }
    else return false;
}

 int main(){
  
      int n,m;
      cin>>n>>m;
      unordered_map <string,int> team;
      int counter=0;
      score ar[n];
     
      for(int i=0;i<m;i++){
          string s;
          
          cin>>s;
          
        //   debug(team.find(s)==team.end());
          if(team.find(s)==team.end()){
              team[s]=counter;
              counter++;
          }
            // debug(11);
          int p;
          cin>>p;
          ar[team[s]].ss=s;
          ar[team[s]].ans+=1;
          ar[team[s]].penalty+=p;
          debug(team[s] , ar[team[s]].ss, ar[team[s]].ans,ar[team[s]].penalty);
          
      }
    sort(ar,ar+counter,compare);
    int pra=ar[0].ans;
    ll prp=ar[0].penalty;
    int ranker=0;
    int exrra=0;
    bool notthere=true;
    bool same=false;
    int co=-1;

    for(int i=0;i<n;i++){
       
       if(i>=counter){
           break;
       }
        
         if(ar[i].ans==pra and ar[i].penalty==prp){
             ar[i].rank=ranker;
             same=true;
             co++;
             debug(co ,i,ranker);
         }
         else{
             co=0;
             same=false;
             pra=ar[i].ans;
             prp=ar[i].penalty;
             ar[i].rank=++ranker;
         }
         if(ar[i].ss.compare("BhayanakMaut")==0){
             notthere=false;
             if(same)
            cout<<ar[i].rank+1<<endl;
            else 
            cout<<i+1<<endl;
        }
    }
    if(notthere){
        debug(co,22);

        cout<<counter+1<<endl;
    }

 

  return 0;
 } 