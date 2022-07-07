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
 
// tried with pq, but TLE as N^2 

// note bst is best.
 
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin>>arr[i];
//     }
//     priority_queue <int, vi , greater<int> > pq;
    
//     for (int i = 0; i < n; i++)
//     {
//         int cur=arr[i];
//         vi v;
//         while(!pq.empty() and pq.top()<=cur){
//             v.push_back(pq.top());
//             pq.pop();
//         }
//         if(!pq.empty()){
//             pq.pop();
//             pq.push(cur);
//         }
//         else {
//             pq.push(cur);
//         }
//         for (int j = 0; j < v.size(); j++)
//         {
//             pq.push(v[j]);

//         }
//         debug(v);
//         v.clear();
        
//     }
//    cout<<pq.size(); 
 
//   return 0;
//   }

//


//  Note to use bst - map and multiset available 
//4
// 5 5 3 4
// this gives wrong ans with map , as can't keep two of 5 ,
// multiset thus easier.

// OMG Great code for LIS .... just OMMGG
//       LIS
//      vi dp;
        // for(int i=0;i<nums.size();i++){
        //     int cur=nums[i];
        //     int pos=lower_bound(dp.begin(),dp.end(),cur)-dp.begin();
        //     if(pos<dp.size())
        //         dp[pos]=cur;
        //     else dp.push_back(cur);
            
        // }
        // return dp.size();
        // just change it to upper_bound here and you're good to go for this question.
// note tmwillian , uses simple vector and calls upper bound on it
int main () {
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    multiset<int > m;
    // map<int,int> m;

    int cnt=0;
    for (int i = 0; i < n; i++)
    {bool sf=true;;
        int cur=arr[i];
        if(m.size()>0) 
        {
            if(m.upper_bound(cur)!=m.end()){
                debug(cur,m.upper_bound(cur)==m.end());
                m.erase(m.upper_bound(cur));
                sf=false;
                // m[cur]=1;
                m.insert(cur);
            }  
        }
        if(sf){
        // m[cur];
        m.insert(cur);
        cnt++;}

    }
    debug(m);
    cout<<cnt;
    

    return 0;
}