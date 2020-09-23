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

signed main()
{
#ifdef LOCAL
    FILE;
#endif
    sh;
	double k1, b1, k2, b2;
	cin >> k1 >> b1 >> k2 >> b2;
	if (k1 == k2 && b1 == b2) {
		cout << "coincide";
		return 0;
	}    
	if (k1 == k2) {
		cout << "parallel";
		return 0;
	}
	cout << "intersect" << endl;
	double x = ((b2 - b1) * 1.0) / (k1 - k2);
	cout << fixed << setprecision(7) << x << ' ' << k1 * x + b1;
    return 0;
}
