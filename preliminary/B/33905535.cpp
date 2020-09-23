#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int k1, b1;
    int k2, b2;
    cin >> k1 >> b1;
    cin >> k2 >> b2;
    if (k1 == k2) {
        if (b1 == b2) {
            cout << "coincide";
        } else {
            cout << "parallel";
        }
    } else {
        cout << "intersect" << "\n";
        double x = double(b2 - b1) / double(k1 - k2);
        double y = double(k1) * x + double(b1);
        cout << fixed << setprecision(6);
        cout << x << " " << y;
    }


    return 0;
}
