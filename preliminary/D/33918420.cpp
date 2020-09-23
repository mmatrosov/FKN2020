#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <string>
#define int long long

using namespace std;

typedef pair<int, int> pa;
typedef long long ll;
typedef long double ld;

const double PI = acos(-1);

struct point
{
	int x, y;
};

void cn(point &a)
{
	cin >> a.x >> a.y;
}

ld operator*(const point &a, const point &b)
{
	return a.x * b.y - a.y * b.x;
}


ld operator%(const point &a, const point &b)
{
	return a.x * b.x + a.y * b.y;
}

point operator-(const point &a, const point &b)
{
	return { b.x - a.x, b.y - a.y };
}

const ld eps = 0.001 * 0.001;

ld ug(const point &a, const point &b, const point &c)
{
	point ba = b - a, bc = b - c;
	ld ans = abs(atan2(ba * bc, ba % bc));
	//cout << ans << " ";
	return ans;
}

ld rad(point a){
    return sqrt(a.x * a.x + a.y * a.y);
}

point O = {0, 0};

ld ft(point a, point b){
    
}


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(20);
	//cout << fixed;
	
	point a, b;
	cin >> a.x >> a.y >> b.x >> b.y;
	if (rad(a) <= rad(b)){
		swap(a, b);
	}
    ld A = rad(a) - rad(b) + ug(a, O, b) * rad(b);

	if (a * b == 0)
		A = rad(a - b);
	A = min(rad(a) + rad(b), A);
	cout << A;
}