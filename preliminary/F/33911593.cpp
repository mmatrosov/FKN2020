#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <complex>
//#pragma GCC optimize("O3")
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define fo(i, n) for (int i = 0; i < n; ++i)
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define mp make_pair
#define out(t, a) {copy(all(a), ostream_iterator<t>(cout, " ")); cout << '\n';}
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
struct pt {
      int x;
      int y;
      pt() : x(0), y(0)
      {}
};
istream& operator>>(istream& is, pt& p) {
      is >> p.x >> p.y;
      return is;
}
ostream& operator<<(ostream& os, pt& p) {
      os << p.x << " " << p.y;
      return os;
}
int main()
{
    io;
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    fo(i, n) cin >> a[i];
    sort(all(a));
    if (k >= n) {
        fo(i, k - n) a.pb(a.back() + 1);
        fo(i, k) cout << a[i] << ' ';
        cout << '\n';
        return 0;
    }
    ll d[k+1][n+1], b[k+1][n+1];
    fo(i, n+1) d[0][i] = 0;
    for (int j = 1; j <= k; ++j) {
        for (int i = j + 1; i <= n; ++i) {
            d[j][i] = 0;
            for (int m = j; m < i; ++m) {
                if (d[j][i] < d[j-1][m] + (i - m)*a[m]) {
                    d[j][i] = d[j-1][m] + (i - m)*a[m];
                    b[j][i] = m;
                }
            }
        }
    }
    //cout << d[k][n] << '\n';
    vector<ll> ans;
    int v = n;
    fo(i, k) {
        v = b[k - i][v];
        ans.pb(a[v]);
    }
    reverse(all(ans));
    out(int, ans);
    return 0;
}
