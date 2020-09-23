#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    ll k1, b1, k2, b2;
    cin >> k1 >> b1 >> k2 >> b2;


    cout << fixed << setprecision(11);

    if (k1 == k2) {
        if (b1 == b2) {
            cout << "coincide";
        }
        else {
            cout << "parallel";
        }
    }
    else {
        cout << "intersect\n";
        double x = (b2 - b1) / (double)(k1 - k2),
            y = k1 * x + b1;
        cout << x << " " << y << "\n";
    }

	return 0;
}