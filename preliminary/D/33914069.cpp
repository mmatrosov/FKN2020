#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

using namespace std;
const int N = 207702;
double pi = 3.14159265359;
double xa, xb, ya, yb;
struct line{
    double a, b, c;
};

line l1, l2;

line make(double x, double y){
    line l;
    l.a = y;
    l.b = -x;
    l.c = 0;
    return l;
}


double dist(double x1, double y1, double x2, double y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

pair <pair <double, double>, pair <double, double> > intersect(double r, line l){
    double a = l.a;
    double b = l.b;
    double c = l.c;

    double x0 = -a * c / (a * a + b * b),  y0 = -b * c / (a * a + b * b);

    double d = r * r - c * c/(a * a + b * b);
    double mult = sqrt (d / (a * a + b * b));
    double ax, ay, bx, by;
    ax = x0 + b * mult;
    bx = x0 - b * mult;
    ay = y0 - a * mult;
    by = y0 + a * mult;
    return {{ax, ay}, {bx, by}};
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> xa >> ya;
    cin >> xb >> yb;
    if (dist(xa, ya, 0, 0) > dist(xb, yb, 0, 0)){
        swap(xa, xb);
        swap(ya, yb);
    }
    double ans = dist(xa, ya, 0, 0) + dist(xb, yb, 0, 0);
    double r1 = dist(xa, ya, 0, 0);
    double r2 = dist(xb, yb, 0, 0);
    l1 = make(xa, ya);
    l2 = make(xb, yb);
    //cout << l1.a << " " << l1.b << " " << l1.c << endl;
    pair <pair <double, double>, pair <double, double> > p = intersect(r1, l2);
    //cout << p.fi.fi << " " << p.fi.se << endl;
    //cout << p.se.fi << " " << p.se.se << endl;
    double dx, dy;
    
    dx = p.fi.fi;
    dy = p.fi.se;
    double two = 2;
    double dst = dist(xa, ya, dx, dy) / (two * r1);
    dst = asin(dst);
    dst *= two;
    dst = dst * r1 + dist(dx, dy, xb, yb);
    ans = min(ans, dst);
    dx = p.se.fi;
    dy = p.se.se;
    dst = dist(xa, ya, dx, dy) / (two * r1);
    dst = asin(dst);
    dst *= two;
    dst = dst * r1 + dist(dx, dy, xb, yb);
    ans = min(ans, dst);
    

    /*p = intersect(r2, l1);
    //cout << p.fi.fi << " " << p.fi.se << endl;
    //cout << p.se.fi << " " << p.se.se << endl;
    dx, dy;
    if (dist(xb, yb, p.fi.fi, p.fi.se) < dist(xb, yb, p.se.fi, p.se.se)){
        dx = p.fi.fi;
        dy = p.fi.se;
    }
    else {
        dx = p.se.fi;
        dy = p.se.se;
    }
    two = 2;
    dst = dist(xb, yb, dx, dy) / (two * r2);
    dst = asin(dst);
    dst *= two;
    dst = dst * r2 + dist(dx, dy, xa, ya);
    ans = min(ans, dst);*/

    cout.precision(7);
    cout << fixed << ans << endl;

}
