#include <bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;

void PUNKS_NOT_DEAD() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    a.resize(unique(all(a)) - a.begin());
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> n;
        cout << lower_bound(all(a), n) - a.begin() << '\n';
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    PUNKS_NOT_DEAD();
}