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
 


// Initially thought of binary search but couldn't find any good function
// Realised that median is the answer.
// In case of even number of elements it doesn't matter which one you choose n/2 or  n/2-1 both would give the same difference.


int main(){
    int n;
    cin>>n;
    vi v(n);
    int maxl=0;
 
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        maxl=max(maxl,v[i]);
    
    }
    sort(v.begin(),v.end());
    int X=-1;
    if(n%2==1)
    X= v[n/2];
    else X=v[n/2-1]; // even X=v[n/2] gives correct.
    ll sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=abs(v[i]-X);
    }
    cout<<sum;
    
  return 0;
  }


//    # For tooth A 
//    collision_points=[]
//    x1,y1=initialcordinates of A
//    x2,y2=finalcordinates of A
//    # we know equation of line path of A
//    for i in list_of_other_teeth :   
//         x3,y3=initialcordinates of i;
//         x4,y4=finalcordinates of i;
//         # we now know equation of line path of ith tooth
//         x5,y5= coordinate_of_collision #of i and A
//         if( x1<x5<x2 and y1<y5<y2):
//             collision_points.append((x5,y5))
        
//     # In the end we can sort collision_points list based on distance from x1,y1
//     # Preprocessing this for all 32 teeth wouldn't take much time , and we have the entire possible collision points with us stored in each tooth's state.





