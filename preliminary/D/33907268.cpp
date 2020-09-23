#include<bits/stdc++.h>

using namespace std;

using ll = long long int;
using vi = vector<int>;
#define f(n) for(int i = 0; i < n; i++)
#define fj(n) for(int j = 0; j < n; j++)
#define fk(n) for(int k = 0; k < n; k++)
#define ci(n) cin >> n;
#define ic(n) int n; cin >> n;
#define lc(n) int n; cin >> n;
#define all(a) a.begin(), a.end()
#define pri(a, n) for(int i = 0; i < n; i++) cout << a[i] << " "; cout << "\n";
#define sc(a, n) int a[n] = {0}; for(int i = 0; i < n; i++) cin >> a[i];
#define int long long
#define double long double
struct pt {
    int x, y;
    pt(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};

struct Vector {
    int x, y;
    Vector(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    Vector(pt a, pt b) : x(b.x - a.x), y(b.y - a.y) {}
    double length() {return sqrtl(x * x + y * y);}
    int intlen() {return x * x + y * y;}
};
std::istream&operator>>(std::istream &is, pt &p) {return is >> p.x >> p.y;}
std::ostream&operator<<(std::ostream &os, pt &p) {return os << p.x << " " << p.y;}


Vector operator * (double a, const Vector &b) {return Vector(a * b.x, a * b.y);}
Vector operator * (const Vector &a, double b) {return Vector(b * a.x, b * a.y);}
int operator % (const Vector &a, const Vector &b) {return a.x * b.x + a.y * b.y;}
int operator * (const Vector &a, const Vector &b) {return a.x * b.y - a.y * b.x;}
double operator ^ (const Vector &a, const Vector &b) {
    if (atan2(a * b, a % b) >= 0) {
        return atan2(a * b, a % b);
    } else {
        return abs(atan2(a * b, a % b));
    }
}
main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(34);
    pt pa, pb, start(0, 0);
    cin >> pa >> pb;
    Vector va(start, pa), vb(start, pb);
    double ans = min(va.length() + vb.length(), abs(vb.length() - va.length()) + (va ^ vb) * min(va.length(), vb.length()));
    cout << ans;
}
