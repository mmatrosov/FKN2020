#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    double k1, k2, b1, b2;
    cin >> k1 >> b1 >> k2 >> b2;

    if (k1 == k2 && b1 == b2)
    {
        cout << "coincide";
        return 0;
    }
    if (k1 == k2)
    {
        cout << "parallel";
        return 0;
    }

    double x = (b2 - b1) / (k1 - k2);
    double y = k1 * x + b1;

    cout << "intersect\n";
    cout << fixed << setprecision(7) << x << " " << y;


    return 0;
}
