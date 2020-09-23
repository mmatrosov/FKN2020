#include <iostream>
#include <vector>
using namespace std;

int main() {
        int n;
        cin >> n;

        vector<vector<int>> mat(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                        cin >> mat[i][j];
                }
        }

        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                        for (int k = 0; k < n; ++k) {
                                if (mat[mat[i][j]][k] != mat[i][mat[j][k]]) {
                                        cout << "NO" << endl;
                                        return 0;
                                }
                        }
                }
        }
        cout << "YES" << endl;
}
