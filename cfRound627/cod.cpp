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
 

 void f1(   string str, int k, int cur, string& max)
{
     
    char maxno = str[cur];
    if (k == 0)
        return;
 
    int n = str.size();

    for (int j = cur + 1; j < n; j++) {
        if (maxno < str[j])
            maxno = str[j];
    }

    if (maxno != str[cur])
        --k;
 
    for (int j = cur; j < n; j++) {
    
        if (str[j] == maxno) {
           
            
            if (str.compare(max) > 0)
                max = str;
            swap(str[cur], str[j]);
            f1(str, k,cur + 1, max);
            swap(str[cur], str[j]);
        }
    }
}
 





















void swapMax(string & arr, int target_position,
                      int current_position)
{
    int aux = 0;
    for (int i = current_position;i > target_position; i--) {
        aux = arr[i - 1];
        arr[i - 1] = arr[i];
        arr[i] = aux;
    }
}
void f1(string & arr, int length, int swaps){
    if (swaps == 0)
        return;
    for (int i = 0; i < length; i++) {
        int maxind = 0, max = INT_MIN;
        int limit = (swaps + i) > length ? length : swaps + i;
        for (int j = i; j <= limit; j++) {
            if ((arr[j]-48) > max) {
                max = (arr[j]-48);
                maxind = j;
            }
        }
        swaps -= (maxind - i);
        swapMax(arr, i, maxind);
        if (swaps == 0)
            break;
    }
}
string maxmiser(string input1,int input2){
    int n=input1.size();
    f1(input1,n,input2);
    return input1;
} 

int main(){
    cout<<maxmiser("1123",1);
 
  return 0;
  }