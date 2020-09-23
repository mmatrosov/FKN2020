#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i)
        std::cin >> v[i];
    std::sort(v.begin(), v.end());
    v.resize(std::unique(v.begin(), v.end()) - v.begin());
    int q;
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        int x;
        std::cin >> x;
        std::cout << lower_bound(v.begin(), v.end(), x) - v.begin() << '\n';
    }
    return 0;
}
