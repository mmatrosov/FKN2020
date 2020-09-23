#include <iostream>
#include <cmath>

#define int long long

using namespace std;

struct point{
    int x, y;
    point(int _x, int _y){
        x = _x;
        y = _y;
    }

};

point operator -(point a, point b){
    return point(a.x - b.x, a.y - b.y);
}

point operator +(point a, point b){
    return point(a.x + b.x, a.y + b.y);
}

int len(point a){
    return a.x * a.x + a.y * a.y;
}

int cross_product(point a, point b){
    return a.x * b.y - b.x * a.y;
}

int dot_product(point a, point b){
    return a.x * b.x + a.y * b.y;
}

signed main()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    point p1(x1, y1), p2(x2, y2);
    if (len(p1) > len(p2)){
        swap(p1, p2);
    }
    double ans = sqrt(len(p2)) - sqrt(len(p1));
    double sup = abs(atan2(cross_product(p1, p2), dot_product(p1, p2)));
    ans += min(sup, 2.0) * sqrt(len(p1));
    cout.precision(100);
    cout << ans << endl;
    return 0;
}
