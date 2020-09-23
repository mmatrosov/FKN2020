#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    map<int, bool> used;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        if (!used[b]) {
            used[b] = 1;
            a.push_back(b);
        }
    }
    sort(a.begin(), a.end());
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int p;
        cin >> p;
        int j = lower_bound(a.begin(), a.end(), p) - a.begin();
        if (j == a.size()) {
            cout << j << "\n";
            continue;
        }
        if (a[j] >= p) --j;
        cout << j + 1 << "\n";
    }
    return 0;
}
