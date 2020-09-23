#include <iostream>
#include <vector>
const int N = 1001;

char kingdom[N][N];

enum filling_type {ABAB, CDCD, EFEF};
filling_type operator++(filling_type &was) {
    switch (was) {
    case ABAB:
        return was = CDCD;
    case CDCD:
        return was = EFEF;
    case EFEF:
        return was = ABAB;
    }
}
char sample(const filling_type &was, int x) {
    switch (was) {
    case ABAB:
        return x % 2 ? 'B' : 'A';
    case CDCD:
        return x % 2 ? 'D' : 'C';
    case EFEF:
        return x % 2 ? 'F' : 'E';
    }
}

int row(int cell_id, int n, int m) {
    return cell_id / m;
}

int column(int cell_id, int n, int m) {
    int r = row(cell_id, n, m);
    cell_id -= r * m;
    return r % 2 ? m - 1 - cell_id : cell_id;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> sizes;
    int sum = 0;
    while (sum + sizes.size() < n * m)
        sizes.push_back(sizes.size() + 1), sum += sizes.back();
    sizes.back() += n * m - sum;
    std::cout << sizes.size() << '\n';
    filling_type filling = ABAB;
    for (int past = 0, id = 0, i = 0, j = 0; id < sizes.size(); ++id) {
        int last_i = row(past + sizes[id] - 1, n, m);
        if (last_i != i)
            ++filling;
        for (int k = 0; k < sizes[id]; ++k) {
            kingdom[i=row(past+k,n,m)][j=column(past+k,n,m)] = sample(filling, id % 2);
        }
        past += sizes[id];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            std::cout << kingdom[i][j];
        std::cout << '\n';
    }
    return 0;
}
