#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    map<int, int> m;
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || v[i] != v[i - 1]) {
            m[v[i]] = k;
            k++;
        }
    }

    int q;
    cin >> q;
    while (q) {
        q--;
        int p;
        cin >> p;
        auto t = m.upper_bound(p - 1);
        if (t == m.end()) {
            cout << k << endl;
        } else {
            cout << t->second << endl;
        }
    }
}
