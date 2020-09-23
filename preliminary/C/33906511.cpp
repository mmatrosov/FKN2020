#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    set <int> a;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        a.insert(val);
    }
    int k;
    cin >> k;
    pair <int, int> b[k];
    for (int i = 0; i < k; ++i) cin >> b[i].first;
    for (int i = 0; i < k; ++i) b[i].second = i;
    sort(b, b + k);
    int ans[k];
    int id = 0;
    for (int i = 0; i < k; ++i) {
        while (!a.empty() && *a.begin() < b[i].first) {
            a.erase(a.begin());
            ++id;
        }
        ans[b[i].second] = id;
    }
    for (int i = 0; i < k; ++i) cout << ans[i] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
