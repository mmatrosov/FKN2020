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
using namespace std;
int siz = 1;
long long c1 = 1;
long long ans = 0;
vector<long long> s(100000);
int pos1 = 0, pos2 = 0;
struct Bor {
	int per[2];
};
vector<Bor> b(1);
void insert(long long p, int i) {
	long long h = (c1 << 32);
	int v = 0;
	while (h > 0) {
		if (b[v].per[(p / h) % 2] == -1) {
			b[v].per[(p / h) % 2] = siz;
			Bor ff;
			b.push_back(ff);
			b[siz].per[0] = -1;
			b[siz].per[1] = -1;
			++siz;
		}
		v = b[v].per[(p / h) % 2];
		h /= 2;
	}
	b[v].per[0] = i;
}
void find(long long p, int i) {
	long long h = (c1 << 32);
	int v = 0;
	while (h > 0) {
		int k = (p / h) % 2;
		if (b[v].per[1 - k] == -1) {
			v = b[v].per[k];
		}
		else {
			v = b[v].per[1 - k];
		}
		h /= 2;
	}
	if (ans < (s[b[v].per[0]] ^ s[i])) {
		ans = (s[b[v].per[0]] ^ s[i]);
		pos1 = i;
		pos2 = b[v].per[0];
	}
}
void dfs(long long v, vector<vector<pair<long long, long long>>> &g, vector<long long> &s, long long way, int pred = -1) {
	s[v] = way;
	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i].first == pred) {
			continue;
		}
		dfs(g[v][i].first, g, s, (way^g[v][i].second), v);
	}
}
int main()
{
	b[0].per[0] = -1;
	b[0].per[1] = -1;
	int n;
	cin >> n;
	vector<int> a(n, 1000000);
	vector<vector<pair<long long, long long>>> g(n);
	for (int i = 0; i < n - 1; ++i) {
		long long v1, v2, w;
		cin >> v1 >> v2 >> w;
		--v1, --v2;
		g[v1].push_back({ v2, w });
		g[v2].push_back({ v1, w });
	}
	s[0] = 0;
	long long c0 = 0;
	dfs(c0, g, s, c0);
	for (int i = 0; i < n; ++i) {
		insert(s[i], i);
	}
	for (int i = 0; i < n; ++i) {
		find(s[i], i);
	}
	cout << pos1 + 1 << " " << pos2 + 1;
	//system("pause");
    return 0;
}

