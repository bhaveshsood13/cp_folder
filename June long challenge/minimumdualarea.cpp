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


bool mycomp(pi a, pi b){
    return a.sec<b.sec;
}

int main(){
    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      vector <pl> points;
      vl ally , allx;
      for (int i = 0; i < n; i++)
      {
          ll x, y;
          cin>>x>>y;
          points.pb({x,y});
          allx.pb(x);
          ally.pb(y);
      }
      
      
      sort(points.begin(),points.end());
      vl rmin(n+1,1e9),rmax(n+1,0);
       rmin[n-1]=points[n-1].second;
        rmax[n-1]=points[n-1].second;
      for (int i = n-2; i >=0; i--)
      {     
          if(points[i].second<rmin[i+1]){
              rmin[i]=points[i].second;
          }
          else rmin[i]=rmin[i+1];
          if(points[i].second>rmax[i+1]){
              rmax[i]=points[i].second;
          }
          else rmax[i]=rmax[i+1];
          
      }
      
      ll minarea=1e18;
      ll ymax=0,ymin=1e18;
      for (int i = 0; i < n-1; i++)
      {
          if(ymin>points[i].second){
              ymin=points[i].second;
          }
          if(ymax<points[i].second){
              ymax=points[i].second;
          }
          ll h1=ymax-ymin;
        
          ll maxy2=rmax[i+1];
          ll miny2=rmin[i+1];
          ll h2=maxy2-miny2;
          ll area1= (points[i].first-points[0].first)*h1;
          ll area2= (points[n-1].first-points[i+1].first)*h2;
          ll posarea=area1+area2;
          if(minarea>posarea){
              debug(1,posarea,minarea,area1,area2,i);
              minarea=posarea;
          }

      }
      sort(points.begin(),points.end(),mycomp);
       vl xrmin(n+1,1e9),xrmax(n+1,0);
       xrmin[n-1]=points[n-1].first;
        xrmax[n-1]=points[n-1].first;
      for (int i = n-2; i >=0; i--)
      {     
          if(points[i].first<xrmin[i+1]){
              xrmin[i]=points[i].first;
          }
          else xrmin[i]=xrmin[i+1];
          if(points[i].first>xrmax[i+1]){
              xrmax[i]=points[i].first;
          }
          else xrmax[i]=xrmax[i+1];
          
      }
      ll xmax=0,xmin=INT_MAX;
      for (int i = 0; i < n-1; i++)
      {
          if(xmin>points[i].first){
              xmin=points[i].first;
          }
          if(xmax<points[i].first){
              xmax=points[i].first;
          }
          ll w1=xmax-xmin;
     
          ll maxy2=xrmax[i+1];
          ll miny2=xrmin[i+1];
          ll w2=maxy2-miny2;
         
          ll area1= (points[i].sec-points[0].sec)*w1;
          ll area2= (points[n-1].sec-points[i+1].sec)*w2;
          ll posarea=area1+area2;
          debug(2,posarea,minarea,area1,area2);
          if(minarea>posarea){
              
              minarea=posarea;
              
          }

      }
      if(minarea==1e18) cout<<0<<"\n";
      else 
      cout<<minarea<<"\n";      
    }

  return 0;
  }