#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <utility>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cassert>
#include <sstream>
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
 
 int main(){
	 
	int v[]={1,2,3,4,5,6};
	 int key;
	 cin>>key;
	 //find
	 
	 auto it=find(v,v+6,key);
	 cout<<endl<<it;
			//to get the index
	cout<<endl<<it-v;
			// if not present then find returns index n
	vi vv{1,23,4,55,5};
	auto cit= find(vv.begin(),vv.end(),key);
	cout<<endl<<cit-vv.begin()<<endl;
	 
	 
	 //binary search
	
	
	 int are[]={1,2,3,4,56,66};
	 bool present = binary_search(are,are+6,key);
	 if(present){
	 cout<<"Element present ";
		// to get lower bound of it;
		auto lb=lower_bound(are,are+6,key);
		//similarly upperbound
		// to get freq do up-lb;
				cout<<"present at lowest index"<<lb-are;
	 }
	 
	 
	 //sort
		//sort (st,end,comparator)  - it sorts from [st,end);
	 
	 //Rotate and next permutations
	 int arr[]={1,2,3,4,5,6};
	 rotate(arr,arr+3,arr+6);
	 for(auto i : arr){
	 cout<<i<<",";
 } cout<<endl;
  
		next_permutation(arr,arr+6);
	 
	 for(auto i : arr){
	 cout<<i<<",";
 }
 
 
 ////some more methods;
 
 cout<<"MORE METHODS SHOWN: "<<endl<<endl;
 int a=10,b=20;
 swap(a,b);
 
 cout<<"MAx "<<max(a,b)<<endl<<"min "<<min(a,b);
 
 
 //reversing a thing
 int s[]={1,2,3,4,5};
 int n=sizeof(s)/sizeof(2);
 reverse(s,s+n);
 
	 for(auto i : s){
	 cout<<i<<",";
 }
 
 
	 return 0;
	 }
 
 
