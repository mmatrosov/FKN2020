#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <set>
#include <cmath>
#include <vector>
#include <bitset>
#include <iomanip>


using namespace std;

typedef long long ll;
typedef long double ld;

const ld PI = 3.141592653589;

ld a(ld x1, ld y1, ld x2, ld y2) {
    return abs(atan2(x1 * y2 - x2 * y1, x1 * x2 + y1 * y2));
}


int main() {
    ld x1, y1, l1;
    ld x2, y2, l2 = 0;
    cin >> x1 >> y1 >> x2 >> y2;
    l1 = sqrt(x1 * x1 + y1 * y1) + sqrt(x2 * x2 + y2 * y2);
    //cout << setprecision(8) << a(x1, y1, x2, y2);
    if (sqrt(x1 * x1 + y1 * y1) < sqrt(x2 * x2 + y2 * y2)) {
        l2 = sqrt(x2 * x2 + y2 * y2) - sqrt(x1 * x1 + y1 * y1);
        l2 += 2 * PI * sqrt(x1 * x1 + y1 * y1) / PI / 2 * a(x1, y1, x2, y2);
    } else {
        l2 = - sqrt(x2 * x2 + y2 * y2) + sqrt(x1 * x1 + y1 * y1);
        l2 += 2 * PI * sqrt(x2 * x2 + y2 * y2) / PI / 2 * a(x1, y1, x2, y2);
    }
    if (l2 < l1) cout << setprecision(16) << l2;
    else cout << setprecision(16) << l1;
}
