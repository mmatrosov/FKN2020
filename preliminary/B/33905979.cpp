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
    int k1, b1, k2, b2;
    cin >> k1 >> b1 >> k2 >> b2;
    if (k1 == k2 && b1 == b2)
        cout << "coincide";
    else if (k1 == k2)
        cout << "parallel";
    else
    {
        cout << "intersect\n";
        ld x = ((ld)b2 - b1) / (k1 - k2);
        ld y = k1 * x + b1;
        cout.precision(20);
        cout << fixed << x << " " << y;
    }
}
