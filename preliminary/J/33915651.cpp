#include <bits/stdc++.h>
 
using namespace std;

//#define int long long
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const int MAXN = 1020;
char res[MAXN][MAXN];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout.setf(ios::fixed);
	//cout.precision(20);

	memset(res, '.', sizeof(res));
	int n, m;
	cin >> n >> m;
	int ans = 0, ost = n * m;
	bool f = true;
	int x = 0, y = 0;
	for (int cur = 1; f; cur++) {
		if (cur + cur + 1 > ost) {
			cur = ost;
			f = false;
		}
		ost -= cur;
		ans++;
		set<char> setik;
		int tx = x, ty = y;
		int kek = cur;
		while (kek > 0) {
			if (tx > 0 && res[tx - 1][ty] != '.') {
				setik.insert(res[tx - 1][ty]);
			}
			if (ty > 0 && res[tx][ty - 1] != '.') {
				setik.insert(res[tx][ty - 1]);
			}
			if (ty < m - 1 && res[tx][ty + 1] != '.') {
				setik.insert(res[tx][ty + 1]);
			}
			if (tx % 2 == 0) {
				ty++;
				if (ty == m) {
					tx++;
					ty = m - 1;
				}
			}
			else {
				ty--;
				if (ty == -1) {
					tx++;
					ty = 0;
				}
			}
			kek--;
		}  
		char need = '.';
		for (char c = 'A'; c <= 'Z'; ++c) {
			if (!setik.count(c)) {
				need = c;
				break;
			}
		}
		assert(need != '.');
		kek = cur;
		while (kek > 0) {
			res[x][y] = need;
			if (x % 2 == 0) {
				y++;
				if (y == m) {
					x++;
					y = m - 1;
				}
			}
			else {
				y--;
				if (y == -1) {
					x++;
					y = 0;
				}
			}
			kek--;
		} 
	}
	cout << ans << '\n';
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << res[i][j];
		}
		cout << '\n';
	}
}