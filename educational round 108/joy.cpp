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
#include <unordered_map>
 
using namespace std;
 
#define read(type) readInt<type>() // Fast read
#define ll long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define a first
#define b second
#define vi vector<ll>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))
 
void solve()
{
	ll n;
	vi uni;
	vi skill;
	cin >> n;
	for (ll i = 0; i < n; i++)
	{
		ll a;
		cin >> a;
		uni.pb(a);
		// cin >> uni[i];
	}
	// for (ll i = 0; i < n; i++)
	// {
	// 	cout << uni[i];
	// }
	for (ll i = 0; i < n; i++)
	{
		ll a;
		cin >> a;
		skill.pb(a);
		// skill[i] = a;
		// cin >> skill[i];
	}
	
	unordered_map<ll, vi> map;
	for (ll i = 0; i < n; i++)
	{
		vi temp;
		// cout << uni[i] << nL;
		map[uni[i]] = temp;
	}
 
	for (ll i = 0; i < n; i++)
	{
		map[uni[i]].pb(skill[i]);
	}
	// for (auto x : map){
	// 	cout << x.first << " ";
	// 	sort(x.second.begin(), x.second.end(), greater<ll>());
	// 	for(ll i =0; i<x.second.size();i++){
	// 		cout << x.second[i] << " ";
	// 	}
	// 	cout << nL;
 
	// }
 
	vector < vector <ll > > arr;
	for (auto x : map)
	{
		arr.pb(x.second);
	}
	for (ll i = 0; i < arr.size(); i++)
	{
		// vi temp = arr[i];
		vi sum;
		ll sum_value = 0;
		sort(arr[i].begin(), arr[i].end(), greater<ll>());
		for(ll j = 0; j < arr[i].size(); j++)
		{
			// cout << arr[i][j] << " ";
			// if(j == 0){
			// 	continue;
			// }
			// arr[i][j] = arr[i][j] + arr[i][j - 1];
			sum_value += arr[i][j];
			sum.pb(sum_value);
		}
		// cout << nL;
		arr[i] = sum;
		
	}
	// for(ll i = 0; i<arr.size(); i++){
	// 	for(ll j = 0; j <arr[i].size(); j++){
	// 		cout << arr[i][j] << " ";
	// 	}
	// 	cout << nL;
	// }
 
	
	vector<long long int> ans(n);
    for(long long int i =0;i<n;i++)
    {
      ans[i]=0;
    }
	// cout << arr.size() << nL;
    for(long long int i=0;i<arr.size();i++)
    {
      if(arr[i].size()!=0){
		//   cout<<arr[i].size()<;
        for(long long int j=0;j<arr[i].size();j++)
        {
        // cout<<arr[i].size()<<endl;
          
        long long int d = arr[i].size()%( j + 1);
        long long int sum = arr[i][arr[i].size()-1-d];
        // cout<<i<<" "<<j<<" "<<d<<" "<<sum<<endl;
        ans[j]+=sum;
        
        }
      }
      
    }
 
    for(long long int i=0;i<n;i++)
    {
      cout<<ans[i]<<" ";
    }
    cout<<endl;
 
  }
 
	// for (ll i = 0; i < n; i++)
	// {
	// 	ll value = 0;
 
	// 	for(ll j = 0; j<arr.size(); j++){
	// 		if(i >= arr[j].size()){
	// 			continue;
	// 		}
	// 		ll size = arr[j].size();
	// 		ll sub = size%(i + 1);
	// 		// cout << "size " << size << " sub " << sub <<nL;
	// 		// cout << arr[j][size - sub] << nL;
	// 		value += arr[j][size - sub - 1];
	// 		// cout << "value " << value << nL;
	// 	}
		
	// 	cout << value << " ";
	// }
	// cout <<nL;
	
// }
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int ttt;
	cin >> ttt;
	while (ttt--)
	{
		solve();
	}
 
	return 0;
}