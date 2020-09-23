#include <bits/stdc++.h>

using namespace std;

#define double long double

#define all(a) a.begin(),a.end()

double hypota(double x, double y) {
    return sqrtl(x * x + y * y);
}

double ag(double x1, double y1, double x2, double y2) {
    double a = x1 * x2 + y1 * y2;
    double b = hypota(x1, y1) * hypota(x2, y2);
    return acosl(a / b);
}


int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << fixed;
    cout.precision(17);

    if (hypota(x1, y1) > hypota(x2, y2)) {
        swap(x1, x2);
        swap(y1, y2);
    }

    if (x1 * y2 == x2 * y1) {
        if(x1>=0 && x2>=0 || x1<=0 && x2<=0)
        cout << abs(
                hypota(x1, y1) - hypota(x2, y2));
        else
            cout << abs(
                    hypota(x1, y1) + hypota(x2, y2));
        return 0;
    }

    if (x1 == 0 && y1 == 0) {
        cout << hypota(x2, y2) << endl;
    } else {
        double b = ag(x1, y1, x2, y2);
        cout << (min(hypota(x1, y1) * 2, hypota(x1, y1) * b) + abs(
                hypota(x1, y1) - hypota(x2, y2))) << endl;
    }

    return 0;
}
