#include <iostream>
#include <vector>

#define x first
#define y second

using namespace std;

typedef pair<int, int> pii;
#define mp make_pair

pii shs[4] = {
	mp(0, 1), mp(1, 0), mp(0, -1), mp(-1, 0)
};

signed main() {
	int n, m;
	cin >> n >> m;
	vector<pii> cells;
	for (int i = 0; i < n; i++) {
		if (~i & 1) {
			for (int j = 0; j < m; j++) {
				cells.emplace_back(i, j);
			}
		} else {
			for (int j = m - 1; j >= 0; j--) {
				cells.emplace_back(i, j);
			}
		}
	}
	vector<string> v(n, string(m, '.'));
	int diff = 0;
	char last = 'A';
	for (int cnt = 1; (cells).size() >= cnt; cnt++) {
		if (cnt + 1 + cnt > cells.size()) {
			cnt = cells.size();
		}
		diff++;
		last = (cnt % 26) + 'A' - 1;
		vector<pii> place;
		for (int i = 0; i < cnt; i++) {
			place.push_back(cells.back());
			cells.pop_back();
			// v[cells.back().first][cells.back().second] = last;
		}
		vector<bool> ava(26, true);
		for (pii pp : place) {
			for (pii sh : shs) {
				pii sub = mp(pp.first + sh.first, pp.second + sh.second);

				if (0 <= sub.x && sub.x < n && 0 <= sub.y && sub.y < m) {
					if (v[sub.x][sub.y] != '.') {
						ava[v[sub.x][sub.y] - 'A'] = false;
					}
				}
			}
		}
		for (int i = 0; i < 26; i++) {
			if (ava[i]) {
				last = 'A' + i;
				break;
			}
		}
		for (pii pp : place) {
			v[pp.x][pp.y] = last;
		}
	}
	// for (int i = 0; i < n; i++)
	// 	for (int j = 0; j < m; j++)
	// 		if (v[i][j] == '.')
	// 			v[i][j] = last;
	cout << diff << endl;
	for (string s : v) {
		cout << s << endl;
	}
}