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


int main() {
    double k1, a1, k2, a2;
    cin >> k1 >> a1 >> k2 >> a2;
    if (k1 == k2 && a1 == a2) {
        cout << "coincide";
        return 0;
    }
    if (k1 == k2) {
        cout << "parallel";
        return 0;
    }
    double x = (a2 - a1) / (k1 - k2);
    double y = k1 * x + a1;
    cout << "intersect" << endl;
    cout << setprecision(8) << x << ' ' << y;
}
