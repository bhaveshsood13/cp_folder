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
 

// approach is simple keep a iterator on mid on the set and keep updating mid on each window.

// better to add the window first in set, maintaining window size through the set only.

// trick is to think about the element which will leave the window
// what to do about that , since it could be anywhere in the sorted window.

int main(){
    int n,k;
    cin>>n>>k;
    vi nums(n);
    cinarr(nums,n);
    multiset<int> window(nums.begin(), nums.begin() + k);
  
    auto mid = next(window.begin(), k / 2);
      if(k%2==0){
        mid--;
    }
    vector<double> medians;
    for (int i=k; i<n; i++) {

        // Push the current median.
        medians.push_back((double(*mid)));

        // If all done, return.
      
            
        // Insert nums[i].
        window.insert(nums[i]);
        if (nums[i] < *mid)
            mid--;

        // Erase nums[i-k].
        if (nums[i-k] <= *mid)
            mid++;
        window.erase(window.lower_bound(nums[i-k]));
    }
    medians.push_back((double(*mid)));
    // multiset <int> s;
    // s.insert(arr.begin(),arr.begin()+k);
    
    // auto mid= next(s.begin(),k/2);
    // if(k%2==0){
    //     mid--;
    // }
    // vi ans;
    // ans.push_back(*mid);
    // for (int i = k; i < n; i++)
    // {   
    //     int cur=arr[i];
    //     s.insert(cur);
    //     bool big=false,small=false;
    //     if(cur>=*mid){
    //         mid++;
    //         big=true;
    //     }
    //     else{
    //         mid--;
    //         small=true;
    //     }
    //     //  debug(1,s,i,*mid);
    //     int rem=arr[i-k];
    //     if(rem >= *mid and big ){
    //         if(!(rem==*mid and s.count(rem)>1))
    //         mid--;
    //     }
    
    //     if(rem <= *mid and small){
    //         if(!(rem==*mid and s.count(rem)>1))
    //             mid++;
    //         }
        
    
    //     // debug(*mid);///
       
    //     s.erase(s.find(rem));
    //     //  debug(s,i,*mid);
    //     ans.push_back(*mid);
    // }
    for(int i =0;i<medians.size();i++){ 
        cout<<medians[i]<<" ";
    }
    

    return 0;
}
// int main(){
//     int n,k;
//     cin>>n>>k;
//     vi arr(n);
//     cinarr(arr,n);

//     multiset <int> s;
//     int ps=0,ng=0;
//     int hf=k/2;
//     vi ans;
//     int len=1;
//     s.insert(arr[0]);
//     auto it =s.begin();
//     for (int i = 1; i < n; i++)
//     {
//         if(len<k){
//             s.insert(arr[i]);
//             if(arr[i]>=*it){
//                 ps++;
//                 if(ps>hf){
//                     it++;
//                     ps--;
//                 }
//             }
//             else{
//                 ng++;
//                 if(ng>hf){
//                     it--;
//                     ng--;
//                 }
//             }
//         }
//         else {
//             s.insert(arr[i]);
//             if(arr[i]>=*it){
//                 ps++;
//                 if(ps>hf){
//                     it++;
//                     ps--;
//                 }
//             }
//             else{
//                 ng++;
//                 if(ng>hf){
//                     it--;
//                     ng--;
//                 }
//             }
//             int rem=i-k;
//             auto it2=s.find (arr[rem]);
//             s.erase ( it2 );  
//             if(arr[rem]>=*it){
//                 ps--;
//                 if(ps<hf){
//                     it--;
//                     ps++;
//                 }
//             }
//             else{
//                 ng--;
//                 if(ng<hf){
//                     it++;
//                     ng++;
//                 }
//             }
//         }
//         ans.push_back(*it);
//     }
//     debug(ans);
 
//   return 0;
//   }