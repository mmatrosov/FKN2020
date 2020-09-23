#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long double k1, b1, k2, b2;
    cin >> k1 >> b1 >> k2 >> b2;
    cout << fixed;
    cout.precision(7);
    if (k1 == k2) {
        if (b1 == b2) cout << "coincide";
        else cout << "parallel";
    }
    else {
        cout << "intersect" << endl;
        long double x = (b2 - b1) / (k1 - k2);
        long double y = k1 * x + b1;
        cout << x << " " << y;
    }
}

