#include <bits/stdc++.h>
using namespace std;

#define double long double
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

double da, db;

double getans1(ll xa, ll ya, ll xb, ll yb) {
    double ans = db - da;

    double ang1 = atan2(ya, xa),
        ang2 = atan2(yb, xb),
        pi = acos(-1);

    double ang = abs(ang1 - ang2);

    if (ang > pi) {
        ang = 2 * pi - ang;
    }

    ans += min(da + da, ang * da);

    return ans;
}

double getans2(ll xa, ll ya, ll xb, ll yb) {
    double ans = db + da;

    xb = -xb;
    yb = -yb;

    double ang1 = atan2(ya, xa),
        ang2 = atan2(yb, xb),
        pi = acos(-1);

    double ang = abs(ang1 - ang2);

    if (ang > pi) {
        ang = 2 * pi - ang;
    }

    ans += min(da + da, ang * da);

    return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    ll xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;

    da = sqrtl(xa * xa + ya * ya),
        db = sqrtl(xb * xb + yb * yb);

    if (da > db) {
    	swap(da, db);
    	swap(xa, xb);
    	swap(ya, yb);
    }

    cout << fixed << setprecision(10);

    if (xa == 0 && ya == 0) {
    	cout << db << "\n";
    	return 0;
    }

    double ans = min(getans1(xa, ya, xb, yb), getans2(xa, ya, xb, yb));

    
    cout << ans << "\n";

	return 0;
}