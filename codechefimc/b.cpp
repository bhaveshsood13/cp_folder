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

double polyarea(float n, double a)
{
    // Side and side length cannot be negative
    if (a < 0 && n < 0)
        return -1;
 
    // Area
    // degree converted to radians
    double A = (a * a * n) / (4 * tan((180 / n) * 3.14159265359 / 180));
 
    return A;
}
double cal_cos(float n)
{
    float accuracy = 0.0000001, x1, denominator, cosx, cosval;
 
    // Converting degrees to radian
    n = n * (3.142 / 180.0);
 
    x1 = 1;
 
    // Maps the sum along the series
    cosx = x1;
 
    // Holds the actual value of sin(n)
    cosval = cos(n);
    int i = 1;
    do {
        denominator = 2 * i * (2 * i - 1);
        x1 = -x1 * n * n / denominator;
        cosx = cosx + x1;
        i = i + 1;
    } while (accuracy <= fabs(cosval - cosx));
 
    return cosx;
}
double halfside(int n){
    double interiorAngle = (n - 2) * 180 / n;
//    interiorAngle = interiorAngle * (3.142 / 180.0);
    double cosan=cal_cos(interiorAngle);
    //  cout<<"interior"<<interiorAngle<<" "<<cosan;
    return sqrt((0.5 * 0.5) + (0.5 * 0.5) - 2 * 0.5 * 0.5 * cosan);
}

int main(){
    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      double l2=halfside(n);
      double ao=polyarea(n,1);
      double a2=polyarea(n,l2);
      double r=a2/ao;
      float rr=round(r*100)/100;
    //   cout<<"R"<<rr;
      double d=(1-rr)/rr;
    //   int d=round(dd);

      double ans= d*rr/((1-rr)*(1-rr));
      debug(ao,a2,rr, d, ans);
      cout<<setprecision(3)<<ans<<endl;
    // cout<<halfside(n)<<" ";  
    // cout<<polyarea(n,2)<<" ";
    // cout<<polyarea(n,halfside(n))<<" ";
    // cout<<polyarea(n,halfside(n))/polyarea(n,2);
    }
    
  return 0;
  }