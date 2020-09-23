#include <bits/stdc++.h>


using namespace std;


#define int long long
#define double long double


const int eps = 1e-10;


struct point
{
    double x, y;
    point(int val1, int val2)
    {
        x = val1;
        y = val2;
    }
    point()
    {
        x = 0;
        y = 0;
    }
};


struct line
{
    int a, b, c;
    line()
    {
        a = 0;
        b = 0;
        c = 0;
    }
    line (int aa, int bb, int cc)
    {
        a = aa;
        b = bb;
        c = cc;
    }
    line (point A, point B)
    {
        a = (B.y - A.y);
        b = (A.x - B.x);
        c = ((-1) * (a * A.x + b * A.y));
    }
};


void swap(point &a, point &b)
{
    swap(a.x, b.x);
    swap(a.y, b.y);
}


void swap(line &a, line &b)
{
    swap(a.a, b.a);
    swap(a.b, b.b);
    swap(a.c, b.c);
}


point operator+(point a, point b)
{
    point c(a.x + b.x, a.y + b.y);
    return c;
}


point operator-(point a, point b)
{
    point c(a.x - b.x, a.y - b.y);
    return c;
}


int operator*(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}


int operator^(point a, point b)
{
    return a.x * b.y - a.y * b.x;
}


bool operator==(point a, point b)
{
    return a.x == b.x && a.y == b.y;
}


istream& operator>>(istream& stream, line &a)
{
    stream >> a.a >> a.b >> a.c;
    return stream;
}


istream& operator>>(istream& stream, point &a)
{
    stream >> a.x >> a.y;
    return stream;
}


ostream& operator<<(ostream& stream, point &a)
{
    stream << a.x << " " << a.y << " ";
    return stream;
}


ostream& operator<<(ostream& stream, line &a)
{
    stream << a.a << " " << a.b << " " << a.c;
    return stream;
}


double angle(point a, point b, point c)
{
    return atan2((a - b) ^ (c - b), (a - b) * (c - b));
}


int twSpace(point a, point b, point c)
{
    return (a - b) ^ (c - b);
}


double dist(point a, point b)
{
    int f = a.x - b.x, s = a.y - b.y;
    return sqrt(f * f + s * s);
}


double lineDist(point a, point b, point c)
{
    return (abs(twSpace(a, b, c))) / dist(b, c);
}


double rayDist(point a, point b, point c)
{
    if (((c - b) * (a - b)) < 0)
    {
        return dist(a, b);
    }
    return lineDist(a, b, c);
}


double segmentDist(point a, point b, point c)
{
    if (((c - b) * (a - b)) < 0)
    {
        return dist(a, b);
    }
    if (((b - c) * (a - c)) < 0)
    {
        return dist(a, c);
    }
    return lineDist(a, b, c);
}

bool insideAngle(point a, point o, point b, point p)
{
    if (((b - o) ^ (a - o)) < 0)
    {
        swap(a, b);
    }
    if (((b - o) ^ (p - o)) >= 0 && ((a - o) ^ (p - o)) <= 0)
    {
        return true;
    }
    return false;
}



bool rayCross(point a, point b, point c, point d)
{
    if (((b - a) ^ (c - a)) == 0)
    {
        return (rayDist(c, a, b) == 0) || (rayDist(a, c, d) == 0);
    }
    return insideAngle(a, c, c + b - a, d) && ((b - a) ^ (d - c)) != 0;
}


bool segmentCross(point a, point b, point c, point d)
{
    return (rayCross(a, b, c, d)) && (rayCross(b, a, c, d)) && (rayCross(a, b, d, c)) && (rayCross(b, a, d, c));
}


double segmentSegmentDist(point a, point b, point c, point d)
{
    if (segmentCross(a, b, c, d))
    {
        return 0.0;
    }
    return min(min(segmentDist(a, c, d), segmentDist(b, c, d)), min(segmentDist(c, a, b), segmentDist(d, a, b)));
}


bool segmentRayCross(point a, point b, point c, point d)
{
    return rayCross(a, b, c, d) && rayCross(b, a, c, d);
}


double segmentRayDist(point a, point b, point c, point d)
{
    if (segmentRayCross(a, b, c, d))
    {
        return 0.0;
    }
    return min(min(rayDist(a, c, d), rayDist(b, c, d)), segmentDist(c, a, b));
}


bool segmentLineCross(point a, point b, point c, point d)
{
    return segmentRayCross(a, b, c, d) || segmentRayCross(a, b, d, c);
}


double segmentLineDist(point a, point b, point c, point d)
{
    if (segmentLineCross(a, b, c, d))
    {
        return 0.0;
    }
    return min(lineDist(a, c, d), lineDist(b, c, d));
}


double rayRayDist(point a, point b, point c, point d)
{
    if (rayCross(a, b, c, d))
    {
        return 0.0;
    }
    return min(rayDist(a, c, d), rayDist(c, a, b));
}


bool rayLineCross(point a, point b, point c, point d)
{
    return rayCross(a, b, c, d) || rayCross(a, b, d, c);
}


double rayLineDist(point a, point b, point c, point d)
{
    if (rayLineCross(a, b, c, d))
    {
        return 0.0;
    }
    return lineDist(a, c, d);
}


bool lineLineCross(point a, point b, point c, point d)
{
    return rayLineCross(a, b, c, d) || rayLineCross(b, a, c, d);
}


