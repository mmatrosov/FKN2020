#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define ld long double
#define ull unsigned long long
#define mp make_pair

using namespace std;

const ld inf = 1e9;
const ld eps = 1e-9;
const int bigConstant = 1000;
const int maxn = 3e3;

void init() {
#ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifdef TEST
    freopen("!inp", "r", stdin);
    freopen("!out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

ld sqr(ld a) {
    return a * a;
}

bool eq(const ld &x, const ld &y) {
    return fabs(x - y) < eps;
}

bool gr(ld x, ld y) {
    return x > y && (!eq(x, y));
}

struct Vector {
    ld x, y;
    ld len;
    Vector() {}
    Vector(ld nx, ld ny) {
        x = nx;
        y = ny;
        len = sqrt(sqr(x) + sqr(y));
    }
};

ld operator*(const Vector &v1, const Vector &v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

ld operator%(const Vector &v1, const Vector &v2) {
    return v1.x * v2.y - v2.x * v1.y;
}

Vector operator+(const Vector &v1, const Vector &v2) {
    return Vector(v1.x + v2.x, v1.y + v2.y);
}

Vector operator-(const Vector &v1, const Vector &v2) {
    return Vector(v1.x - v2.x, v1.y - v2.y);
}

Vector operator*(const Vector &v, const ld &x) {
    return Vector(v.x * x, v.y * x);
}

bool operator==(const Vector &v1, const Vector &v2) {
    return eq(v1.x, v2.x) && eq(v1.y, v2.y);
}

struct Line {
    ld a, b, c;
    Line() {}
    Line(ld na, ld nb, ld nc) {
        a = na;
        b = nb;
        c = nc;
    }
    Line(Vector v1, Vector v2) {
        a = v2.y - v1.y;
        b = v1.x - v2.x;
        c = -1 * (a * v1.x + b * v1.y);
    }

    ld operator()(const Vector &p) const {
        return p.x * this->a + p.y * this->b + this->c;
    }
};

Line operator+(const Line &l, const Vector &v) {
    ld a2b2 = sqr(l.a) + sqr(l.b);
    Vector v1(-l.a * l.c / a2b2, -l.b * l.c / a2b2);
    Vector v2 = v1 + (Vector(-l.b, l.a));
    v1 = v1 + v;
    v2 = v2 + v;
    return Line(v1, v2);
}
Line operator-(const Line &l, const Vector &v) {
    ld a2b2 = sqr(l.a) + sqr(l.b);
    Vector v1(-l.a * l.c / a2b2, -l.b * l.c / a2b2);
    Vector v2 = v1 + (Vector(-l.b, l.a));
    v1 = v1 - v;
    v2 = v2 - v;
    return Line(v1, v2);
}

struct Circle {
    Vector O;
    ld r;
    Circle() {}
    Circle(Vector nO, ld nr) {
        O = nO;
        r = nr;
    }
};

//Vector interLines(Line l1, Line l2) {
//	ld d = l1.a*l2.b - l2.a*l1.b;
//	if (eq(d, 0))
//		return Vector(inf, inf);
//	ld dx = l1.b*l2.c - l2.b*l1.c;
//	ld dy = l1.c*l2.a - l2.c*l1.a;
//	return Vector(dx / d, dy / d);
//}

Vector interLines(Line l1, Line l2) {
    if (fabs((l2.b * l1.a - l1.b * l2.a)) < eps) {
        return Vector(inf, inf);
    }
    return Vector((-l1.c * l2.b + l2.c * l1.b) / (l1.a * l2.b - l2.a * l1.b),
                  (l1.c * l2.a - l2.c * l1.a) / (l2.b * l1.a - l1.b * l2.a));
}

pair<Vector, Vector> interCircleLine(Circle c, Line l) {
    Vector toadd = c.O;
    c.O = c.O - toadd;
    l = l - (toadd);
    ld a2b2 = sqr(l.a) + sqr(l.b);
    Vector cur(-l.a * l.c / a2b2, -l.b * l.c / a2b2);
    if (gr(cur.len, c.r)) {
        return {Vector(inf, inf), Vector(inf, inf)};
    }
    ld len = sqrt(sqr(c.r) - sqr(cur.len));
    Vector n(-l.b, l.a);
    n = n * (len / n.len);
    Vector ans1 = cur + n + toadd;
    Vector ans2 = cur - n + toadd;
    return {ans1, ans2};
}

pair<Vector, Vector> interCircles(Circle c1, Circle c2) {
    Vector cur = c1.O;
    Circle nc1(c1.O - cur, c1.r);
    Circle nc2(c2.O - cur, c2.r);
    Line rados(2 * nc2.O.x, 2 * nc2.O.y, sqr(nc2.r) - sqr(nc1.r) - sqr(nc2.O.x) - sqr(nc2.O.y));
    auto ans = interCircleLine(nc1, rados);
    if (ans.ff == Vector(inf, inf))
        return ans;
    ans.ff = ans.ff + cur;
    ans.ss = ans.ss + cur;
    return ans;
}

ld distOnCircle(Vector &v1, Vector &v2, Circle &c) {
    ld ang = fabs(atan2((v1 - c.O) % (v2 - c.O), (v1 - c.O) * (v2 - c.O)));
    return c.r * ang;
}

ld distVectorLine(Vector v, Line l) {
    ld ans = (v.x * l.a + v.y * l.b + l.c) / sqrt(sqr(l.a) + sqr(l.b));
    return ans;
}

ld distVectorRay(Vector p, Vector a, Vector b) {
    if (p * (b - a) > 0)
        return distVectorLine(p, Line(a, b));
    else
        return (p - a).len;
}

ld distVectorSection(Vector p, Vector a, Vector b) {
    return max(distVectorRay(p, a, b), distVectorRay(p, b, a));
}

ld distLines(Line a, Line b) {
    ld a2b2 = sqr(a.a) + sqr(a.b);
    Vector cur(-a.a * a.c / a2b2, -a.b * a.c / a2b2);
    if (interLines(a, b) == Vector(inf, inf)) {
        return distVectorLine(cur, b);
    }
    return 0;
}

ld distRayLine(Vector a, Vector b, Line l) {
    Vector inter = interLines(Line(a, b), l);
    if (inter == Vector(inf, inf)) {
        return distVectorLine(a, l);
    }
}

Circle circleByVectors(Vector &v1, Vector &v2, Vector &v3) {
    Line l((v1 + v2) * 0.5, ((v1 + v2) * 0.5) + Vector(-(v2 - v1).y, (v2 - v1).x));
    Line l2((v1 + v3) * 0.5, ((v1 + v3) * 0.5) + Vector(-(v3 - v1).y, (v3 - v1).x));
    Vector O = interLines(l, l2);
    return Circle(O, (v1 - O).len);
}

bool isInCircle(Vector &v, Circle &c) {
    return (eq(c.r, (v - c.O).len));
}

bool threeInLine(Vector &a, Vector &b, Vector &c) {
    Line l(a, b);
    return eq(distVectorLine(c, l), 0);
}
bool vectorInSegment(Vector p, Vector a, Vector b) {
    if ((a == p) || (b == p))
        return false;
    if ((p - a) % (b - a) != 0)
        return false;
    if ((((b - a) * (p - a)) * ((a - b) * (p - b))) > 0)
        return true;
    return false;
}

ll tree[maxn];

ll f(ll x) {
    return x & (x + 1);
}

void add(ll pos, ll val) {
    while (pos < maxn) {
        tree[pos] += val;
        pos |= (pos + 1);
    }
}

ll prefsum(ll pos) {
    ll ans = 0;
    while (pos >= 0) {
        ans += tree[pos];
        pos = f(pos) - 1;
    }
    return ans;
}

int main() {
    init();

    ld x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    Vector v1(x1, y1);
    Vector v2(x2, y2);

    ld ans = fabs(v1.len - v2.len);

    ld minlen = min(v1.len, v2.len);

    ld ang = fabs(atan2(v1 % v2, v1 * v2));

    ans += ang * minlen;
    ans = min(ans, v1.len + v2.len);

    cout << fixed << setprecision(10);

    cout << ans << endl;

    return 0;
}