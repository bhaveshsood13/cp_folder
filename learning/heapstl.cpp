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
 
 
 class process{
	
	 public:
	  int id;
	 int pri;
	 int start;
	 int left;
	 process(int id, int pri,int start,int left){
		this->id =id;
		this->pri= pri;
		this-> start=start;
		this-> left= left;
	
	 }
	 
	 
	 
	 };
	 
	 
struct comp{
	
	 bool operator()(process a, process b){
		 if(a.start==b.start)
{	return a.pri<b.pri;
	}	
	else 
	return a.start>b.start;
	 }
 };
 	 
struct comp2{
	
	 bool operator()(process a, process b){
	return a.pri<b.pri;
	 }
 };
 struct comp3{
	
	 bool operator()(process a, process b){
	return a.id>b.id;
	 }
 };
 
 
 
 
 int main(){
	 
	 
	
	 priority_queue <process,vector<process>,  comp > qu;
	 priority_queue <process,vector<process>,  comp2 > pq;
	priority_queue <process,vector<process>,  comp3 > fi;
	 
	 int t;
	 cin>>t;
	 int no=t;
	  //process p[t];
	 while(t--){
		 
		//int cmd;
		//cin>>cmd;
		
		//switch(cmd)
		//{
			//case 1: int x;
					//cin>>x;
					//qu.push(x);
					//break;
			//case 2: cout<<qu.top()<<endl; break;
			//case 3: qu.pop();break;
		//}
		//;
	//}
		 int id,s,p;
		 cin>>id>>s>>p;
		 qu.push(process(id,p,s,5));
	 }
	 
	 
	 ll gt=0;
	 
	ll com=0;

	 while (com<(no)) { 
		 //debug(com, no);
		 if(!qu.empty()){
        process p = qu.top(); 
        if(p.start==gt){
		pq.push(p);
		qu.pop();
		}}
		if(!pq.empty()){
		  process cur=pq.top();
		  pq.pop();
		   //cout<<"herere1 "<<cur.id<<" "<<cur.left<<" "<<gt<<endl;
		  cur.left-=1;
		  			  //cout<<"herere2 "<<cur.id<<" "<<cur.left<<endl;
		pq.push(cur);
		  if(cur.left<=0){
			  //cout<<"herere"<<cur.id<<" "<<cur.left;
			  cur.left=gt;
			  com++;
			  fi.push(cur);
			pq.pop();
		  }
		}
		gt++;
		
		
	}
	//cout<<fi.empty();
	
	 while(!fi.empty()){
	 process p=fi.top();
	 //cout<<endl;
	 cout<<p.left+1<<endl;
	 fi.pop();
	 
	 }
	 
	 
 
	 
	 
	 
	 
	 
	
	 
	return 0;
}
 
 