double lineLineDist(point a, point b, point c, point d)
{
    if (lineLineCross(a, b, c, d))
    {
        return 0.0;
    }
    return lineDist(a, c, d);
}


double lineDist(point a, line t)
{
    return (int)abs(t.a * a.x + t.b * a.y + t.c) / sqrt((int)(t.a * t.a + t.b * t.b));
}


point cross(line f, line s)
{
    int ansx, ansy;
    if (s.a == 0 || s.b == 0)
    {
        swap(f, s);
    }
    if (f.a == 0)
    {
        ansy = (-1) * (f.c / f.b);
        ansx = (-1) * (s.b * ansy + s.c) / s.a;
    }
    else if (f.b == 0)
    {
        ansx = (-1) * f.c / f.a;
        ansy = (-1) * (ansx * s.a + s.c) / s.b;
    }
    else
    {
        ansy = (f.c * s.a - f.a * s.c) / (f.a * s.b - f.b * s.a);
        ansx = (f.c * s.b - s.c * f.b) / (s.a * f.b - f.a * s.b);
    }
    point a(ansx, ansy);
    return a;
}


int value(point p, line l)
{
    return p.x * l.a + p.y * l.b + l.c;
}


struct cmp
{
    bool operator()(point a, point b)
    {
        if (a.x == b.x)
        {
            a.y < b.y;
        }
        return a.x < b.x;
    }
};


void die()
{
    while (true){};
}


line perp(line l, point p)
{
    point norm(l.a, l.b);
    line ans(p, p + norm);
    return ans;
}


point medianCross(point a, point b, point c)
{
    point m1((a.x + b.x) / 2, (a.y + b.y) / 2), m2((a.x + c.x) / 2, (a.y + c.y) / 2);
    line cm1(c, m1), bm2(b, m2);
    point ans = cross(cm1, bm2);
    return ans;
}


point orthocenter(point a, point b, point c)
{
    line bc(b, c), ab(a, b);
    line ah = perp(bc, a), ch = perp(ab, c);
    point ans = cross(ah, ch);
}


point turn(point a, int alpha)
{
    int x = a.x, y = a.y;
    point ans(x * cos(alpha) - y * sin(alpha), y * cos(alpha) + x * sin(alpha));
    return ans;
}


point resize(point a, int d)
{
    int temp = sqrt(a.x * a.x + a.y * a.y);
    a.x *= (d / temp);
    a.y *= (d / temp);
    return a;
}


point mid(point a, point b)
{
    point c((a.x + b.x) / 2, (a.y + b.y) / 2);
    return c;
}


line bisector(point a, point b, point c)
{
    line ans(b, mid(a, b + resize(c - b, dist(a, b))));
    return ans;
}


point par(line l)
{
    point ans((-1) * l.b, l.a);
    return ans;
}


point sym(line l, point p)
{
    point norm(l.a, l.b);
    int temp = lineDist(p, l);
    norm = resize(norm, temp * 2);
    int a = value(p, l), b = value(p + norm, l);
    if (a * b < 0)
    {
        return p + norm;
    }
    norm.x *= -1;
    norm.y *= -1;
    return p + norm;
}


void pointPrint(line l)
{
    if (l.a == 0)
    {
        int y = (-1) * l.c / l.b;
        cout << 0 << " " << y << " " << 1 << " " << y << endl;
    }
    else
    {
        cout << (-1) * l.c / l.a << " " << 0 << " " << (-1) * (l.c + l.b) / l.a << " " << 1 << endl;
    }
}


bool in(vector<point> &sm, point k)
{
    double ans = 0.0, t = 0.0;
    for (int i = 0; i < sm.size(); i++)
    {
        ans += (sm[i] - k) ^ (sm[(i + 1) % sm.size()] - k);
        t += abs((sm[i] - k) ^ (sm[(i + 1) % sm.size()] - k));
    }
    return abs(ans) == t;
}


bool cross(vector<point> &f, vector<point> &s)
{
    for (int i = 0; i < f.size(); i++)
    {
        if(in(s, f[i]))
        {
            return true;
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        if(in(f, s[i]))
        {
            return true;
        }
    }
    for (int i = 0; i < f.size(); i++)
    {
        for (int j = 0; j < s.size(); j++)
        {
            if(segmentCross(f[i], f[(i + 1) % f.size()], s[j], s[(j + 1) % s.size()]))
            {
                return true;
            }
        }
    }
    return false;
}


void warp()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}


bool insideTriangle(point a, point b, point c, point check)
{
    return insideAngle(a, b, c, check) && insideAngle(b, c, a, check);
}


bool segmentTriangleCross(point a, point b, point c, point start, point fin)
{
    return segmentCross(a, b, start, fin) || segmentCross(b, c, start, fin) || segmentCross(a, c, start, fin);
}


signed main()
{
    warp();
    cout << setprecision(10);
    int k1, b1, k2, b2;
    cin >> k1 >> b1 >> k2 >> b2;
    if (k1 == k2)
    {
        if (b1 == b2)
        {
            cout << "coincide" << endl;
        }
        else
        {
            cout << "parallel" << endl;
        }
        return 0;
    }
    cout << "intersect" << endl;
    double x = (double)(b1 - b2) / (double)(k2 - k1);
    cout << x << " " << (double)b1 + (double)k1 * x << endl;
    /*
    line a(k1, -1, b1), b(k2, -1, b2);
    point p = cross(a, b);
    cout << p.x << " " << p.y << endl;
    */
    return 0;
}
