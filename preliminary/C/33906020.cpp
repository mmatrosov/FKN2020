#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> b = {a[0]};
    for (int i = 1; i < n; i++) if (a[i] != a[i - 1]) b.push_back(a[i]);
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int mx;
        cin >> mx;
        cout << lower_bound(b.begin(), b.end(), mx) - b.begin() << "\n";
    }
}
