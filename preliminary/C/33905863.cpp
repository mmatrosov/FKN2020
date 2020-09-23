#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())
#define ld long double

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> cur(n);
    for (int i = 0; i < n; i++)
        cin >> cur[i];
    uniq(cur);
    cin >> n;
    for (int j = 0; j < n; j++)
    {
        int x;
        cin >> x;
        int pos = lower_bound(all(cur), x) - cur.begin();
        cout << pos << "\n";
    }
}
