//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    cout.precision(20);
    int k1, b1, k2, b2;
    cin >> k1 >> b1 >> k2 >> b2;
    if (k1 == k2 && b1 == b2) {
        cout << "coincide" << endl;
    }
    else if (k1 == k2) {
        cout << "parallel" << endl;
    }
    else {
        cout << "intersect" << endl;
        double x = double(b1 - b2) / (k2 - k1);
        double y = k1 * x + b1;
        cout << x << ' ' << y << endl;
    }
    return 0;
}
