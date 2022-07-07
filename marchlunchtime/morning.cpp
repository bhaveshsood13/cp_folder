#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
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

#define pb push_back
#define eb emplace_back
#define f first
#define s second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;

    ll n, m;
    while (t--)
    {
        
        ll sum = 0;

        cin >> n >> m;
        multiset<ll, less<ll>> all;
        vector<vl> arr;
        vector<vl> answers(n, vl(m, 0));
        for (int i = 0; i < n; ++i)
        {
            vl l(m);
           
            ll temp;

            arr.pb(l);
             ll min_ans = 1e18;
            for (int j = 0; j < m; ++j)
            {
                cin >> temp;
                arr[i][j] = temp;
                all.insert(temp);
            }
            sort(arr[i].begin(), arr[i].end(), greater<ll>());
        }
        for (int k = 0; k < m; k++)
        {
            ll cur_min = *all.begin();
            bool foundalready = false;
            for (int i = 0; i < n; ++i)
            {
                if (!foundalready)
                {
                    auto it = find(arr[i].begin(), arr[i].end(), cur_min);
                    if (it != arr[i].end())
                    {

                        answers[i][k] = cur_min;
                        all.erase(all.begin());
                        arr[i].erase(it);
                        foundalready = true;
                    }
                    else
                    {
                        answers[i][k] = arr[i][0];

                        all.erase(all.find(arr[i][0]));
                        arr[i].erase(arr[i].begin());
                    }
                }
                else
                {
                    answers[i][k] = arr[i][0];
                    all.erase(all.find(arr[i][0]));
                    arr[i].erase(arr[i].begin());
                }
            }
        }

        for (int i = 0; i < answers.size(); ++i)
        {
            for (int j = 0; j < answers[i].size(); ++j)
            {
                cout << answers[i][j] << " ";
            }
            cout << "\n";
        }
    }
}