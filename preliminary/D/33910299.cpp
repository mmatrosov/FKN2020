#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define double long double
#define _ << ' ' <<
#define For(i,z) for(int i=0;i<int32_t(z);++i)
#define printObj(a) {for (auto &i : a) cout << i << ' '; cout << '\n';}
#define sqr(a) ((a)*(a))

#define pii pair<int, int>
#define pdd pair<double, double>
#define x first
#define y second

template<typename T>
using orset = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T, typename K>
using ormap = tree <T, K, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T, typename K> inline void umax(T &a, K b) { a = max(a, (T)b); }
template<typename T, typename K> inline void umin(T &a, K b) { a = min(a, (T)b); }
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int32_t N = 1e5 + 10;
const int64_t INF = 1e16;
const pair<int64_t, int64_t> PINF = make_pair(INF, INF);
const double EPS = 1e-7;
const int MOD = 1e9 + 7;
const int II = 1e9 + 10;
const int64_t AMOD = 99194853094755497;
const double PI = 3.14159265359;

double pif(pdd a) {
    return sqrt(a.x*a.x + a.y*a.y);
}

double angleBtw(pdd a, pdd b) {
    double x = pif(a), y = pif(b), z = pif({a.x-b.x,a.y-b.y});
    double c = (x*x+y*y-z*z)/x/y/2;
    return acos(c);
}

int32_t main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    pdd ar[2];
    For (i, 2) cin >> ar[i].x >> ar[i].y;

    double ans = pif(ar[0]) + pif(ar[1]);
    if (ar[0] != make_pair(0.0L, 0.0L) && ar[1] != make_pair(0.0L, 0.0L)) {
        double d = abs(pif(ar[0]) - pif(ar[1]));
        double a = angleBtw(ar[0], ar[1]);
        umin(ans, a * pif(ar[0]) + d);
        umin(ans, a * pif(ar[1]) + d);
    }

    cout.precision(8);
    cout << fixed << ans << '\n';
}
