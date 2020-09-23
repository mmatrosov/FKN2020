#include <algorithm>
#include <vector>
// reminder that PascalCase for function is disgusting
void swap_columns(std::vector<std::vector<int>> &matrix, size_t const i,
                  size_t const j) {
    // IDK if std::swap(x, x) is allowed, so let's special-case i == j.
    if (i == j) {
        return;
    }
    for (std::vector<int> &row : matrix) {
        std::swap(row[i], row[j]);
    }
}