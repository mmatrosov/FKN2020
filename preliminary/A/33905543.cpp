#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define l first
#define r second
#define pb push_back
#define int long long

using namespace std;

const int maxn = 2e5 + 1, mod = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    if (n == 1) {
        cout << "YES";
        return 0;
    }
    cout << (n % 4 ? "NO" : "YES");
    return 0;
}
