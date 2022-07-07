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
        vector<vi> mat(3, vi(3, -1));
        vi row(3, -1);
        vi col(3, -1);
        int countem=0;
        int countx = 0, counto = 0;
        for (int i = 0; i < 3; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < 3; j++)
            {
                if (s[j] == 'X')
                {
                    mat[i][j] = 1;
                    countx++;
                }
                else if (s[j] == 'O')
                {
                    mat[i][j] = 0;
                    counto++;
                }
                else{
                    countem++;
                }
            }
        }
        int countrowsolve = 0;
        bool xrow = false;
        bool owins=false;
        bool xwins=false;
        bool xcol = false;
        for (int i = 0; i < 3; i++)
        {
            int type = mat[i][0];

            bool rs = true;
            for (int j = 0; j < 3; j++)
            {
                if (mat[i][j] != type)
                {
                    rs = false;
                }
            }
            if (rs and type!=-1)
            {
                if (type == 1)
                    xrow = true;
                if(type==0) owins=true;
                if(type==1) xwins=true;
                row[i] = type;
                countrowsolve++;
            }
        }
        int countcolsolve = 0;
        for (int i = 0; i < 3; i++)
        {
            int type = mat[0][i];
            bool rs = true;
            for (int j = 0; j < 3; j++)
            {
                if (mat[j][i] != type)
                {
                    rs = false;
                }
            }
            if (rs and type!=-1)
            {
                if (type == 1)
                    xcol = true;
                if(type== 0) owins=true;
                if(type==1) xwins=true;
                col[i] = type;
                countcolsolve++;
            }
        }
        int cdiagsolv = 0;
        int ldt = mat[0][0];
        bool ld = true;
        bool rd = true;
        int rdt = mat[2][0];
        
        for (int i = 0; i < 3; i++)
        {
            if (mat[i][i] != ldt or  ldt==-1)
                ld = false;
            if (mat[i][2 - i] != rdt or  rdt==-1)
                rd = false;
        }
        if (ld or rd)
            cdiagsolv = 1;
        if((ld and ldt==0 ) or (rd and rdt==0)) owins=true;
        if((ld and ldt==1 ) or (rd and rdt==1)) xwins=true;
        debug(countcolsolve, countrowsolve, cdiagsolv , xrow, xcol);

        if (((countcolsolve + countrowsolve) > 1 and !((countcolsolve + countrowsolve) == 2 and xrow and xcol)) or ((countx - counto) > 1) or (counto > countx)or (owins and countx!=counto) or (xwins and countx==counto))
        { // unreacheable
            cout << "3\n";
        }
        else{

            if((countx==5 and counto==4) or (countrowsolve + countcolsolve + cdiagsolv>=1)){
                cout<<"1"<<"\n";
            }
            else cout<<"2\n";
        }



    }

    return 0;
}