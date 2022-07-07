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
#define pub push_back
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
    string s;
    cin >> s;
    int nb, ns, nc, pb, ps, pc;
    vl price(3,0);
    vl given(3,0);
    cin >> given[0] >> given[1] >> given[2] >> price[0] >> price[1] >> price[2];
    nb=given[0];
    ns=given[1];
    nc=given[2];
    ll r;
    cin >> r;
    int cb = 0, cs = 0, cc = 0;
    vl req(3,0);
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'B')
        {
            cb++;req[0]++;
        }

        if (s[i] == 'S')
        {
            cs++;req[1]++;
        }

        if (s[i] == 'C')
        {
            cc++;req[2]++;
        }
    }

    
    vpl pos(3,{INT_MAX,-1});
    vl rem={nb,ns,nc};
    if(cb>0){ pos[0].f = nb / cb; pos[0].sec=0;
        rem[0] = nb % cb;}
    if(cs>0){ pos[1].f = ns / cs;pos[1].sec=1;
        rem[1] = ns % cs;}
    if(cc>0){ pos[2].f = nc / cc;pos[2].sec=2;
        rem[2] = nc % cc;}

    ll count=0;
    debug(pos[0].f,pos[1].f,pos[2].f ,rem[0], rem[1], rem[2]);
    count+=min({pos[0].f,pos[1].f,pos[2].f});
    // cout<<count;
    bool rfinish=false;
    bool posequal=false;
    if(pos[0].f==pos[1].f and pos[1].f==pos[2].f) posequal=true;
    for (int i = 0; i < 3; i++)
    {
       if(rem[i]!=0 and req[i]>0) {
           
            int required=req[i]-rem[i];
            // debug(required);
            if(r-(price[i]*required)>=0){
                r-=(price[i]*required);
                rem[i]=0;
            }
            else{
                
                rfinish=true;
                break;
            }

        
        if(rfinish==false and req[i]>0)
        pos[i].f++;}
    }
    vpl sortpos=pos;
    sort(sortpos.begin(),sortpos.end());
    // for (int i = 0; i < 3; i++)
    // {
    //     cout<<"sortpos"
    // }
    debug(sortpos);
    
        pl mini=sortpos[0];
        pl secondmini=sortpos[1];
        pl thirdmini=sortpos[2];
        if(mini.f!=secondmini.f){
            if(secondmini.sec!=-1){
                ll required=secondmini.f-mini.f;
                if(r-(price[mini.sec]*required*req[mini.sec])>=0){
                     r-=(price[mini.sec]*required*req[mini.sec]);
                     pos[mini.sec].f+=required;
                     mini.f+=required;
                     debug(r,"here");
                }
                else{
                    int possibletobuy=r/(price[mini.sec]*req[mini.sec]);
                    r-=(possibletobuy*price[mini.sec]*req[mini.sec]);
                    pos[mini.sec].f+=possibletobuy;
                    mini.f+=possibletobuy;
                    rfinish=true;
                }
            }
            else {
                    int possibletobuy=r/(price[mini.sec]*req[mini.sec]);
                    r-=(possibletobuy*price[mini.sec]*req[mini.sec]);
                    pos[mini.sec].f+=possibletobuy;
                       mini.f+=possibletobuy;
                    rfinish=true;
            }
        }
        if(mini.f==secondmini.f and secondmini.f!=thirdmini.f){
            if(thirdmini.sec!=-1){
                int required=thirdmini.f-mini.f;
                if(r-((price[mini.sec]*req[mini.sec]+price[secondmini.sec]*req[secondmini.sec])*required)>=0){
                     r-=((price[mini.sec]*req[mini.sec]+price[secondmini.sec]*req[secondmini.sec])*required);
                     pos[mini.sec].f+=required;
                      mini.f+=required;
                     pos[secondmini.sec].f+=required;
                      secondmini.f+=required;
                }
                else {
                int possibletobuy=r/(price[mini.sec]*req[mini.sec]+price[secondmini.sec]*req[secondmini.sec]);
                    r-=(possibletobuy*(price[mini.sec]*req[mini.sec]+price[secondmini.sec]*req[secondmini.sec]));
                    pos[mini.sec].f+=possibletobuy;
                    pos[secondmini.sec].f+=possibletobuy;
                    mini.f+=possibletobuy;
                    secondmini.f+=possibletobuy;
                    rfinish=true;
                }
            }
            else {
                int possibletobuy=r/(price[mini.sec]*req[mini.sec]+price[secondmini.sec]*req[secondmini.sec]);
                    r-=(possibletobuy*(price[mini.sec]*req[mini.sec]+price[secondmini.sec]*req[secondmini.sec]));
                    pos[mini.sec].f+=possibletobuy;
                    pos[secondmini.sec].f+=possibletobuy;
                     mini.f+=possibletobuy;
                    secondmini.f+=possibletobuy;
                    rfinish=true;
            }
        }
    if(pos[0].f==pos[1].f and pos[1].f==pos[2].f) posequal=true;
        
    


    debug(pos[0].f,pos[1].f,pos[2].f ,rem[0], rem[1], rem[2],count);

    count=min({pos[0].f,pos[1].f,pos[2].f});

    int sum=0;
    for (int i = 0; i < 3; i++)
    {
        if(req[i]>0){
            sum+=price[i]*req[i];
        }
    }
    debug(sum);
    count+=r/sum;
    



    // int count = 0;

    // int pcb = 0, pcs = 0, pcc = 0;
    // int rem1=nb,rem2=ns,rem3=nc;

    // if (cb != 0)
    //     {pcb = nb / cb;
    //     rem1 = nb % cb;}
    // if (cs != 0)
    //     {pcs = ns / cs;
    //      rem2 = ns % cs;}
    // if (cc != 0)
    //     {pcc = nc / cc;
    //      rem3 = nc % cc;}
    // debug(pcb, pcs, pcc, rem1, rem2, rem3);
    // int bb, ss, che;
    // if (cb == 0)
    // {
    //     if (pcs > 0 and pcc > 0)
    //     {
    //         count += mini(pcs, pcc);
    //     }
    // }
    // if (cs == 0)
    // {
    //     if (pcb > 0 and pcc > 0)
    //     {
    //         count += mini(pcb, pcc);
    //     }
    // }
    // if (cc == 0)
    // {
    //     if (pcb > 0 and pcs > 0)
    //     {
    //         count += mini(pcb, pcs);
    //     }
    // }
    // else if (pcb > 0 and pcs > 0 and pcc > 0)
    // {
    //     count += mini(pcb, mini(pcs, pcc));
    // }

    // //filling in the remainder first.
    // while((rem1!=0 and cb>0)) or (rem2!=0 and cs>0) or (rem3!=0 and cc>0))
    // {
        
    // }

    cout << count;

    return 0;
}