#include <bits/stdc++.h>
using namespace std;
int j;
int main()
{
	int t;
	long long ans;
	cin >> t;
	while (t--)
	{
		int n, q;
		cin >> n >> q;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		vector<int> bits(32, 0);
		for (int i = 0; i < n; i++)
		{
			j = 0;
			int cnt = 0;
			int v1 = v[i];
			while (v1 > 0)
			{
				if ((v1 & 1) == 1)
				{
					bits[j]++;
				}
				v1 = v1 >> 1;
				j++;
			}
		}
		ans = 0;
		for (int i = 0; i < 32; i++)
		{
			// cout << bits[i] << " ";
			if (bits[i] >= 1)
			{
				ans += pow(2, i);
			}
		}
		//cout << '\n';
		cout << ans << '\n';

		while (q--)
		{
			int x, V;
			cin >> x >> V;
			// bits.clear ();

			//for x
			x = v[x-1];
			
			j = 0;
			while (x > 0)
			{

				if ((x & 1) == 1)
				{
					bits[j]--;
					// cout<<"here"<<j<<" bi"<<bits[j];
				}

				x = x >> 1;
				j++;
			}
			//for V
			j = 0;
			v[x-1]=V;
			while (V > 0)
			{

				if ((V & 1) == 1)
				{
					bits[j]++;
				}

				V = V >> 1;
				j++;
			}
			long long ans = 0;
			for (int i = 0; i < 32; i++)
			{
				// cout << bits[i] << " ";
				if (bits[i] >= 1)
				{
					ans += pow(2, i);
				}
			}
			// cout << '\n';
			cout << ans << '\n';
		}
	}

	return 0;
}
