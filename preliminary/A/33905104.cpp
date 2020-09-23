#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

signed main() {
#ifdef LOCAL
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll k;
    cin >> k;

    if (k == 1 || k % 4 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
