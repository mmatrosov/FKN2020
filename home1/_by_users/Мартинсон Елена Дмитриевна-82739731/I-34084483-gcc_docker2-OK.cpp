#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }
    bool is_assosiate = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                int left_part = matrix[matrix[i][j]][k];
                int right_part = matrix[i][matrix[j][k]];
                if (left_part != right_part) {
                    is_assosiate = false;
                    break;
                }
            }
        }
    }
    if (is_assosiate) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    std::cout << "\n";



    return 0;
}
