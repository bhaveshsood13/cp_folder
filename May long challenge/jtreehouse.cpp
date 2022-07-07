#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

#define read(type) readInt<type>() // Fast read
#define int long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define a first
#define b second
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))

const int maxn = 3E5 + 5;
const int mod = 1E9 + 7;

vector<vector<int>> adj;
vi value;
vi weight;
vector<pair<int, int>> ch;

void dfs(int node, int arrival = -1)
{

    for (int i = 0; i < adj[node].size(); i++)
    {
        if (adj[node][i] != arrival)
        {
            dfs(adj[node][i], node);
        }
    }

    ch.clear();

    for (int i = 0; i < adj[node].size(); i++)
    {
        if (adj[node][i] != arrival)
        {
            ch.push_back(make_pair(value[adj[node][i]], adj[node][i]));
        }
    }

    sort(ch.rbegin(), ch.rend());

    int tok = 1;
    for (int i = 0; i < ch.size(); i++)
    {
        weight[ch[i].second] = tok++;
    }

    for (int i = 0; i < adj[node].size(); i++)
    {
        if (adj[node][i] != arrival)
        {
            value[node] += weight[adj[node][i]] * value[adj[node][i]];
        }
    }
}

void solve()
{
    int N, X;
    cin >> N >> X;

    adj.clear();
    weight.clear();
    value.clear();
    for (int i = 0; i < N; i++)
    {
        value.pb(1);
        weight.pb(0);
    }
    for (int i = 0; i < N; ++i)
    {
        vector<int> temp;
        adj.push_back(temp);
    }

    for (int i = 0; i < N - 1; ++i)
    {
        int u, v;
        cin >> u >> v, --u, --v;
        adj[u].pb(v), adj[v].pb(u);
    }

    dfs(0);

    cout << ((value[0] % MOD) * (X % MOD)) % MOD << "\n";
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ttt;
    cin >> ttt;
    while (ttt--)
    {
        solve();
    }

    return 0;
}