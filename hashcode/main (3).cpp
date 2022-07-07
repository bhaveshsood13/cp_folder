#include<bits/stdc++.h>

#define f first
#define s second

#define MOD 1000000007
#define INF 1000000007

#define pb push_back
#define mp make_pair

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
typedef vector<pair<int, int>> vp;
typedef vector<vector<pair<int, int>>> vvp;

class street
{
  public:
	int end, time, id;

	street(int e, int t, int d)
	{
		end = e;
		time = t;
		id = d;
	}

	street()
	{
		end = time = id = -1;
	}
};


bool comp (street & a, street & b)
{
	return pow(a.time, 1.2) *pow(b.end, 1.3) > pow(b.time, 1.2) *pow(a.end, 1.3);
}


int main()
{
	// file I/O
freopen(R"(D:\competitive programming\hashcode\e.txt)", "r", stdin);
	freopen(R"(D:\competitive programming\hashcode\eout.txt)", "w", stdout);

	// global vars
	int D, I, S, V, F;
	unordered_map<string, street> streets;

	// input
	cin >> D >> I >> S >> V >> F;
	vector<string> street_name(S);
	vector<vector<street>> graph(I);
	vvi paths(V);
	vector<ld> cars_count_factor(I, 0.0);
	ld MAX_CAR_COUNT = 1.0;
	// IDs of all the streets leading to intersection i
	vvi towards(I);

	for (int i = 0; i < S; i++)
	{
		int B, E, L;
		string name;
		cin >> B >> E >> name >> L;

		street st(E, L, i);
		towards[E].push_back(i);
		graph[B].push_back(st);
		streets[name] = st;//street(E, L, i);
		street_name[i] = name;
	}

	for (int i = 0; i < V; i++)
	{
		int p;
		cin >> p;
		paths[i].resize(p);
		for (int j = 0; j < p; j++)
		{
			string name;
			cin >> name;
			paths[i][j] = streets[name].id;
			cars_count_factor[streets[name].end] += ((ld)p- (ld)j)/(ld)p;
			MAX_CAR_COUNT = max(MAX_CAR_COUNT, cars_count_factor[streets[name].end]);
		}
	}
	// calculating car factor
	for (int i = 0; i < I; i++){
		cars_count_factor[i] /= MAX_CAR_COUNT;
	}

	// heat map generation
	vector<ld> heatmap(S, 0);
	for (vi &path: paths)
	{
		for (int s: path)
		{
			heatmap[s]++;
		}
	}
//    for (auto &st: streets)
//    {
//        heatmap[st.second.id] /= pow(st.second.time, 0.5);
//    }
	// updating car factor in heatmap
//    for (int i = 0; i < S; i++){
//        heatmap[i] = (cars_count_factor[i] + heatmap[i])/2.0;
//    }
	// schedule calculation and output


	string out;
	int count = 0;

	for (int i = 0; i < I; i++)
	{
		vi &ids = towards[i];
		ld total = 0, base = 1.5;
		int number = ids.size();

		for (int id: ids)
		{
			total += heatmap[id];
		}
		ld gamma = 0.2;
		total = (total + (gamma * cars_count_factor[i]));
		if (total == 0)
		{
			total = 1;
		}

		vector<street> times;
		for (int id: ids)
		{
			if (heatmap[id] > 0)
			{
				int time = (int) round(number * base * heatmap[id] / total);
				time = min(time, D - 1);
				time = max(time, 1);
				times.emplace_back(streets[street_name[id]].time, time, id);
			}
		}

		if (!times.empty())
		{
			count++;
			out += to_string(i) + "\n" + to_string(times.size()) + "\n";
			sort(times.begin(), times.end(), comp);
			for (auto &ti: times)
			{
				out += street_name[ti.id] + " " + to_string(ti.time) + "\n";
			}
		}
	}

	cout << count << '\n' << out;
}
