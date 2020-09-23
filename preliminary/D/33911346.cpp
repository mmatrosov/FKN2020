#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct point
{
    ld x, y;

    point(ld x, ld y): x(x), y(y) {}
    point(): x(0), y(0) {}
};

struct Vector
{
    ld x, y;

    Vector(point a, point b): x(b.x - a.x), y(b.y - a.y) {}
    Vector(ld x, ld y): x(x), y(y) {}
};

ld dist(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

ld operator*(Vector a, Vector b)
{
    return a.x * b.y - a.y * b.x;
}

ld operator^(Vector a, Vector b)
{
    return a.x * b.x + a.y * b.y;
}

ld angle(Vector a, Vector b)
{
    return atan2(a * b, a ^ b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    point a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    point o(0, 0);

    if (dist(a, o) > dist(b, o))
        swap(a, b);

    cout << fixed << setprecision(20) << min(dist(a, o) + dist(b, o),
            dist(a, o) * abs(angle(Vector(o, a), Vector(o, b))) + dist(b, o) - dist(a, o));

    return 0;
}
