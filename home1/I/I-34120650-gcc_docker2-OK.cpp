#include <iostream>
#include <vector>

bool check_operation() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int> > matr(n);
    for (int i = 0; i < n; ++i) {
        matr[i].resize(n);
        for (int e = 0; e < n; ++e) {
            std::cin >> matr[i][e];
        }
    }
    for (int i = 0; i < n; i++)
        for (int e = 0; e < n; e++)
            for (int j = 0; j < n; j++) {
                if (matr[matr[i][e]][j] != matr[i][matr[e][j]])
                    return 0;
            }
    return 1;
}

signed main() {
    if (check_operation()) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}
