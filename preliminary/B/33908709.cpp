#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ll k1, b1, k2, b2;
    cin >> k1 >> b1 >> k2 >> b2;
    if (k1 == k2) {
        if (b1 == b2) {
            cout << "coincide" << endl;
        } else {
            cout << "parallel" << endl;
        }
    } else {
        ld x = (ld)(b2 - b1) / (k1 - k2);
        ld y = k1 * x + b1;
        cout.precision(10);
        cout.setf(ios::fixed);
        cout << "intersect" << endl;
        cout << x << ' ' << y << endl;
    }
}