// Bippolar disorder is very cool

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

typedef int64_t ll;
typedef long double ld;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] *= -1;
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    ll m;
    cin >> m;
    for (ll i = 0; i < m; ++i) {
        ll p;
        cin >> p;
        p *= -1;
        cout << a.end() - lower_bound(a.begin(), a.end(), p + 1) << "\n";
    }
    return 0;
}
