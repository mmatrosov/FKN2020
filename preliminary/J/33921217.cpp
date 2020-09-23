#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define int long long

using namespace std;
const int INF = 2e15;
const int MB = 20;
const int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    int x = 0, y = 0, r = 1;
    vector<vector<char>> a(n, vector<char>(m, ' '));
    int cnt = n * m, now = 1;

    vector<int> goX = { 0, 0, -1, 1 };
    vector<int> goY = { 1, -1, 0, 0 };
    int ans = 0;
    while (cnt) {
        if (now * 2 + 1 > cnt) now = cnt;
        vector<bool> bad(26);
        int nx = x, ny = y, nr = r;
        for (int i = 0; i < now; i++) {
            for (int j = 0; j < 4; j++) {
                int one = nx + goX[j];
                int two = ny + goY[j];
                if (one >= 0 && two >= 0 && one < n && two < m && a[one][two] != ' ') bad[a[one][two] - 'A'] = true;
            }
            if (nr) {
                if (ny == m - 1) {
                    nx++;
                    nr = 0;
                }
                else {
                    ny++;
                }
            }
            else {
                if (!ny) {
                    nx++;
                    nr = 1;
                }
                else {
                    ny--;
                }
            }
        }
        nx = x; ny = y;
        int id = 0;
        while (bad[id]) id++;
        for (int i = 0; i < now; i++) {
            a[nx][ny] = (char)(id + 'A');
            if (r) {
                if (ny == m - 1) {
                    nx++;
                    r = 0;
                }
                else {
                    ny++;
                }
            }
            else {
                if (!ny) {
                    nx++;
                    r = 1;
                }
                else {
                    ny--;
                }
            }
        }
        x = nx;
        y = ny;
        cnt -= now;
        now++;
        ans++;
    }

    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j];
        }
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed;
    cout.precision(12);
    //srand(time(0));
    int t = 1;
    //int t;
    //cin >> t;
    while (t--) solve();
}