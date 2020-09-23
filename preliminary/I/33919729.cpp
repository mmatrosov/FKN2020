#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <algorithm>
#include <string>
#include <iostream>
#include <complex>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <stack>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <random>
#include <set>
#include <vector>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#include <array>
#include <forward_list>
#include <chrono>
#include <iomanip>
#include <utility>
#include <assert.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse")

#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

mt19937 gen(34);

struct edge
{
	int to;
	ll l;
	edge() {}
	edge(int _to, ll _l)
	{
		to = _to;
		l = _l;
	}
};

int n, m, k, s, f;
vector <vector <edge>> gr;
ll d[200000], d2[200000];
set <pair <ll, int>> dijkstra;

void run_dijkstra()
{
	while (dijkstra.size() > 0)
	{
		pair <int, int> qwe = *dijkstra.begin();
		dijkstra.erase(dijkstra.begin());
		int v = qwe.second, dd = qwe.first;
		for (int i = 0; i < gr[v].size(); i++)
		{
			int to = gr[v][i].to, l = gr[v][i].l;
			if (d[to] > d[v] + l)
			{
				dijkstra.erase(dijkstra.find(mp(d[to], to)));
				d[to] = d[v] + l;
				dijkstra.insert(mp(d[to], to));
			}
		}
	}
}

void run_dijkstra2()
{
	while (dijkstra.size() > 0)
	{
		pair <int, int> qwe = *dijkstra.begin();
		dijkstra.erase(dijkstra.begin());
		int v = qwe.second, dd = qwe.first;
		if (dd == 1e18)
			continue;
		for (int i = 0; i < gr[v].size(); i++)
		{
			int to = gr[v][i].to, l = gr[v][i].l;
			if (d2[to] > d2[v] + l && d2[v] + l < d[to])
			{
				dijkstra.erase(dijkstra.find(mp(d2[to], to)));
				d2[to] = d2[v] + l;
				dijkstra.insert(mp(d2[to], to));
			}
		}

	}

}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("memory.in", "r", stdin);
	//freopen("memory.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	gr.resize(n);
	for (int i = 0; i < n; i++)
		d[i] = 1e18;
	while (k--)
	{
		int v;
		cin >> v;
		v--;
		d[v] = 0;
	}
	for (int i = 0; i < n; i++)
		dijkstra.insert(mp(d[i], i));
	while (m--)
	{
		int u, v;
		ll len;
		cin >> u >> v >> len;
		u--;
		v--;
		gr[u].push_back(edge(v, len));
		gr[v].push_back(edge(u, len));
	}
	run_dijkstra();
	cin >> s >> f;
	s--;
	f--;
	dijkstra.clear();
	for (int i = 0; i < n; i++)
		d2[i] = 1e18;
	d2[s] = 0;
	for (int i = 0; i < n; i++)
		dijkstra.insert(mp(d2[i], i));
	run_dijkstra2();
	if (d2[f] == 1e18)
		cout << -1;
	else
		cout << d2[f];
	return 0;
}