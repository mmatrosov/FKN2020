#include <iostream>
#include <vector>

using namespace std;

int main() {
    size_t n;
    cin >> n;
    vector<vector<size_t>> opera(n, vector<size_t>(n));
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            cin >> opera[i][j];
        }
    }
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            for (size_t k = 0; k < n; k++) {
                if (opera[opera[i][j]][k] != opera[i][opera[j][k]]) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}
