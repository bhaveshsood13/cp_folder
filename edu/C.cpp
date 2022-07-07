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
 
 ll fi=0;
 bool check(ll x,int h,int c,int t){
	 if((double)(x*h+(x-1)*c)/(2*x-1)>=t) {debug(x,(double)(x*h+(x-1)*c)/(2*x-1));return true;}
	 else return false;
	 }
ll bs(int h, int c ,int tr)
 {	ll s=1;
	 int e=1000000001;
	 while(s<e){
		ll mid=(s+e)/2;
		debug(mid,s,e);
		if(check(mid,h,c,tr)){
			s=mid+1;
			fi=mid;
		}
		else{
		e=mid-1;
		}
	 
	 }
	 debug("fasd",(double)((tr-(double)((fi+1)*h+(fi)*c)/(2*fi+1))),(double)((double)((fi*h+(fi-1)*c))/(2*fi-1)-tr),"sfs",(double)(fi*h+(fi-1)*c)/(2*fi-1));
	 if((double)((tr-(double)((fi+1)*h+(fi)*c)/(2*fi+1)))<(double)((double)((fi*h+(fi-1)*c))/(2*fi-1)-tr)){
	 debug(fi,(double)(fi*h+(fi-1)*c)/(2*fi-1));
	 return 2*(fi+1)-1;
	 }
	 debug(fi,(double)((fi+1)*h+(fi)*c)/(2*fi+1));
	 return 2*fi-1;
	 }
 
 int main(){
	int t;
	cin>>t;
	while(t--){
		fi=0;
		int h,c,tr;
		cin>>h>>c>>tr;
		if(h==tr){
		cout<<1<<endl;
		continue;
		}
		if(tr<=(h+c)/2){
		cout<<2<<endl;
		continue;
		}
		else{
			//~ cout<<"here";
		ll j=bs(h,c,tr);
		
		cout<<j<<endl;
		}
		
	}
	return 0;
}
