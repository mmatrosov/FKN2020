// Win32Project116.cpp: определяет точку входа для консольного приложения.
//

//#include "stdafx.h"
#include<iomanip>
#include<iostream>
#include<cmath>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>
#define int  long long
using namespace std;
signed main()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<int, int>>> g(n);
	vector<int> beg(k);
	for (int i = 0; i < k; ++i) {
		cin >> beg[i];
		--beg[i];
	}
	for (int i = 0; i < m; ++i) {
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		--v1, --v2;
		g[v1].push_back({ v2, w });
		g[v2].push_back({ v1, w });
	}
	set<pair<int, int>> sp;
	vector<long long> s(n, 1e18);
	for (int i = 0; i < k; ++i) {
		s[beg[i]] = 0;
		sp.insert({ s[beg[i]], beg[i] });
	}
	while (sp.size() > 0) {
		auto t = *sp.begin();
		sp.erase(sp.begin());
		if (s[t.second] != t.first) {
			continue;
		}
		int v = t.second;
		for (int i = 0; i < g[v].size(); ++i) {
			if (s[g[v][i].first] > s[v] + g[v][i].second) {
				s[g[v][i].first] = s[v] + g[v][i].second;
				sp.insert({s[g[v][i].first], g[v][i].first});
			}
		}
	}
	int bg, ed;
	cin >> bg >> ed;
	--bg, --ed;
	vector<int> s2(n, 1e18);
	s2[bg] = 0;
	sp.insert({s2[bg], bg});
	while (sp.size() > 0) {
		auto t = *sp.begin();
		sp.erase(sp.begin());
		if (s2[t.second] != t.first) {
			continue;
		}
		int v = t.second;
		for (int i = 0; i < g[v].size(); ++i) {
			if (s2[g[v][i].first] > s2[v] + g[v][i].second && s2[v] + g[v][i].second < s[g[v][i].first]) {
				s2[g[v][i].first] = s2[v] + g[v][i].second;
				sp.insert({s2[g[v][i].first], g[v][i].first});
			}
		}
	}
	if (s2[ed] > 1e17) {
		cout << -1;
	}
	else {
		cout << s2[ed];
	}
	//system("pause");
    return 0;
}

