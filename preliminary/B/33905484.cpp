#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ld k1, b1, k2, b2;
    cin >> k1 >> b1 >> k2 >> b2;

    if (k1 == k2)
    {
        if (b1 == b2)
            cout << "coincide" << endl;
        else
            cout << "parallel" << endl;
        return 0;
    }

    cout << "intersect" << endl;

    ld x = (b2 - b1) / (k1 - k2);
    cout << fixed << setprecision(20) << x << " " << k1 * x + b1 << endl;

    return 0;
}
