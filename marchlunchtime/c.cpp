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
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        stack<pi> s;
        vi count(n, 0);
        int lcount[n]={0};
        int rcount[n]={0};
        vi leftjump(n,0);
        vi rightjump(n,0);

        for (int i = 0; i < n; i++)
        {
            if (s.empty())
            {
                s.push({arr[i], i});
            }
            else if (arr[i] >= s.top().f)
            {
                if (arr[i] >= s.top().f)
                {
                    int tempcount = 0;
                    pi topw = s.top();

                    debug("here", arr[i], s.top().f, i);
                    while (!s.empty() and s.top().f <= arr[i])
                    {
                        leftjump[s.top().f]=i;
                        s.pop();
                      
                    s.push({arr[i], i});
                }
            }
            else
            {
                s.push({arr[i], i});
            }
        }

        debug("0 ", count,leftjump);
        while (!s.empty())
        {
            int topno = s.top().f;
            int topi = s.top().sec;
            int countfortop = 0;
            s.pop();
            if (!s.empty())
            {
                debug(s.top().f);
                while (!s.empty() and s.top().f == topno)
                {
                    countfortop++;
                    s.pop();
                }
            }

            debug(countfortop);
            count[topi] = countfortop;
        }

        debug("1", count);
        stack<pi> s2;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s2.empty())
            {
                s2.push({arr[i], i});
            }
            else if (arr[i] > s2.top().f)
            {
                int tempcount = 0;
                pi topw = s2.top();

                debug("here", arr[i], s2.top().f, i);
                while (!s2.empty() and s2.top().f < arr[i])
                {
                    
                    s2.pop();
                    if(s2.empty()==false){
                    int topno = s2.top().f;
                    int topi = s2.top().sec;
                    int countfortop = 0;

                    if (topw.f == topno)
                        tempcount++;}
                    // if (!s.empty())
                    // {
                    //     debug(s.top().f);
                    //     while (!s.empty() and s.top().f == topno and s.top().f < arr[i])
                    //     {
                    //         countfortop++;
                    //         s.pop();
                    //     }
                    // }
                    debug(tempcount);
                    count[topw.sec] = tempcount;
                }
                s2.push({arr[i], i});
            }
            else
            {
                debug("here2", arr[i], s2.top().f);
                s2.push({arr[i], i});
            }
        }
        // cout<<"S2\n";
        // while(!s2.empty()){
        //     cout<<" "<<s2.top().f;
        //     s2.pop();
        // }

        debug("\n2", count);
        while (!s2.empty())
        {
            int topno = s2.top().f;
            int topi = s2.top().sec;
            int countfortop = 0;
            debug("s2", s2.top().f, countfortop);
            s2.pop();

            if (!s2.empty())
            {
                debug(s2.top().f, countfortop);
                while (!s2.empty() and s2.top().f == topno)
                {
                    countfortop++;
                    s2.pop();
                }
            }

            debug(countfortop);
            count[topi] = countfortop;
        }
        //   for (int i = 0; i < n; i++)
        //   {

        //   }
        for (int i = 0; i < n; i++)
        {
            cout << count[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}