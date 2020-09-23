#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int SZ = 1e3 + 10;

int n, m;
char ans[SZ][SZ];
int cnt;

void make_step(int& x, int& y) {
	if (x & 1)
		y--;
	else
		y++;
	if (y < 0) {
		x++;
		y = 0;
	}
	else if (y >= m) {
		x++;
		y = m - 1;
	}
}

char choose_letter(int x, int y, int k) {
	set<char> st;
	for (int i = 0; i < k; i++) {
		if (x > 0)
			st.insert(ans[x - 1][y]);
		if (y > 0)
			st.insert(ans[x][y - 1]);
		if (y < m - 1)
			st.insert(ans[x][y + 1]);
		
		make_step(x, y);
	}
	char c = 'A';
	while (st.count(c))
		c++;
	return c;
}

void action(int& x, int& y, int k) {
	if (cnt - k <= k)
		k = cnt;
	char c = choose_letter(x, y, k);
	for (int i = 0; i < k; i++) {
		ans[x][y] = c;
		make_step(x, y);
	}
	cnt -= k;
}

int main()
{
	cin >> n >> m;
	cnt = n * m;
	int x = 0, y = 0;
	int k = 1;
	int result = 0;
	while (cnt > 0) {
		action(x, y, k++);
		result++;
	}
	cout << result << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << ans[i][j];
		cout << "\n";
	}
	return 0;
}
