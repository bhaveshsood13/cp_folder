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
 #define cinarr(ar,n) for(int i=0;i<n;i++){cin>>ar[i];}
#define car(ar,n) for(int i =0;i<n;i++){cout<<ar[i]<<" ";}
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
 
 
 
 
 
 void upheapify(vi &v,int n){
	 //here n is the index of upheapifying;
	 if(n==0){
	 return;
	 }
	 
	 if(v[n]<v[(n-1)/2]){
	 return;
	 }
	 else if(v[n]>v[(n-1)/2]){
	 swap(v[n],v[(n-1)/2]);
	 upheapify(v,(n-1)/2);
	 
	 
	 }
	 
	 }

	void downheapify(vi & v, int idx,int n ){
		int idxleft=2*idx +1;
		int idxright=idxleft+1;
		
		//debug(n)	;
		if(idxleft >=n and idxright>=n){
		return;
		}
		else if(idxright<n){
			int valleft=v[idxleft];
			int valright=v[idxright];
			if(valleft>valright){
				if(v[idx]<valleft){
				swap(v[idx],v[idxleft]);
				downheapify(v,idxleft,n);
				}}
			if(valleft<=valright){
				if(v[idx]<valright){
				swap(v[idx],v[idxright]);
					downheapify(v,idxright,n);
				}}
		}
		else {int valleft=v[idxleft];
			if(v[idx]<valleft){
				swap(v[idx],v[idxleft]);
				downheapify(v,idxleft,n);
			}
		}
		}
	
	void deletepeek(vi &v)
	 {
		swap(v[0],v[v.size()-1]);
		v.pop_back();
		downheapify(v,0,v.size());
	
	}
 
 
 void insert(vi &v , int x){
	 v.pb(x);
	 upheapify(v,v.size()-1);
	 
	 }
	 
	 
	 //O(n)way to make heap
	
	//void buildheap(vi &v,int n){
		
		//for(int i=n-1;i>=0;i--){
			
			//downheapify(v,i);
		//}
	
		//}
 
 
  
 
 
 
 
 
 
 
 
 int main(){
	int  n;
	cin>>n;
	vector <int> v;
	ll k,sum;
	
	
	fo(i,n){
	int cmd;
	cin>>cmd;
	insert(v,1);
	switch(cmd){
		case 1: int x;
				cin>>x;
                    insert(v,x);
                        break;
                case 2:
						cout<<v[0]<<endl;
                    break;
                case 3: deletepeek(v);break;
		
		
	}	
	}

	 
	 
	 
	 
	 
	 
	 
	return 0;
}
 
 
