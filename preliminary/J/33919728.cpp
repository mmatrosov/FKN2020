#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); ++i)

const int MAXN = 1005;
int n, m;
int a[MAXN][MAXN];
bool used[26];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void adv(int &x, int &y) {
    if (x & 1) {
        y--;
        if (y == -1) {
            y = 0;
            x++;
        }
    } else {
        y++;
        if (y == m) {
            y = m - 1;
            x++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int k = 0;
    for (k = 0; (k + 1) * (k + 2) / 2 <= n * m; ++k) {}

    vector<int> segs;
    for (int i = 1; i <= k; ++i) {
        segs.push_back(i);
    }

    if (k * (k + 1) / 2 < n * m) {
        segs.back() = n * m - (k - 1) * k / 2; 
    }

    rep(i, n) {
        rep(j, m) {
            a[i][j] = -1;
        }
    }

    int x = 0, y = -1;
    for (auto len : segs) {
        int nx = x, ny = y;
        rep(i, 26) {
            used[i] = false;
        }

        rep(i, len) {
            adv(nx, ny);
            rep(t, 4) {
                int tx = nx + dx[t], ty = ny + dy[t];
                if (tx < 0 || tx >= n || ty < 0 || ty >= m || a[tx][ty] == -1) continue;
                used[a[tx][ty]] = true;
            }
        }

        int c = 0;
        while (used[c]) c++;

        rep(i, len) {
            adv(x, y);
            a[x][y] = c;
        }
    }

    cout << k << endl;
    rep(i, n) {
        rep(j, m) {
            cout << (char)('A' + a[i][j]);
        }
        cout << '\n';
    }
}
