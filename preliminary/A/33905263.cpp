#include <iostream>

using namespace std;

int main()
{
    int k;
    cin >> k;
    if (k % 2) {
        std::cout << (k == 1 ? "YES" : "NO");
        return 0;
    }
    k = k / 2 + 2;
    std::cout << (k % 2 ? "NO" : "YES");
    return 0;
}
