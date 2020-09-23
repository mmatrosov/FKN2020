#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define F first
#define S second
#define pb push_back
mt19937 rnd;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ld k1, b1, k2, b2;
    cin >> k1 >> b1 >> k2 >> b2;
    if (k1 == k2) {
        if (b1 == b2) {
            cout << "coincide\n";
        }
        else {
            cout << "parallel\n";
        }
    }
    else {
        ld x = (b2 - b1) / (k1 - k2);
        ld y = k1 * x + b1;
        cout << fixed << setprecision(12);
        cout << "intersect\n";
        cout << x << " " << y << "\n";
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
