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
 template <typename T>
 class Graph{
	 
	 map<T,list<T>> l;
	 public: 
		void addEdge(T x ,T y )
	 { 	
		 l[x].pb(y);
	 }
	 
	void bfs (T src){
		map <T,bool > visited;
		queue <T> q;
		q.push(src);
		visited[src]=true;
		while(!q.empty()){
			T nbr=q.front();
			q.pop();
			cout<<nbr<<"-->";
			for(auto x : l[nbr]){
				if(visited[x]!=true){
				q.push(x);
				visited[x]=true;
			}
			}
		}
	}
	void bfs2( T src){
		map <T,int > dist;
		for(auto xp: l){
		T node = xp.f;
		dist[node]=INT_MAX;
		}
		queue <T> q;
		
		dist[src]=0;
		q.push(src);
		while(!q.empty()){
			T nbr=q.front();
			q.pop();
			
			for(auto x : l[nbr]){
				
				if(dist[x]==INT_MAX){
				q.push(x);
				dist[x]=dist[nbr]+1;
				
			}
			}
		}
		
		for(auto npair : l){
		T node= npair.f;
		cout<<"node "<<node<<"-->"<<dist[node]<<endl;
		}
	
	
	}
	void dfs2(T node,map<T,bool>& vis){
		vis[node]=true;
		
		for(auto i : l[node]){
			if(!vis[i]){
			dfs2(i,vis);
			}
		}
	
	
	cout<<node<<"->";
	}
	
	
	void dfs1(){
		map<T,bool> visited;
		for(auto i : l){
			T node=i.first;
			visited[node]=false;
		}
		int i=0;
		for(auto src : l){
			T node=src.f;
			
			if(!visited[node]){
				cout<<"Component"<<i++;
			dfs2(node,visited);
			cout<<endl;
		}
		}
		
	
	}
	void dfs2(T node,map<T,bool>& vis,list<T> &ord){
		vis[node]=true;
		
		for(auto i : l[node]){
			if(!vis[i]){
			dfs2(i,vis,ord);
			}
		}
	
		ord.push_front(node);
	}
	
	void dfstopological(){
	
	map<T,bool> visited;
	list<T>  ordering;
		for(auto i : l){
			T node=i.first;
			visited[node]=false;
		}
		int i=0;
		for(auto src : l){
			T node=src.f;
			
			if(!visited[node]){
				
			dfs2(node,visited,ordering);
			cout<<endl;
		}
		}
		cout<<endl;
		for(auto src : ordering){
		cout<<src<<",";
		
		}
		
	
	}
	
	
	
	void topologicalbfs(){
	T indegree[100000]={0};
	vector<T> ordered;
	queue<T> q;
	for(auto i : l){
	T node=i.f;
	for(auto j : l[node]){
		indegree[j]+=1;
	}
	}
	
	for(auto i : l){
	if(indegree[i.f]==0){
		q.push(i.f);
		ordered.pb(i.f);
	}
	}
	while(!q.empty()){
	T node=q.front();
	q.pop();
	for(auto i: l[node]){
		indegree[i]--;
		if(indegree[i]==0){
			q.push(i);
		ordered.pb(i);
		}
	}
	
	
	}
	for(auto i : ordered){
		cout<<i<<" , ";
	}

	
	
	
	}
	
	
	
	
	 
	 };
 
 int main(){
	Graph<int> g;
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(1,4);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(4,5);
	g.addEdge(2,5);
	
	g.bfs(0);
	g.dfs1();
	cout<<"\n Topological order \n";
	g.dfstopological();
	cout<<"\n BFS Topological \n";
	g.topologicalbfs();
	
	return 0;
}
 
 
