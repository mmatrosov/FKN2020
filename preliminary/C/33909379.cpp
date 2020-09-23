#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); ++i)

const int MAXN = 1e5 + 5;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    rep(i, n) {
        cin >> a[i];
    }
    sort(a, a + n);
    n = unique(a, a + n) - a;
    int k;
    cin >> k;
    rep(i, k) {
        int x;
        cin >> x;
        int id = lower_bound(a, a + n, x) - a;
        cout << id << '\n';
    }
}
