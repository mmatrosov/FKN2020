//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const vector<pair<int, int> > dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > ans(n, vector<int>(m, -1));
    vector<pair<int, int> > ord;
    for (int it = 0; it < n * m; it++) {
        int x = -1, y = -1;
        if (ord.empty()) x = 0, y = 0;
        else {
            int x1 = ord.back().first, y1 = ord.back().second;
            if (x1 % 2 == 0) {
                if (y1 < m - 1) x = x1, y = y1 + 1;
                else x = x1 + 1, y = y1;
            }
            else {
                if (y1 > 0) x = x1, y = y1 - 1;
                else x = x1 + 1, y = y1;
            }
        }
        ord.push_back({x, y});
    }
    // for (auto elem: ord) cout << elem.first << ' ' << elem.second << endl;
    int cnt = 1;
    int cur = 0;
    while (cur < n * m) {
        int right = (n * m - cur - cnt >= cnt + 1 ? cur + cnt : n * m);
        for (int val = 0; val < 26; val++) {
            bool ok = 1;
            for (int i = cur; i < right; i++) {
                for (auto elem: dir) {
                    int x1 = ord[i].first + elem.first, y1 = ord[i].second + elem.second;
                    if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && ans[x1][y1] == val) {
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok) {
                for (int i = cur; i < right; i++) {
                    ans[ord[i].first][ord[i].second] = val;
                }
                break;
            }
        }
        cur = right;
        cnt++;
    }
    cout << cnt - 1 << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << char(ans[i][j] + 'A');
        }
        cout << endl;
    }
    return 0;
}
