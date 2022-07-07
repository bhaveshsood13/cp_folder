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
 
 
 
int main(){
    int n,q;
    cin>>n>>q;
   vi   arr(n);
    int m[n+1];
    unordered_map<int, pair<int,int>> map;

    // map<int,int> m;  // note single array is enough , to store map;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        m[arr[i]]=i;
        map[arr[i]]={-1,-1};
    }
    for(int i=1;i<n+1;i++){
        if(i==n){
           map[i].first=m[i-1];
           map[i].second=-1;
        }
        else if(i==1){
        map[i].first=-1;
        map[i].second=m[i+1];
        }
        else {
        map[i].first=m[i-1];
        map[i].second=m[i+1];
        }
    }
    ll cnt=0;
    ll idx=n;
    for(int i=1;i<n+1;i++){
        if(m[i]<idx){
            cnt++;   
        } idx=m[i];
    }
    for(int i =1;i<n;i++){
        debug(i,map[i],arr[map[i].f]);
    }
    vi arra={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    // cout<<cnt;
    while(q--){
        int a,b;
        cin>>a>>b;
        int an=arr[a-1];
        int bn=arr[b-1];
        int af;
        if(an!=1)
        af=m[an-1];
        else af=-1;
        int as;
        if(an!=n)
        as=m[an+1];
        else as=-1;
        
        int bf;
        if(bn!=1)
        bf=m[bn-1];
        else bf=-1;
        int bs;
        if(bn!=n)
        bs=m[bn+1];
        else bs=-1;
        debug(af,as,bf,bs,arr[af],arr[as],arr[bf],arr[bs]);
        bool fa=false;

        debug(arra);
        debug(arr);
        if(af!=-1 and af>=b-1 and m[arr[a-1]]>af ){
            cnt++;
            debug(1,cnt);

        }
        else if(af!=-1 and af<=b-1 and m[arr[a-1]]<af ){
            cnt--; fa=true;
            debug(2,cnt);

        }

        if(as!=-1 and as>=b-1 and m[arr[a-1]]>as ){
            cnt--; 
            debug(3,cnt);

        }
       else if(as!=-1 and as<=b-1 and m[arr[a-1]]<as ){
            cnt++;
            debug(4,cnt);

        }
        
        if(bf!=-1 and bf>=a-1 and m[arr[b-1]]>bf ){
            cnt++;
            debug(5,cnt);

        }
        else if(bf!=-1 and bf<=a-1 and m[arr[b-1]]<bf ){
            cnt--;fa=true;
            debug(6,cnt);

        }
        if(bs!=-1 and bs>=a-1 and m[arr[b-1]]>bs ){
            cnt--;fa=false;
            debug(7,cnt);

        }
        else if(bs!=-1 and bs<=a-1 and m[arr[b-1]]<bs ){
            cnt++;
            debug(8,cnt);
        }
        
        if(abs(arr[a-1]-arr[b-1])==1){
            int ia=m[arr[a-1]];
            int ib=m[arr[b-1]];
            if(an>bn){
                if(ia>ib) cnt--;
                else cnt++;
            }
            else {
                if(ia>ib) cnt++;
                else cnt--;
            }
        }

        m[arr[a-1]]=b-1;
        m[arr[b-1]]=a-1;
        swap(arr[a-1],arr[b-1]);
        cout<<cnt<<"\n";
    }   
 
  return 0;
  }