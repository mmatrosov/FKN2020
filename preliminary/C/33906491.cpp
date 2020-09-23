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
    vector<int> vec(n, 0);
    for (int d = 0; d < n; d++) {
        cin >> vec[d];
    }
    sort(all(vec));
    vector<int>::iterator it = unique(all(vec));
    vec.erase(it, vec.end());
    int k;
    cin >> k;
    for (int d = 0; d < k; d++) {
        int p;
        cin >> p;
        vector<int>::iterator it = lower_bound(all(vec), p);
        int dist = it - vec.begin();
        cout << dist << "\n";
    }
}
