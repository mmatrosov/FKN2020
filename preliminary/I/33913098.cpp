#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<random>
#include<set>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	long long n, m, k;
	cin >> n >> m >> k;
	vector<long long> d(n, 1e18);
	vector<long long> dl(n, 1e18);
	vector<int> ko(k);
	for (int i = 0; i < k; i++) {
		cin >> ko[i];
	}
	vector<vector<pair<int,long long>>> g(n);
	for (int i = 0; i < m; i++) {
		long long x, y, z;
		cin >> x >> y >> z;
		x--;
		y--;
		g[x].push_back({ y,z });
		g[y].push_back({ x,z });
	}
	set<pair<long long, int>> se;
	for (auto i : ko) {
		se.insert({ 0,i - 1 });
	}
	while (!se.empty()) {
		pair<long long, int> p = *se.begin();
		se.erase(p);
		if (p.first < d[p.second]) {
			d[p.second] = p.first;
			for (auto i : g[p.second]) {
				se.insert({ i.second + p.first,i.first });
			}
		}
	}
	int s, f;
	cin >> s >> f;
	s--;
	f--;
	se.insert({ 0,s });
	while (!se.empty()) {
		pair<long long, int> p = *se.begin();
		se.erase(p);
		if (p.first < dl[p.second] && p.first<d[p.second]) {
			dl[p.second] = p.first;
			for (auto i : g[p.second]) {
				se.insert({ i.second + p.first,i.first });
			}
		}
	}
	if (dl[f] < 1e18) {
		cout << dl[f];
	}
	else {
		cout << -1;
	}
	system("pause");
}