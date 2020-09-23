#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> mat(n, std::vector<int>(n));

    for (auto &line : mat) {
        for (auto &element : line) {
            std::cin >> element;
        }
    }

    bool assoc = true;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (mat[i][mat[j][k]] != mat[mat[i][j]][k]) {
                    assoc = false;
                }
            }
        }
    }
    if (assoc) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}