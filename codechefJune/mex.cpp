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
        string s;
        cin >> s;
        int n = s.length();

        vector<pair<int, int>> v1(n);
        vi v2(n);
        vi v3(n);

        int c1 = 0, c0 = 0, idx1 = -1, idx0 = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            v1[i].second = c1;
            v1[i].first = c0;
            v2[i] = idx1;
            v3[i] = idx0;
            if (s[i] == '1')
            {
                c1++;
                idx1 = i;
            }
            else
            {
                idx0 = i;
                c0++;
            }
        }
        int start = 0;
        int len = n;
        string min = "";
        bool firstzero = false;
        if (s[0] == '0')
        {
            if (v2[0] != -1)
                s = s.substr(v2[0], n - v2[0]);
            else
            {
                cout << "1" << endl;
                break;
            }
            firstzero = true;
            start = v2[0];
            len = n - v2[0];
        }

        string cur = "";

        // for (int i = 0; i < n; i++)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     cout << v1[i].f << " ";
        // }
        // cout << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     cout << v1[i].sec << " ";
        // }
        // cout << endl;
        //  for(int i=0;i<n;i++){
        //     cout<<v3[i]<<" ";
        // }
        // cout << endl;

        string ans = "";
        ll s10 = INF, s1 = INF, stlen = INF;
        long long X = INF, Y = INF, tlen = INF;
        if (v1[start].f == 0)
        {
            if (firstzero)
                min = "10";
            else
                min = "0";
        }
        else
        {
            int i = start;
            while (i < n)
            {
                int zerosafter = v1[i].f;
                int onesafter = v1[i].second;
                int nextone = v2[i];
                cur += s[i - start];

                // debug(nextone,zerosafter,onesafter,min);

                int tx, ty, tl;
                tl = cur.length() + zerosafter + 1;
                tx = cur.length();
                ty = tl - tx;

                // int possible=stringtodecimal(temp) ;
                // if(possible<=minval){
                //     minval=possible;
                //     min=temp;
                // }
                if (tl < tlen)
                {
                    tlen = tl;
                    X = tx;
                    Y = ty;
                }
                else if (tl == tlen)
                {
                    if (tx < X)
                    {
                        X = tx;
                        Y = ty;
                    }
                }
                if (nextone == -1)
                {

                    tl = cur.length() + 1;
                    tx = cur.length() + 1;
                    ty = tl - tx;
                    if (tl < tlen)
                    {
                        tlen = tl;
                        X = tx;
                        Y = ty;
                    }
                    else if (tl == tlen)
                    {
                        if (tx < X)
                        {
                            X = tx;
                            Y = ty;
                        }
                    }
                    // int pos=stringtodecimal(temp2);
                    // if(pos<=minval){
                    //     minval=pos;
                    //     min=temp2;
                    // }
                }
                // debug(nextone,zerosafter,onesafter,min,minval);

                i = nextone;
                if (i == -1)
                {
                    break;
                }
            }
            i = start;
            cur = "";
            while (i < n)
            {
                int zerosafter = v1[i].f;
                int onesafter = v1[i].second;
                int nextone = v3[i];
                cur += s[i - start];

                debug(nextone, cur, onesafter, min);

                int ts1, ts10, tl;
                tl = cur.length() + onesafter + 1;
                ts10 = cur.length();
                ts1 = tl - ts10;

                // int possible=stringtodecimal(temp) ;
                // if(possible<=minval){
                //     minval=possible;
                //     min=temp;
                // }
                if (tl < stlen)
                {
                    stlen = tl;
                    s10 = ts10;
                    s1 = ts1;
                }
                else if (tl == stlen)
                {
                    if (ts10 > s10)
                    {
                        s10 = ts10;
                        s1 = ts1;
                    }
                }
                // if (nextone == -1)
                // {

                //     tl = cur.length() + onesafter + 1;
                //     ts10 = cur.length();
                //     ts1 = tl - ts10;
                //     if (tl < stlen)
                //     {
                //         stlen = tl;
                //         s10 = ts10;
                //         s1 = ts1;
                //     }
                //     else if (tl == stlen)
                //     {
                //         if (ts10 > s10)
                //         {
                //             s10 = ts10;
                //             s1 = ts1;
                //         }
                //     }
                // int pos=stringtodecimal(temp2);
                // if(pos<=minval){
                //     minval=pos;
                //     min=temp2;
                // }
                i = nextone;
                if (i == -1)
                {
                    break;
                }
            }

            if (stlen <= tlen)
        {
            min = "1";
            for (int i = 0; i < s10 - 1; i++)
            {
                min += "0";
            }
            for (int i = 0; i < s1; i++)
            {
                min += "1";
            }
        }
        else
        {
            for (int i = 0; i < X; i++)
            {
                min += "1";
            }
            for (int i = 0; i < Y; i++)
            {
                min += "0";
            }
        }
            // debug(nextone,zerosafter,onesafter,min,minval);
        }
        // for (int i = start; i < n;)
        // {
        //     int zerosafter = v1[i].f;
        //     int onesafter = v1[i].second;
        //     int nextone = v2[i];
        //     cur += s[i - start];

        //     temp = cur;
        //     // debug(nextone,zerosafter,onesafter,min);

        //     int tx, ty, tl;
        //     tl = cur.length() + zerosafter + 1;
        //     tx = cur.length();
        //     ty = tl - tx;

        //     // int possible=stringtodecimal(temp) ;
        //     // if(possible<=minval){
        //     //     minval=possible;
        //     //     min=temp;
        //     // }
        //     if (tl < tlen)
        //     {
        //         tlen = tl;
        //         X = tx;
        //         Y = ty;
        //     }
        //     else if (tl == tlen)
        //     {
        //         if (tx < X)
        //         {
        //             X = tx;
        //             Y = ty;
        //         }
        //     }
        //     if (nextone == -1)
        //     {
        //         temp2 = cur + "1";
        //         tl = cur.length() + 1;
        //         tx = cur.length() + 1;
        //         ty = tl - tx;
        //         if (tl < tlen)
        //         {
        //             tlen = tl;
        //             X = tx;
        //             Y = ty;
        //         }
        //         else if (tl == tlen)
        //         {
        //             if (tx < X)
        //             {
        //                 X = tx;
        //                 Y = ty;
        //             }
        //         }
        //         // int pos=stringtodecimal(temp2);
        //         // if(pos<=minval){
        //         //     minval=pos;
        //         //     min=temp2;
        //         // }
        //     }
        //     // debug(nextone,zerosafter,onesafter,min,minval);
        //     i = nextone;
        //     if (i == -1)
        //     {
        //         break;
        //     }
        // }
        // cout<<min<<endl;
        
        cout << min << endl;
    }

    return 0;
}
