#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve();

signed main()
{
#ifdef _______
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
#else
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    int _ = _ = _ = 1;
    for (_; _; --_)
        solve();
}

const int N = 2e6 + 13, mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> in(n);
    for (int i = 0; i < n; i++)
        cin >> in[i];
    sort(in.begin(), in.end());
    in.resize(unique(in.begin(), in.end()) - in.begin());
    int k;
    cin >> k;
    while (k--)
    {
        int p;
        cin >> p;
        cout << lower_bound(in.begin(), in.end(), p) - in.begin() << '\n';
    }
}