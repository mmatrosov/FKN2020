#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define pb push_back
#define pf push_front
#define ft first
#define sc second
#define all(v) v.begin(), v.end()
using namespace std;
const int maxn = 100000, inf = 1e18;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << "YES\n";
        return 0;
    }
    if (n % 4 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
