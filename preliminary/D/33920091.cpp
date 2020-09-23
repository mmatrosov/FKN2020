#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i = 0; i < n; ++i)
#define ld long double

const ld PI = acos(-1);
const ld EPS = 1e-6;

struct pt {
    ld x, y;
    pt (ld a = 0, ld b = 0) {
        x = a;
        y = b;
    }
    ld dist () {
        return sqrt(x * x + y * y);
    }
    ld dist2 () {
        return x * x + y + y;
    }
    ld dlin(pt B) {
        return sqrt((x - B.x) * (x - B.x) + (y - B.y) * (y - B.y));
    }
    pt rotate(pt O, ld sn, ld cs) {
        pt res(x - O.x, y - O.y);
        pt ans(res.x * cs - res.y * sn + O.x, res.x * sn + res.y * cs + O.y);
        return ans;
    }
};

istream & operator >> (istream & in, pt & p) {
    in >> p.x >> p.y;
    return in;
}

ostream & operator << (ostream & out, pt & p) {
    out << p.x << " " << p.y;
    return out;
}

struct Vec {
    ld x, y;
    Vec(ld a = 0, ld b = 0) {
        x = a;
        y = b;
    }
    Vec(pt & a, pt & b){
        x = b.x - a.x;
        y = b.y - a.y;
    }
    ld dlin() {
        return sqrt(x * x + y * y);
    }
    pt trn(ld R) {
        pt res;
        ld d = dlin();
        res.x = (x / d) * R;
        res.y = (y / d) * R;
        return res;
    }
};

istream & operator >> (istream & in, Vec & p) {
    in >> p.x >> p.y;
    return in;
}

ostream & operator << (ostream & out, Vec & p) {
    out << p.x << " " << p.y;
    return out;
}

ld dot(Vec a, Vec b) {
    return a.x * b.x + a.y * b.y;
}

ld cross(Vec  a, Vec  b) {
    return a.x * b.y - a.y * b.x;
}

ld atn(Vec a, Vec b) {
    return atan2(cross(a, b), dot(a, b));
}

ld dol1, dol2;
pt A, B, O, p1, p2;
Vec OA, OB;

ld f(ld R) {
    pt A1 = OA.trn(R);
    pt B1 = OB.trn(R);
    ld res = p1.dlin(A1) + p2.dlin(B1) + dol1 * 2.0 * PI * R;
    return res;
}

ld sol() {
    OA = Vec(O, A), OB = Vec(O, B);
    ld alp = fabs(atn(OA, OB));
    dol1 = alp / (2.0 * PI), dol2 = 1 - dol1;
    dol1 = min(dol1, dol2);
    //cout << dol1 << " " << dol2 << endl;
    //cout << atn(OA, OB) << endl;

    ld l = 0, r = 1e15 + 1.0;
    loop(i, 200) {
        ld m1 = (2 * l + r) / 3.0;
        ld m2 = (l + 2 * r) / 3.0;

        ld r1 = f(m1), r2 = f(m2);

        if(r1 < r2) r = m2;
        else l = m1;
    }
    return f(l);
}
ld dist(pt A, pt B) {
    return A.dlin(B);
}

signed main() {
    cout << fixed << setprecision(20);
    cin >> A >> B;
    if(A.x == 0 && A.y == 0) {
        cout << dist(A, B) << endl;
        return 0;
    }
    if(B.x == 0 && B.y == 0) {
        cout << dist(A, B) << endl;
        return 0;
    }

    p1 = A, p2 = B;
    ld ans = sol();
    ld dop = 0.0;


    p1 = O, p2 = B;
    dop = dist(O, A);
    A.x *= -1, A.y *= -1;
    ans = min(ans, dop + sol());
    A.x *= -1, A.y *= -1;

    p1 = A, p2 = O;
    dop = dist(O, B);
    B.x *= -1, B.y *= -1;
    ans = min(ans, dop + sol());
    B.x *= -1, B.y *= -1;

    p1 = O, p2 = O;
    dop = dist(O, A) + dist(O, B);
    A.x *= -1, A.y *= -1;
    B.x *= -1, B.y *= -1;
    ans = min(ans, dop + sol());

    cout << ans << endl;
}
