#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define ld long double

using namespace std;

const int maxn = 2e5 + 100;
const ll alpha = 29;
const ld eps = 1e-20;
const ll inf = 1e18;

void init() {
#ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifdef TEST
    freopen("!inp", "r", stdin);
    freopen("!out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    init();

    int n, m;
    cin >> n >> m;
    int sum = 0;
    int k = 1;
    while (sum + k <= n * m) {
        sum += k;
        k++;
    }
    k--;
    cout << k << endl;
    vector<int> foo;
    for (int i = 1; i < k - i + 1; i++) {
        foo.pb(i);
        foo.pb(k - i + 1);
    }
    if (k % 2 == 1) {
        foo.pb((k + 1) / 2);
    }
    if (foo.size() >= 2)
        foo[1] += n * m - sum;
    else
        foo[0] += n * m - sum;

    string res;
    char cur = 'A';
    for (auto ev : foo) {
        for (int i = 0; i < ev; i++) {
            res += cur;
        }
        if (cur == 'Z')
            cur = 'A';
        else
            cur++;
    }
    for (int i = m; i < n * m - 1; i += 2 * m) {
        reverse(res.begin() + i, res.begin() + i + m);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << res[i * m + j];
        }
        cout << "\n";
    }
    return 0;
}