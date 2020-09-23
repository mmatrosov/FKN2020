#include <bits/stdc++.h>

using namespace std;

void solve() {
    double pi = acos(-1);
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double l1 = sqrt(x1 * x1 + y1 * y1);
    double l2 = sqrt(x2 * x2 + y2 * y2);
    if (l1 > l2) {
        swap(l1, l2);
        swap(x1, x2);
        swap(y1, y2);
    }
    double way = 0;
    double ang1 = atan2(y1, x1);
    double ang2 = atan2(y2, x2);
    double ang = abs(ang1 - ang2);
    way += min(ang * l1, (2 * pi - ang) * l1);
    way += l2 - l1;
    cout << fixed << setprecision(7) << min(l1 + l2, way);
}

int main() {
#ifdef OLYMP
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
