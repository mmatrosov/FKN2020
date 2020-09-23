#include <iostream>
#include <vector>
using namespace std;

int main() {
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<bool>> field(n + 2, vector<bool>(m + 2));
        for (int i = 0; i < k; ++i) {
                int x, y;
                cin >> x >> y;
                field[x][y] = 1;
        }
        for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                        int cnt = 0;
                        for (int x = -1; x <= 1; ++x) {
                                for (int y = -1; y <= 1; ++y) {
                                        cnt += field[i + x][j + y];
                                }
                        }

                        cout << (field[i][j] ? "*" : to_string(cnt)) << ' ';
                }
                cout << endl;
        }
}
