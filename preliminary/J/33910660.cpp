#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int mat[1005][1005];
ll n, m;

void nx(int& P1, int& P2) {
	if (P1 % 2 == 0) {
		P2++;
		if (P2 == m) {
			P1++;
			P2 = m - 1;
		}
	}
	else {
		P2--;
		if (P2 == -1) {
			P1++;
			P2 = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	ll L = -1;
	ll R = n * m + 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mat[i][j] = 26;
	while (R - L > 1) {
		ll M = (L + R) / 2;
		if (M * (M + 1) / 2 > n * m)
			R = M;
		else
			L = M;
	}
	int c = -1;
	int pt1 = 0;
	int pt2 = 0;
	ll left = n * m;
	cout << L << "\n";
	for (int i = 1; i <= L; i++) {
		//cout << i << "!" << endl;
		int P1 = pt1, P2 = pt2;
		ll need = i;
		if (i == L)
			need = left;
		left -= need;
		vector<int> used(27);
		for (int j = 0; j < need; j++) {
			//cout << j << " " << P1 << " " << P2 << endl;
			if (P1 > 0) {
				used[mat[P1 - 1][P2]] = 1;
			}
			if (P2 > 0) {
				//cout << "!!" << endl;
				//cout << mat[P1][P2 - 1] << "???" << endl;
				used[mat[P1][P2 - 1]] = 1;
				//cout << "!!!" << endl;
			}
			if (P2 < m - 1) {
				used[mat[P1][P2 + 1]] = 1;
			}
			//cout << "here" << endl;
			nx(P1, P2);
		}
		int c = 26;
		for (int i = 0; i < 26; i++) {
			if (!used[i]) {
				c = i;
				break;
			}
		}
		for (int j = 0; j < need; j++) {
			mat[pt1][pt2] = c;
			nx(pt1, pt2);
		}
	}
	for (int i = 0; i < n; i++) {
		string s = "";
		for (int j = 0; j < m; j++) {
			s += ('A' + mat[i][j]);
		}
		cout << s << "\n";
	}
}
//*/