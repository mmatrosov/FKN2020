#include <bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;

void PUNKS_NOT_DEAD() {
    int k;
    cin >> k;
    cout << (k == 1 || k % 4 == 0 ? "YES" : "NO");
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    PUNKS_NOT_DEAD();
}