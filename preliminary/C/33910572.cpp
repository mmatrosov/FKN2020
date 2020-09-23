#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    int k; cin >> k;
    while (k--) {
        int p; cin >> p;
        cout << lower_bound(all(v), p) - v.begin() << '\n';
    }

}