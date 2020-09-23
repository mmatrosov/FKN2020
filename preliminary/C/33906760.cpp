#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    set<int> s;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        s.insert(x);
    }

    vector<int> have;
    for (const auto & it : s) {
        have.emplace_back(it);
    }

    int k;
    cin >> k;
    for (int query = 0; query < k; ++query) {
        int p;
        cin >> p;

        int it = lower_bound(have.begin(), have.end(), p) - have.begin();

        cout << it << '\n';
    }
}
