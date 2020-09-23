#include <iostream>
#define double long double
using namespace std;

int main()
{
    double k1, b1, k2, b2;
    cin >> k1 >> b1 >> k2 >> b2;
    cout.precision(10);
    if (k1 == k2 && b1 == b2) {
        cout << "coincide";
        return 0;
    }
    if (k1 == k2) {
        cout << "parallel";
        return 0;
    }
    cout << "intersect\n";
    double x = (b1 - b2) / (k2 - k1);
    cout << x << ' ' << k1 * x + b1;
    return 0;
}
