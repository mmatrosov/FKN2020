#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define ff first
#define ss second
using namespace std;

vector<vector<int>> arr;

vector<set<int>> g;
vector<char> ind2char;

signed main() {
	int n, m;
	cin >> n >> m;
	arr.resize(n, vector<int>(m, -1));
	int cnt = 1;
	int sz = 1;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = cnt;
				sz--;
				if (sz == 0) {
					cnt++;
					sz = cnt;
				}
			}
		} else {
			for (int j = m - 1; j >= 0; j--) {
				arr[i][j] = cnt;
				sz--;
				if (sz == 0) {
					cnt++;
					sz = cnt;
				}
			}
			
		}
	}
	if (sz != cnt) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == cnt) {
					arr[i][j]--;
				}
			}
		}
	}
	
	g.resize(cnt + 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i > 0) {
				g[arr[i][j]].insert(arr[i - 1][j]);
			}
			if (i != n - 1) {
				g[arr[i][j]].insert(arr[i + 1][j]);
			}
			if (j > 0) {
				g[arr[i][j]].insert(arr[i][j - 1]);
			}
			if (j != m - 1) {
				g[arr[i][j]].insert(arr[i][j + 1]);
			}
		}
	}
	
	ind2char.resize(g.size());
	for (int i = 1; i <= cnt; i++) {
		for (int j = 'A'; j <= 'Z'; j++) {
			bool ok = 1;
			for (auto el: g[i]) {
				if (ind2char[el] == j) {
					ok = 0;
					break;
				}
			}
			if (ok) {
				ind2char[i] = j;
				break;
			}
			
		}
		if (ind2char[i] == 0) {
			return 13;
		}
	}
	cout << cnt - 1<< endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ind2char[arr[i][j]];
		} cout << '\n';
	}
	
	return 0;
}