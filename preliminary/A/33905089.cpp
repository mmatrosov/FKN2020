// Bippolar disorder is very cool

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef int64_t ll;

int main() {
    ll k;
    cin >> k;
    if (k == 1) {
        cout << "YES" << endl;
        return 0;
    }
    if ((k - 4) & 3) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}
