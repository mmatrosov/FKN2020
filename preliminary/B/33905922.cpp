#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    int k1, b1, k2, b2;
    cin >> k1 >> b1 >> k2 >> b2;
    if (k1 == k2) {
        if (b1 == b2) {
            cout << "coincide" << endl;
        } else {
            cout << "parallel" << endl;
        }
    } else {
        cout << "intersect" << endl;
        ld x = (ld(b2) - b1) / (k1 - k2);
        ld y = k1 * x + b1;
        cout << setprecision(10) << fixed << x << " " << y << endl;
    }
}
