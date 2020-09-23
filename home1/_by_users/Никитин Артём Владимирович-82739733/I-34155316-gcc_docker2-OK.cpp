#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int a[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
        }
    }
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            for (int z = 0; z < n; z++) {
                if (a[a[x][y]][z] != a[x][a[y][z]]) {
                    std::cout << "NO\n";
                    return 0;
                }
            }
        }
    }
    std::cout << "YES\n";
    return 0;
}