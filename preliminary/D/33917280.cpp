#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<set>
#include<string>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <cassert>

using namespace std;
//#define int long long
typedef long long lli;
typedef long double ld;
ld PI = 3.1415926535897932384626433832;
const double E = 0.0000001;
const int INF = 1e7;
#define forn(i, s, f) for (int i = s; i < f; ++i)
#define ft first
#define sec second
#define fora(i, n) for (auto i : n)
#define sz(a) (int)(a).size()
#define sortf0rw(a) sort(a.begin(), a.end())
#define pb push_back
#define mp make_pair
#define fast_ cin.tie(0), ios_base::sync_with_stdio(false);

struct pt {
    ld x, y;
    pt(ld a = 0, ld b = 0) {
        x = a;
        y = b;
    }
};

struct vec {
    ld x, y;
    vec(pt a, pt b) {
        x = a.x - b.x;
        y = a.y - b.y;
    }
    vec(ld a = 0, ld b = 0) {
        x = a;
        y = b;
    }
    vec const operator+ (const vec& a) {
        return { x + a.x, y + a.y };
    }
    vec const operator+ (const pt& a) {
        return { x + a.x, y + a.y };
    }
    double const operator* (const vec& a) {
        return a.x * x + a.y * y;
    }
    double const operator% (const vec& a) {
        return a.y * x - a.x * y;
    }
};
double le(vec a) {
    return sqrt(a.x * a.x + a.y * a.y);
}
double sin2(vec a, vec b) {
    return (a % b) / (le(a) * le(b));
}
double cos2(vec a, vec b) {
    return (a * b) / (le(a) * le(b));
}
double ang(vec a, vec b) {
    ld an = atan2(sin2(a, b), cos2(a, b));
    if (an < 0) {
        an = 2 * PI + an;
    }
    if (an > PI) {
        an = 2 * PI - an;
    }
    return an;
}

istream& operator >>(istream& in, pt& p) {
    in >> p.x >> p.y;
    return in;
}

int main()
{
   
    cout.precision(20);
    pt a, b;
    cin >> a >> b;
    pt o(0, 0);
   // ld an1 = ang(vec(a, b), vec(a, c));
    ld l1 = le(vec(o, a));
    ld l2 = le(vec(o, b));
    ld l = min(l1, l2);
    ld an = ang(vec(o, a), vec(o, b));
    //cout << an << endl;
   // cout << l1 + l2 << endl;
    ld du = l * an;
    cout << fixed << min(l1 + l2, du + abs(l2 - l1));
    return 0;
}
