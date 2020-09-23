#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int dir = 1;
    int i = 0, j = 0;
    int free = n * m;
    vector<vector<char>> a(n, vector<char>(m, ' '));
    int t = 1;
    set<char> st;
    int ans = 0;
    while (true) {
        if (free == 0) {
            break;
        }
        ans++;
        if (t + t + 1 > free) {
            t = free;
        }
        free -= t;
        st.clear();
        int i1 = i, j1 = j, dir1 = dir;
        for (int ii = 0; ii < t; ii++) {
            if (i1 > 0) {
                st.insert(a[i1 - 1][j1]);
            }
            if (i1 < n - 1) {
                st.insert(a[i1 + 1][j1]);
            }
            if (j1 > 0) {
                st.insert(a[i1][j1 - 1]);
            }
            if (j1 < m - 1) {
                st.insert(a[i1][j1 + 1]);
            }
            if (dir1 == 1 && j1 == m - 1) {
                i1++;
                dir1 = -dir1;
            } else if (dir1 == 1) {
                j1++;
            } else if (dir1 == -1 && j1 == 0) {
                i1++;
                dir1 = -dir1;
            } else {
                j1--;
            }
        }
        char tch = 'A';
        while (st.count(tch)) {
            tch++;
        }
        for (int ii = 0; ii < t; ii++) {
            a[i][j] = tch;
            if (dir == 1 && j == m - 1) {
                i++;
                dir = -dir;
            } else if (dir == 1) {
                j++;
            } else if (dir == -1 && j == 0) {
                i++;
                dir = -dir;
            } else {
                j--;
            }
        }
        t++;
    }
    cout << ans << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j];
        }
        cout << "\n";
    }
}

int main() {
#ifdef OLYMP
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
