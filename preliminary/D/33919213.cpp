#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<random>
#include<set>

using namespace std;

long double dl(pair<long long, long long> a) {
	return sqrt(a.first*a.first + a.second*a.second);
}

long double cos1(pair<long long, long long> a, pair<long long, long long> b) {
	//long double pr = a.first*b.first + a.second*b.second;
	//return pr / dl(a) / dl(b);
	long long da = dl(a), db = dl(b), dc = dl({ a.first - b.first,a.second - b.second });
	return (dc*dc - da * da - db * db) / (-2 * da*db);
}

int main() {
	ios_base::sync_with_stdio(false);
	pair<long long, long long> a, b;
	//cout << acos(0);
	cin >> a.first >> a.second >> b.first >> b.second;
	if (dl(a) > dl(b)) {
		swap(a, b);
	}
	if (a.first == 0 && a.second == 0) {
		cout << dl(b);
	}
	else {
		long double ans = dl(a) + dl(b);
		cout.precision(10);
		//long double db = dl(b) / dl(a);
		long double r = dl(a);
		if (a.second*b.second < 0) {
			r = r * acos(a.first / dl(a)) + r * acos(b.first / dl(b));
		}
		else {
			r = r * acos(a.first / dl(a)) - r * acos(b.first / dl(b));
		}
		r = abs(r);
		ans = min(ans, dl(b) - dl(a) + min(r,acos(-1)*2*dl(a)));
		cout << abs(ans);
	}
	system("pause");
}