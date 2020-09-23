#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int k;
    cin >> k;
    if ((k + 4) % 4 == 0 || k == 1) cout << "YES";
    else cout << "NO";
}
