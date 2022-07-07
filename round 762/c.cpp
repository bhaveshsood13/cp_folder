/**
 * author: Bhavesh
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define cinarr(ar, n)           \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> ar[i];           \
    }
#define car(ar, n)              \
    for (int i = 0; i < n; i++) \
    {                           \
        cout << ar[i] << " ";   \
    }
#define forn(i, a, b) for (int i = (a); i < ll(b); ++i)
#define fo(i, a) forn(i, 0, ll(a))
#define rforn(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define ro(i, a) rforn(i, 0, a)
#define trav(a, x) for (auto &a : x)

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define sec second

void __print(int x)
{
    cerr << x;
}
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
const ll INF = 1e18;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        string s;
        cin >> a >> s;
        int n1 = s.size();
        int n2 = a.size();
        string ans = "";
        bool flag=0;
        for (int i = n1-1; i >= 0; i--)
        {   
            
            int cs = s[i] - '0';
            int ca=0;
            if(n2-1>=0)
            ca=a[n2-1]-'0';
            else 
             ca=0;
            int dig=cs-ca;
            debug(1,cs,ca,dig,n2);
            if(dig<0){
                int cs;
                if(i>=1)
                cs= stoi(s.substr(i-1,2));
                dig=cs-ca;
                debug(2,cs,ca,dig);

                if(dig<0){
                    n2--;
                    flag=1;
                    cout<<-1<<endl;
                    break;
                }
                else if(dig>9){
                    n2--;
                    flag=1;
                    cout<<-1<<endl;
                    break;
                }
                else{
                    i--;n2--;
                    // debug(dig);
                    ans.push_back(to_string(dig)[0]);
                }
            }
            else{
                n2--;
                ans.push_back(to_string(dig)[0]);
            }

        }
    
          reverse(ans.begin(),ans.end());
        string finans="";
        bool f=false;
        for(int i=0;i<ans.size();i++){
            if(ans[i]=='0' and !f){}
            else {
            finans+=ans[i]; f=true;}       
            }    
        if(n2>=1){
            cout<<-1<<endl;

        }
        else if( flag==0)         
        cout<<finans<<endl;
    }

    return 0;
}