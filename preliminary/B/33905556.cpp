#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;


using ld = long double;


int main() {
    cout << fixed;

    cout.precision(10);

    ld k1, b1, k2, b2;
    cin >> k1 >> b1 >> k2 >> b2;

    if (k1 == k2) {
        if (b1 == b2) {
            cout << "coincide";

            return 0;
        }

        cout << "parallel";

        return 0;
    }

    cout << "intersect" << '\n';

    ld x = (b2 - b1) / (k1 - k2);
    ld y = k1 * x + b1;

    cout << x << ' ' << y;

    return 0;
}


/*

y = k1x + b1;
y = k2x + b2;

k1x + b1 = k2x + b2;

x = (b2 - b1) / (k1 - k2)

*/