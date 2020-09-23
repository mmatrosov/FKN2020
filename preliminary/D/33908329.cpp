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
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ld r1 = sqrt(x1*x1 + y1*y1), r2 = sqrt(x2*x2 + y2*y2), l = 0, r = min(r1, r2), a = abs(atan2(x1*y2 - x2*y1, x1*x2 + y1*y2));
    ld pi = acos(-1);
    a = min(a, 2*pi - a);
    cout.precision(30);
    if (a < 2) {
        cout << a*r + abs(r1 - r2);
    } else {
        cout << r1 + r2;
    }
    return 0;
}
