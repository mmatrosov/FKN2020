#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back

const int MAXN = 1e4 + 10;

int main()
{
    int k1, b1, k2, b2;
    cin >> k1 >> b1 >> k2 >> b2;
    if (k1 == k2) {
        if (b1 == b2) {
            cout << "coincide";
            return 0;
        }
        cout << "parallel";
        return 0;
    }
    cout << "intersect" << endl;
    double x = double(b2 - b1) / (k1 - k2);
    double y = k1 * x + b1;
    cout << fixed << setprecision(10) << x << " " << y;
    return 0;
}

