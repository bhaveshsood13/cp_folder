#include <bits/stdc++.h>
using namespace std;
typedef map<int, vector<int>>::iterator mi;
typedef pair<int, mi> p;
typedef priority_queue<p, vector<p>, greater<p>> pq;

void allPossibleSubset(vector<int> arr, int n, int k, map<int, vector<int>> &m)
{
    int count = pow(2, n);
    vector<int> v;

    for (int i = 1; i < count; i++)
    {
        int sum = 0;

        for (int j = 0; j < n; j++)
        {

            if ((i & (1 << j)) > 0)
            {
                cout << arr[j + k] << " ";
                v.push_back(arr[j + k]);
                sum += arr[j + k];
            }
        }
        cout << "!" << sum << "\n";
        m[sum] = v;
        v.clear();
    }
    cout << '\n';
}

int main()
{
    int n, n1, target;
    cout << "Enter size of the set\n";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter Elements of the set\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // cin>>target ;

    //array division
    vector<int> v1, v2, v3, v4;
    auto beg = arr.begin();
    v1.assign(beg, beg + n / 4);
    v2.assign(beg + n / 4, beg + 2 * (n / 4));
    v3.assign(beg + 2 * (n / 4), beg + 3 * (n / 4));
    v4.assign(beg + 3 * (n / 4), beg + 4 * (n / 4));

    //  for(auto i: v1) cout<<i<<" "; cout<<endl;
    //  for(auto i: v2) cout<<i<<" ";cout<<endl;
    //  for(auto i: v3) cout<<i<<" "; cout<<endl;
    //   for(auto i: v4) cout<<i<<" ";cout<<endl;
    int j = n % 4;
    while (j)
    {

        v1.push_back(arr[n - j]);
        j--;
    }
    //for(int i=0;i<v1.size();i++) cout<<v1[i]<<" "; cout<<endl;
    map<int, vector<int>> m1, m2, m3, m4;
    allPossibleSubset(v1, v1.size(), 0, m1); //first half
    allPossibleSubset(v2, n / 4, 0, m2);
    allPossibleSubset(v3, n / 4, 0, m3);
    allPossibleSubset(v4, n / 4, 0, m4);
    cout << '\n';
    // for(auto i : m1){
    // cout<<i.first<<" ";
    // for(auto itr : i.second)
    // {cout<<itr<<" ";}
    // cout<<endl;
    //map < int, vector < int >> :: iterator itr;
    priority_queue<p> maxh;
    pq minh;

    //init minh

    return 0;
}