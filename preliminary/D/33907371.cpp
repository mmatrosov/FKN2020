// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma warning(disable : 4996)

// by ivan esipov

#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define len(x) (int)(x).size()
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
const int maxn = 3e5 + 500;
const int mod = 1e9 + 7;
const int INF = 1e18 + 1;
// const ld eps = 1e-8;
// mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
struct pt {
    ld x, y;
};
ld dist(pt a, pt b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
ld cosangle(pt a, pt b, pt c) {
    ld A = dist(b, c);
    ld B = dist(a, c);
    ld C = dist(a, b);
    return (C * C + B * B - A * A) / (2.0 * B * C);
}
ld rad_dist(pt a, pt b) {
    ld R = dist(a, {0, 0});
    ld alpha = cosangle({0, 0}, a, b);
    ld acs = acos(alpha);
    return acs * R;
}
signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    pt a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    ld ad = dist(a, {0, 0});
    ld bd = dist(b, {0, 0});
    ld ans = ad + bd;
    if (ad > bd) {
        swap(ad, bd);
        swap(a, b);
    }
    ans = min(ans, bd - ad + rad_dist(a, b));
    cout << fixed << setprecision(10) << ans;
    return 0;
}