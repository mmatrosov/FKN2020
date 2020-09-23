//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int p;
        cin >> p;
        int ind = lower_bound(a.begin(), a.end(), p) - a.begin();
        cout << ind << '\n';
    }
    return 0;
}
