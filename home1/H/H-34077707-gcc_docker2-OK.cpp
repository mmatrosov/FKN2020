#include <iostream>
#include <vector>

using namespace std;

const vector<pair<int, int> > dir = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
};

int main() {
    size_t n, m, k;
    cin >> n >> m >> k;
    vector<vector<bool>> is_bomb(n, vector<bool>(m));
    for (size_t i = 0; i < k; i++) {
        size_t x, y;
        cin >> x >> y;
        is_bomb[x - 1][y - 1] = true;
    }
    vector<vector<int>> cnt(n, vector<int>(m));
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            if (is_bomb[i][j]) {
                cnt[i][j] = -1;
                continue;
            }
            for (auto elem : dir) {
                int x = i + elem.first, y = j + elem.second;
                if (x >= 0 && x < n && y >= 0 && y < m && is_bomb[x][y]) {
                    cnt[i][j]++;
                }
            }
        }
    }
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            if (cnt[i][j] == -1) {
                cout << "* ";
            } else {
                cout << cnt[i][j] << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}
