#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;


int main() {
    vector<int> pos;
    pos.push_back(1);
    for (int i = 2; i < 100000; ++i) {
        pos.push_back(4 * i - 4);
    }

    int k;
    cin >> k;

    if (*lower_bound(pos.begin(), pos.end(), k) != k) {
        cout << "NO";

        return 0;
    }

    cout << "YES";

    return 0;
}
