#include <bits/stdc++.h>
#define int long long
#define to first
#define wt second
using namespace std;

const int N = 1001;
char t[N][N];
int n, m;

char choose_char(int r, int c, char ch, int mx) {
    set<char> bad = {ch};
    if (r % 2 == 0 && r != 0) {
        for (int g = c; g < m && g < c + mx; g++) bad.insert(t[r - 1][g]);
    }
    if (r % 2 == 1) {
        for (int g = c; g >= 0 && g > c - mx; --g) bad.insert(t[r - 1][g]);
    }
    char good = ch;
    while (bad.count(good)) {
        good++;
        if (good > 'Z') good = 'A';
    };
    return good;
}

signed main() {
    cin >> n >> m;
    vector<int> a;
    int cur = 0;
    for (int i = 1; i < 10000; i++) cur += i, a.push_back(cur);
    int cnt = upper_bound(a.begin(), a.end(), n * m) - a.begin();
    cout << cnt << "\n";
    int r = 0, c = 0;
    char ch = 'A';
    int left = 1, mx = 1;
    for (int i = 0; i < n * m; i++) {
        t[r][c] = ch;
        left--;
        if (!left) {
            if (mx != cnt) {
                ch = choose_char(r, c, ch, mx + 1);
            }
            mx++;
            left = mx;
        }
        if (c == m - 1 && r % 2 == 0 || !c && r % 2 == 1) r++;
        else if (r % 2 == 0) c++;
        else c--;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << t[i][j];
        cout << "\n";
    }
}
