#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define pb push_back
#define pi pair<int, int>
#define l first
#define r second

using namespace std;

const int maxn = 2e5 + 1;
const long long inf = 1e15;

char v[1000][1000];

int i = 0, j = 0;
int n, m;
int cnt = 1;
int fg = 0;

void upd() {
    if (fg == 1) {
        if (j == m - 1) {
            j = 0; ++i;
        } else {
            ++j;
        }
        return;
    }
    if (fg == 2) {
        if (j == 0) {
            j = m - 1;
            ++i;
        } else {
            --j;
        }
        return;
    }
    if (i % 2) {
        if (j == 0) ++i;
        else --j;
    } else {
        if (j == m - 1) ++i;
        else ++j;
    }
}

void add(char c) {
    int x = cnt;
    while (x--) {
        v[i][j] = c;
        upd();
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    char lc = 'B';
    char ltc = 'Q';
    while ((cnt + 1) * (cnt + 2) / 2 <= n * m) {
        if (cnt > m) {
            if (!fg) fg = 1 + i % 2;
            if (cnt % 2) add('X');
            else add('Y');
        } else {
            if (i % 2) {
                if (j + 1 < cnt) {
                    if (ltc == 'R') {
                        add('S');
                        ltc = 'S';
                    } else if (ltc == 'S') {
                        add('Q');
                        ltc = 'Q';
                    } else {
                        add('R');
                        ltc = 'R';
                    }
                    ++cnt;
                    continue;
                }
                if (lc == 'C') {
                    add('D');
                    lc = 'D';
                } else {
                    add('C');
                    lc = 'C';
                }
            } else {
                if (j + cnt > m) {
                    if (ltc == 'R') {
                        add('S');
                        ltc = 'S';
                    } else if (ltc == 'S') {
                        add('Q');
                        ltc = 'Q';
                    } else {
                        add('R');
                        ltc = 'R';
                    }
                } else {
                    if (lc == 'A') {
                        add('B');
                        lc = 'B';
                    } else {
                        add('A');
                        lc = 'A';
                    }
                }
            }
        }
        ++cnt;
    }
    while (i < n) {
        v[i][j] = 'W';
        upd();
    }
    cout << cnt << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << v[i][j];
        cout << '\n';
    }
    return 0;
}
