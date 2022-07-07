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
 
    // Think like we do the cycle detection in linked list..

 // When i looked at it , i tried binary search on somehow the answer, or try to find the minimum difference subsets of the array. ( but thats n^2)
 // if max > sum-max then 2*max is answer thats simple.
 // if sum > 2*max , this means while the time max element was being read by 1st person the other couldn't read all other books.
 // so whichever ones he could read he read them while 1'st was reading max. (lets say x books he could read with sum max)
 // so sum-max is left for him. while person 1 has sum-max left too. Now while he reads max, 1st person reads max amount too. 
 // so after 2*max time both persons are left with sum-max-max.  sum-2max  is left for both.
 // to read sum-2max it will take say sum-2max for 1 person , and total time would have been sum;
 // the other person would have read sum-2max too in that much time if no waiting ever. and we can be sure that there is no waiting always since we can rearrange the initial books

// while 1 was reading the max book , 2 would have finished some other book early, thus he would shift to some other book , and now while he was finishing that book 
// 1 would have completed max. and still left with some time, so he would start with other book , now 2 will read max ,till then left books would be read by 1 and extra time would have been used here .



 // sort the books based on reading times 
 // 1 2 3 4 5 6 7 8 9  
 // 9 9 9 9 9 9 9 9 9
 // 8 
 // 
 // 
 
int main(){
    int n;
    cin>>n;
    ll sum=0;
    vl arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    sort(arr.begin(),arr.end());
    cout<<max(sum, 2*arr[n-1]);

    
 
  return 0;
  }