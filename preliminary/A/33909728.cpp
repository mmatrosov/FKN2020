#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define int long long

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int k;
    cin >> k;
    for (int i = 1; ; ++i) {
        int x = i * i - (i - 2) * (i - 2);
        if (i == 1) x = 1;
        if (x == k) {
            cout << "YES";
            return 0;
        } else if (x > k) {
            cout << "NO";
            return 0;
        }
    }
}
