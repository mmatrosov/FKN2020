#include <bits/stdc++.h>

using namespace std;

using ld = long double;
//using long long = long long;

ld constexpr pi() { return acos(-1); }

const ld EPS = 10e-6;

struct Vector {
    long long x, y;

    Vector operator+(Vector other) {
        return {x + other.x, y + other.y};
    }

    long long operator*(Vector v) {
        return x * v.x + y * v.y;
    }

    long long operator%(Vector v) {
        return x * v.y - y * v.x;
    }
};

struct Point {
    long long x, y;

    Point operator+(Point other) {
        return {x + other.x, y + other.y};
    }

    Point operator-() {
        return {-x, -y};
    }

    Point operator-(Point other) {
        return (*this) + (-other);
    }

    Point operator+(Vector other) {
        return {x + other.x, y + other.y};
    }

    Vector as_vector() {
        return {x, y};
    }
};

inline ld len(Vector v) {
    return sqrt(v * v);
}

inline ld ro(Point p) {
    //return len(p.as_vector());
    return sqrt((p.x * p.x) + (p.y * p.y));
}

inline ld angle(Vector v, Vector u) {
    return atan2(v % v, v * v);
}

inline bool is_zero(ld x) {
    return abs(x) < EPS;
}

inline bool is_collinear(Vector v, Vector u) {
    return is_zero(v % u);
}

inline bool is_equal(ld x, ld y) {
    return is_zero(x - y);
}

inline Vector turn_left(Vector v) {
    return {-v.y, v.x};
}

inline Vector turn_right(Vector v) {
    return {v.y, -v.x};
}

struct Line {
    long long a, b, c;


    // нормирование: разделить коэфы на sqrt(a ** 2 + b ** 2), тогда с - расстояние из 0
};

Point read_point() {
    long long x, y;
    cin >> x >> y;
    return {x, y};
}

ld angle(Point X, Point O, Point Y) {
    Vector v = (X - O).as_vector();
    Vector u = (Y - O).as_vector();
    return atan2(v % u, v * u);
}

ld to_deg(ld rad) {
    return 360 * rad / (2 * pi());
}

int main() {
    cout.precision(7);

    Point A = read_point();
    Point B = read_point();
    if (ro(A) < ro(B)) {
	Point tmp = B;
	B = A;
	A = tmp;
    }
    Point O = {0, 0};

    //cout << to_deg(max(max(abs(angle(B, O, A)), abs(angle(O, A, B))), abs(angle(A, B, O)))) << endl;
    
    ld alpha = min(abs(angle(A, O, B)), abs(angle(B, O, A)));
    if (alpha > pi() + EPS) {
	alpha -= pi();
    }
    ld r;
    /*
    if (angle <= 2 - EPS) {
	r = A.ro() + B.ro() - (angle - 2) * B.ro();
    } else if (angle < 2 + EPS) {
	r = 
    }
    */
    /*
    if (alpha < 2 + EPS) {
	r = ro(A) + ro(B) + (alpha - 2) * ro(B);
    } else {
	r = ro(A) + ro(B);
    }
    */
    r = min(ro(A) + ro(B) + (alpha - 2) * ro(B), ro(A) + ro(B));
    cout << r << endl;
}
