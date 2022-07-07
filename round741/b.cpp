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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        string no;
        cin>>no;
        map <int,int> m;
        bool check1=false;
        bool check2=false;
        int nocheck2=-1;
        int nocheck1=-1;
        for (int i = 0; i < no.size(); i++)
        {   
            int x=no[i]-'0';
            if(x==1 or x==4 or x==6 or x==8 or x==9){
                nocheck1=x;
                check1=true;
               break;
            }
            m[x]++;
            if(m[x]==2){
                check2=true;
                nocheck2=x;
                
            }
        }
        if(check1){
            cout<<1<<"\n"<<nocheck1<<"\n";
        }
       else if(check2){
            cout<<2<<"\n"<<nocheck2<<nocheck2<<"\n";
        }
        else {
            string ans;
            bool fi=false;
            bool tw=false;
            bool th=false;
            bool sv=false;
            for (int i = 0; i < no.size(); i++)
            {
                int x=no[i]-'0';
                if(x==2){
                    tw=true;
                    ans+=no[i];
                }
                else if(tw){
                    if(x==5){
                        ans+=no[i];
                        break;
                    }
                    else if(x==7){
                        ans+=no[i];
                        break;
                    }
                }
            }
            if(ans.size()==2){
                cout<<2<<"\n"<<ans<<"\n";
                continue;;
            }
            else{
                ans="";
            }

            for (int i = 0; i < no.size(); i++)
            {
                int x=no[i]-'0';
                if(x==3){
                    th=true;
                    ans+=no[i];
                }
                else if(th){
                     if(x==2){
                        ans+=no[i];
                        break;
                    }
                    else if(x==5){
                        ans+=no[i];
                        break;
                    }
                }
            }
             if(ans.size()==2){
                cout<<2<<"\n"<<ans<<"\n";
                continue;
            }
            else{
                ans="";
            }
             for (int i = 0; i < no.size(); i++)
            {
                int x=no[i]-'0';
                if(x==5){
                    fi=true;
                    ans+=no[i];
                }
                else if(fi){
                    if(x==2){
                        ans+=no[i];
                        break;
                    }
                    else if(x==7){
                        ans+=no[i];
                        break;
                    }
                }
            }
            if(ans.size()==2){
                cout<<2<<"\n"<<ans<<"\n";
                continue;
            }
            else{
                ans="";
            }
            for (int i = 0; i < no.size(); i++)
            {
                int x=no[i]-'0';
                if(x==7){
                    sv=true;
                    ans+=no[i];
                }
                else if(sv){
                    if(x==5){
                        ans+=no[i];
                        break;
                    }
                    else if(x==2){
                        ans+=no[i];
                        break;
                    }
                }
            }
            if(ans.size()==2){
                cout<<2<<"\n"<<ans<<"\n";
                continue;
            }
            else{
                ans="";
            }
        }
        

    }
 
  return 0;
  }