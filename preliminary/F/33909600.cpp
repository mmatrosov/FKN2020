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

ld rad(int x, int y){
	return sqrt(x * x + y * y);
}


const double PI = acos(-1);

struct point
{
	ld x, y;
};

void cn(point &a)
{
	cin >> a.x >> a.y;
}

double operator*(const point &a, const point &b)
{
	return a.x * b.y - a.y * b.x;
}

double operator%(const point &a, const point &b)
{
	return a.x * b.x + a.y * b.y;
}

point operator-(const point &a, const point &b)
{
	return { b.x - a.x, b.y - a.y };
}

double ug(const point &a, const point &b, const point &c)
{
	point ba = b - a, bc = b - c;
	return abs(atan2(ba * bc, ba % bc)) * 180 / PI;
}

const int N = 101;
int dp[N][N];
vector<int> an[N][N];

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(6);
	cout << fixed;
	
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int& i : a){
		cin >> i;
	}
	int ans = 0;
	sort(a.begin(), a.end());
	for (int N = 0; N < n; ++N){
		for (int K = 0; K < k; ++K){
			for (int cnt = 1; cnt + N <= n; ++cnt){
				
				if (dp[N + cnt][K + 1] <= dp[N][K] + cnt * a[N]){
					dp[N + cnt][K + 1] = max(dp[N + cnt][K + 1], dp[N][K] + cnt * a[N]);
					an[N + cnt][K + 1] = an[N][K];
					an[N + cnt][K + 1].push_back(a[N]);
				}
			}
		}
	}
	vector<int> sp;
	for (int N = 0; N <= n; ++N){
		for (int cnt = 0; cnt <= k; ++cnt) {
			//ans = max(ans, dp[N][cnt]);
			if (ans <= dp[N][cnt]){
				ans = max(ans, dp[N][cnt]);
				sp = an[N][cnt];
			}
		}
	}
	//cout << ans << "\n";
	int x = a.back() + 1;
	while (sp.size() < k){
		sp.push_back(x++);
	}
	for (int i : sp){
		cout << i << " ";
	}
}