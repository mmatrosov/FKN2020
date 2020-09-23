#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;


const int MAXN = 1001;


int a[MAXN][MAXN];


int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> ord;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; ++j) {
                ord.emplace_back(i, j);
            }
        } else {
            for (int j = m - 1; j >= 0; --j) {
                ord.emplace_back(i, j);
            }
        }
    }

    int curp = 0;
    int cs;
    int ocs;
    for (cs = 1; ; ++cs) {
        if (curp == n * m) {
            break;
        }

        if (curp + cs + cs + 1 > n * m) {
            ocs = cs;
            cs = n * m - curp;
        }

        int used[26];
        for (int i = 0; i < 26; ++i) {
            used[i] = 0;
        }

        for (int i = 0; i < cs; ++i) {
            int x = ord[curp + i].first;
            int y = ord[curp + i].second;

            vector<pair<int, int>> nbs;

            if (x > 0) {
                nbs.emplace_back(x - 1, y);
            }

            if (x < n - 1) {
                nbs.emplace_back(x + 1, y);
            }

            if (y > 0) {
                nbs.emplace_back(x, y - 1);
            }

            if (y < m - 1) {
                nbs.emplace_back(x, y + 1);
            }

            for (auto p : nbs) {
                int cl = a[p.first][p.second];

                if (cl == 0) {
                    continue;
                }

                used[cl - 1] = true;
            }
        }

        int c;
        for (c = 0; c < 26; ++c) {
            if (!used[c]) {
                for (int i = 0; i < cs; ++i) {
                    int x = ord[curp + i].first;
                    int y = ord[curp + i].second;

                    a[x][y] = c + 1;
                }

                curp += cs;

                break;
            }
        }

        if (c == 26) {
            return 1;
        }
    }

    cout << ocs << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << (char)('A' + a[i][j] - 1);
        }
        cout << '\n';
    }

    return 0;
}
