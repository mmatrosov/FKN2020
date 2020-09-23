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
    int k;
    cin >> k;
    if (k == 0)
    {
        cout << "NO";
        return;
    }
    if (k == 1)
    {
        cout << "YES";
        return;
    }
    if (k % 4 == 0)
        cout << "YES";
    else
        cout << "NO";
}