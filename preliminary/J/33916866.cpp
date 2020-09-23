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
	long long n, m;
	cin >> n >> m;
	vector<vector<int>> ms(n, vector<int>(m));
	long long s = n * m;
	long long sz = 1;
	for (int i = 1; i < 5000; i++) {
		s -= i;
		if (s >= 0) {
			sz = i;
		}
	}
	cout << sz << "\n";
	long long nu = 0;
	long long b = -1;
	for (int i = 1; i <= sz; i++) {
		b++;
		b %= 26;
		for (int j = 0; j < i; j++) {
			long long nb = nu % m;
			if (nu / m % 2 == 1) {
				nb = m - 1 - nb;
			}
			ms[nu / m][nb] = i - 1;
			nu++;
		}
	}
	while (nu < n*m) {
		long long nb = nu % m;
		if (nu / m % 2 == 1) {
			nb = m - 1 - nb;
		}
		ms[nu / m][nb] = sz-1;
		nu++;
	}
	vector<vector<int>> g(sz, vector<int>(sz, 0));
	vector<long long> col(sz,-1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i > 0) {
				g[ms[i][j]][ms[i - 1][j]] = 1;
			}
			if (j > 0) {
				g[ms[i][j]][ms[i][j - 1]] = 1;
			}
			if (i + 1 < n) {
				g[ms[i][j]][ms[i + 1][j]] = 1;
			}
			if (j + 1 < m) {
				g[ms[i][j]][ms[i][j + 1]] = 1;
			}
		}
	}
	for (int i = 0; i < sz; i++) {
		for (int c = 0; c < 26; c++) {
			bool t = true;
			for (int j = 0; j < sz; j++) {
				if (g[i][j] == 1 && col[j] == c) {
					t = false;
				}
			}
			if (t) {
				col[i] = c;
				break;
			}
		}
	}
	for (auto i : ms) {
		for (auto j : i) {
			cout << char('A' + col[j]);
		}
		cout << "\n";
	}
	system("pause");
}