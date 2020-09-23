#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    int ls = 0;
    char ans[n][m];
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) ans[i][j] = '.';
    int ts = 0;
    int sum = 0;
    int cnt = 0;
    int x = 0, y = 0;
    while (x < n) {
        set <char> lol;
        ++ts;
        if (sum + ts + ts + 1 <= n * m) {
            vector <pair <int, int> > cls;
            for (int i = 0; i < ts; ++i) {
                cls.push_back({x, y});
                if (x) lol.insert(ans[x - 1][y]);
                if (y + 1 < m) lol.insert(ans[x][y + 1]);
                if (y) lol.insert(ans[x][y - 1]);
                if (x % 2) --y;
                else ++y;
                if (y < 0 || y == m) {
                    ++x;
                    if (x % 2) y = m - 1;
                    else y = 0;
                }
            }
            sum += ts;
            ++cnt;
            char tc = 'A';
            for (int i = 1; i < 26; ++i) if (lol.find('A' + i) == lol.end()) tc = 'A' + i;
            for (int i = 0; i < cls.size(); ++i) ans[cls[i].first][cls[i].second] = tc;
        }
        else {
            vector <pair <int, int> > cls;
            for (int i = 0; i < n * m - sum; ++i) {
                cls.push_back({x, y});
                if (x) lol.insert(ans[x - 1][y]);
                if (y + 1 < m) lol.insert(ans[x][y + 1]);
                if (y) lol.insert(ans[x][y - 1]);
                if (x % 2) --y;
                else ++y;
                if (y < 0 || y == m) {
                    ++x;
                    if (x % 2) y = m - 1;
                    else y = 0;
                }
            }
            sum += ts;
            ++cnt;
            char tc = 'A';
            for (int i = 1; i < 26; ++i) if (lol.find('A' + i) == lol.end()) tc = 'A' + i;
            for (int i = 0; i < cls.size(); ++i) ans[cls[i].first][cls[i].second] = tc;
        }
    }
    cout << cnt << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cout << ans[i][j];
        cout << '\n';
    }
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}