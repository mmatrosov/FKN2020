#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

const int dx[4] = {-1, 1, 0, 0},
	dy[4] = {0, 0, 1, -1};

const int N = 1005, A = 26;
int w[N][N];
int n, m;
bool used[A];



void move(int &x, int &y) {
	if (x % 2 == 0) {
		if (y == m - 1) {
			x++;
		}
		else {
			y++;
		}
	}
	else if (y == 0) {
		x++;
	}
	else {
		y--;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	cin >> n >> m;

	memset(w, -1, sizeof(w));

	int s = n * m, x = 0, y = 0, ans = 0;

	for (int i = 1; i <= s; i++) {
		int a = x, b = y, sz = i;
		s -= i;
		ans = i;

		if (s < i + 1)
			sz += s;

		fill(used, used + A, false);

		for (int j = 0; j < sz; j++) {
			for (int k = 0; k < 4; k++) {
				int p = a + dx[k],
					q = b + dy[k];
				if (p >= 0 && p < n && q >= 0 && q < m && w[p][q] != -1) {
					used[w[p][q]] = true;
				}
			}
			move(a, b);
		}

		int z = 0;
		while (used[z])
			z++;

		for (int j = 0; j < sz; j++) {
			w[x][y] = z;
			move(x, y);
		}
	}

	cout << ans << "\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << char(w[i][j] + 'A');
		}
		cout << "\n";
	}

	return 0;
}