#include <bits/stdc++.h>
using namespace std;

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
    ld angle() {
        return atan2(y, x);
    }
};

ld degres (ld radians) {
    return radians / PI * 180;
}

Vec operator +(Vec & a, Vec & b) {
    return Vec(a.x + b.x, a.y + b.y);
}
pt operator +(pt & a, Vec & b) {
    return pt(a.x + b.x, a.y + b.y);
}
Vec operator -(Vec & a, Vec & b) {
    return Vec(a.x - b.x, a.y - b.y);
}
pt operator -(pt & a, Vec & b) {
    return pt(a.x - b.x, a.y - b.y);
}
Vec operator *(Vec & a, ld k) {
    return Vec(a.x * k, a.y * k);
}

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

struct line{
    ld a, b, c;
    line(ld q = 0, ld w = 0, ld e = 0) {
        a = q;
        b = w;
        c = e;
    }
    line(pt p1, pt p2) {
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = -(p1.x * a + p1.y * b);
    }
    ld har() {
        return sqrt(a * a + b * b);
    }
    ld har2() {
        return a * a + b * b;
    }
    line norm(pt P) {
        return line(-b, a, b * P.x - a * P.y);
    }
    pt peres(line n) {
        return pt((n.c * b - c * n.b) / (a * n.b - n.a * b), (-n.c * a + c * n.a) / (a * n.b - n.a * b));
    }
    ld dist(pt P) {
        return (a * P.x + b * P.y + c) / har();
    }
    pt simm(pt P) {
        ld bly = (a * P.x + b * P.y + c) / har();
        return pt(P.x - 2 * bly * a / har(), P.y - 2 * bly * b / har());
    }
};

signed main() {
    cout << fixed << setprecision(20);
    int k1, b1, k2, b2;
    cin >> k1 >> b1 >> k2 >> b2;
    line n1(-k1, 1, -b1), n2(-k2, 1, -b2);
    if(k1 == k2 && b1 == b2) {
        cout << "coincide" << endl;
    } else if(k1 == k2) {
        cout << "parallel" << endl;
    } else {
        cout << "intersect" << endl;
        pt a = n1.peres(n2);
        cout << a << endl;
    }
}
