#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int k;
    cin >> k;
    if (k % 4 && k > 1) cout << "NO";
    else cout << "YES";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
