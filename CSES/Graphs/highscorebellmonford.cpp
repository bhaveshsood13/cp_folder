#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define INT_MIN -1e18
#define INT_MAX 1e18
 
 
struct triplet{
    int first;
    int second;
    int third;
};
 
int n, m;
vector<triplet> edges;
vector<long long> dist;
 
void bellman_ford()
{
    for(int i = 1; i < n; i++)
    {
        for(auto e: edges)
        {
            int u = e.first;
            int v = e.second;
            int d = e.third;

            if (dist[u] != INT_MAX && dist[u] + d < dist[v])
                dist[v] = dist[u] + d;
        }
    } // n-1 relaxations
 
    for(int i =0; i<n ;i ++){
        for(auto e: edges)
        {
            int u = e.first;
            int v = e.second;
            int d = e.third;

             if (dist[u] != INT_MAX && dist[u] + d < dist[v]) {
                dist[v] = INT_MIN;

            //cout<<"v"<<v<<" "<<dist[v]<<'\n';
            }

        }
    }

}
 
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    dist.resize(n+1);
    edges.resize(m);
    for(int i = 0; i < m; ++i)
    {
        struct triplet inp;
        cin >> inp.first >> inp.second >> inp.third;
        inp.third *= -1; 
        edges[i] = inp;
    }
 
    for(int i = 2; i <= n; ++i)
    {
        dist[i] = INT_MAX;
    }
    dist[1] = 0;
 
    bellman_ford();
    if(dist[n] == INT_MIN)
    {
        cout << -1 << endl;
        return 0;
    } 
    cout << dist[n] * (-1) << endl;
}