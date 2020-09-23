#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int A[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> A[i][j];
        }
    }
    bool check = 1;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            for (int z = 0; z < n; z++) {
                if (A[A[x][y]][z] != A[x][A[y][z]]) {
                    check = 0;
                }
            }
        }
    }
    if (!check) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
    }
}