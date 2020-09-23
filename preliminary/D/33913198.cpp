#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

struct point {
    ld x, y;
    void in() {
        cin >> x >> y;
    }
    point(ld x, ld y) : x(x), y(y) {}
};

struct vect {
    ld x, y;
    vect(ld x, ld y) : x(x), y(y) {}
};

ld dist(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void ok(vect& v) {
    ld d = sqrt(v.x * v.x + v.y * v.y);
    v.x /= d;
    v.y /= d;
}

void mult(vect & v, ld x) {
    v.x *= x;
    v.y *= x;
}

ld len(vect v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

int main() {
    //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //cout << acos(1);
    point F(0, 0), T(0,0);
    F.in();
    T.in();
    ld d1 = dist(F, point(0, 0)), d2 = dist(T, point(0, 0));
    ld ans = d1 + d2;
    vect v1(F.x, F.y), v2(T.x, T.y);
    ok(v1), ok(v2);
    //cout << ans << endl;
    if (d1 > d2) {
        mult(v1, d2);
        ld tmp = dist(F, point(v1.x, v1.y));
        ld cos = (v1.x * v2.x + v1.y * v2.y) / (len(v1) * len(v2));
        //cout << v1.x << " " << v1.y << " " << v2.x << " " << v2.y << endl;
        //cout << cos << " h " << acos(min((ld)1, cos)) << endl;
        tmp += acos(max((ld)-1, min((ld)1, cos))) * d2;
        ans = min(ans, tmp);
        //cout << tmp << endl;
    } else {
        ld cos = (v1.x * v2.x + v1.y * v2.y) / (len(v1) * len(v2));
        ld tmp = acos(max((ld)-1, min((ld)1, cos))) * d1;
        mult(v2, d1);
        tmp += dist(T, point(v2.x, v2.y));
        ans = min(ans, tmp);
        //cout << v1.x << " " << v1.y << " " << v2.x << " " << v2.y << endl;
        //cout << cos << " p " << acos(max((ld)-1, min((ld)1, cos))) << endl;
        //cout << tmp << endl;
    }
    cout.precision(15);
    cout << fixed << ans;
    return 0;
}
