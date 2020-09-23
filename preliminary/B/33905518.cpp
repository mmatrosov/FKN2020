#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << setprecision(15);
    int k1, b1;
    int k2, b2;
    cin >> k1 >> b1 >> k2 >> b2;
    if (k1 == k2) {
        cout << (b1 == b2 ? "coincide":"parallel");
    }
    else {
        double x = 1.0 * (b2 - b1) / (k1 - k2);
        cout << "intersect\n";
        cout << x << " " << k1 * x + b1;
    }
}
