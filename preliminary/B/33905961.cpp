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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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
    int k1, b1, k2, b2;
    cin >> k1 >> b1 >> k2 >> b2;
    if (k1 == k2) {
        if (b1 == b2) {
            cout << "coincide\n";
        } else {
            cout << "parallel\n";
        }
    } else {
        cout << "intersect\n";
        ld x = ((ld)1)*(b2-b1)/(k1-k2);
        ld y = x*k1 + b1;
        cout.precision(30);
        cout << x << ' ' << y << '\n';
    }
    return 0;
}
