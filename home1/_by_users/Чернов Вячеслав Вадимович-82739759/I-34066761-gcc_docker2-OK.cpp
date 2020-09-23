#include <iostream>
#include <vector>

int main() {
    int elements;
    std::cin >> elements;
    std::vector<std::vector<int>> result;
    result.resize(elements, std::vector<int>(elements));
    for (int i = 0; i < elements; ++i) {
        for (int j = 0; j < elements; ++j) {
            std::cin >> result[i][j];
        }
    }

    bool isAssociative = true;
    for (int i = 0; i < elements; ++i) {
        for (int j = 0; j < elements; ++j) {
            for (int k = 0; k < elements; ++k) {
                int value1 = result[result[i][j]][k];  // (x * y) * z
                int value2 = result[i][result[j][k]];  // x * (y * z)
                if (value1 != value2) {
                    isAssociative = false;
                }
            }
        }
    }

    if (isAssociative) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}
