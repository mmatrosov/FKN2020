#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double PI = 3.14159265359;

class pt {
public:
    double x, y;

    pt(double _x, double _y) {
        x = _x;
        y = _y;
    };
};

struct vc {
    double x;
    double y;

    vc(double x_inp, double y_inp) {
        x = x_inp;
        y = y_inp;
    }

    vc(pt pt1, pt pt2) {
        x = pt2.x - pt1.x;
        y = pt2.y - pt1.y;
    }
};

double len(vc vc1) {
    return sqrt(vc1.x * vc1.x + vc1.y * vc1.y);
}

double dist(pt pt1, pt pt2) {
    return sqrt((pt1.x - pt2.x) * (pt1.x - pt2.x) + (pt1.y - pt2.y) * (pt1.y - pt2.y));
}

double cross_product(vc vc1, vc vc2) {
    return vc1.x * vc2.y - vc1.y * vc2.x;
}

double dot_product(vc vc1, vc vc2) {
    return vc1.x * vc2.x + vc1.y * vc2.y;
}

double min_angle(vc vc1, vc vc2) {
    return atan2(cross_product(vc1, vc2), dot_product(vc1, vc2));
}

int main() {
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    pt pt0 = pt(0, 0);
    pt pt1 = pt((double) x1, (double) y1);
    pt pt2 = pt((double) x2, (double) y2);
    vc vc1 = vc(pt0, pt1);
    vc vc2 = vc(pt0, pt2);

    cout << fixed;

    if (x1 * y2 == y1 * x2) {
        cout << dist(pt1, pt2);
    } else {
        double t1;
        t1 = abs(min_angle(vc1, vc2)) * min(len(vc1), len(vc2)) + abs(len(vc1) - len(vc2));

        double t2;
        t2 = len(vc1) + len(vc2);

        cout << min(t1, t2);
    }
}
