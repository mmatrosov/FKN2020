#include <iostream> 
#include <fstream> 
#include <sstream> 
#include <vector> 
#include <set> 
#include <string> 

#include <ctime> 
#include <cctype> 
#include <cmath> 
#include <algorithm> 
#include <cstdlib> 
#include <iomanip> 

using namespace std;
using ll = long long;

ll INF = 1e16;

signed main() 
{
	ll n, m, k;
	cin >> n >> m >> k;

	vector<vector<pair<ll, ll>>> g(n);

	vector<bool> sm_used(n, 0);
	vector<ll> sm_time(n, INF);
	set<pair<ll, ll>> smq;
	int b1, b2, b3;

	for (int i = 0; i < k; i++)
	{
		cin >> b1;
		b1--;
		smq.insert({ 0, b1 });
		sm_time[b1] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> b1 >> b2 >> b3;
		b1--;
		b2--;
		g[b1].emplace_back(b2, b3);
		g[b2].emplace_back(b1, b3);
	}

	while (!smq.empty())
	{
		auto t = *(smq.begin());
		smq.erase(smq.begin());

		ll u = t.second;

		for (int i = 0; i < g[u].size(); i++)
		{
			int v = g[u][i].first;
			int w = g[u][i].second;

			if (!sm_used[v] && sm_time[v] > sm_time[u] + w)
			{
				if (smq.find({ sm_time[v], v }) != smq.end())
					smq.erase(smq.find({ sm_time[v], v }));
				sm_time[v] = sm_time[u] + w;
				smq.insert({ sm_time[v], v });
			}
		}
	}

	ll s, f;
	cin >> s >> f;
	s--; f--;

	vector<bool> used(n, 0);
	vector<ll> time(n, INF);
	set<pair<ll, ll>> q;

	time[s] = 0;
	q.insert({ 0, s });

	while (!q.empty())
	{
		auto t = *(q.begin());
		q.erase(q.begin());

		ll u = t.second;

		for (int i = 0; i < g[u].size(); i++)
		{
			int v = g[u][i].first;
			int w = g[u][i].second;

			if (!used[v] && time[v] > time[u] + w && time[u] + w < sm_time[v])
			{
				if (q.find({ time[v], v }) != q.end())
					q.erase(q.find({ time[v], v }));
				time[v] = time[u] + w;
				q.insert({ time[v], v });
			}
		}
	}

	if (time[f] == INF)
		cout << -1 << endl;
	else
		cout << time[f] << endl;

	cin >> n;
}