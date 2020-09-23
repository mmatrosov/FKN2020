#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define sh cin.tie(0); cin.sync_with_stdio(0); cout.tie(0);
#define FILE freopen("test.in", "r", stdin);
#define vprint(v) for (int ii = 0; ii < v.size(); ii++){cout << v[ii] << " ";}
#define debugv(v) if (v.size() != 0) {cout << "[ "; for (int __ = 0; __ < (int)(v.size()) - 1; __++){cout << v[__] << ", ";} cout << v[(int)(v.size()) - 1] << " ]" << endl;} else {cout << "[]" << endl;}
#define debug cout << "-----------------------------------------------" << endl;
#define print1(a) cout << "{ " << a << " }" << endl;
#define print2(a, b) cout << "{ " << a << ", " << b << " }" << endl;
#define print3(a, b, c) cout << "{ " << a << ", " << b << ", " << c << " }" << endl;
#define print4(a, b, c, d) cout << "{ " << a << ", " << b << ", " << c << ", " << d << " }" << endl;
using namespace std;
//#define int long long
const int INF = 1e9 + 228;
const int MAXN = 1e5 + 228;
const double PI = 3.14159265359;
const double eps = 1e-8;
signed main()
{
#ifdef LOCAL
    FILE;
#endif
    sh;
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double a = sqrt(x1 * x1 + y1 * y1);
    double b = sqrt(x2 * x2 + y2 * y2);
    double c = abs(a - b);
    double d1 = atan2(y1, x1);
    double d2 = atan2(y2, x2);
    double r = abs(d1 - d2);
    //print1(r);
    double d = (min(a, b) * r);
    cout << fixed << setprecision(7) << min(a + b, c + d) << endl;
    return 0;
}
