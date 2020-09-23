#include <bits/stdc++.h>
 
#define pii pair<int, int>
#define endl "\n"
#define int long long
// #define double long double
#define F first
#define S second
#define B begin
#define E end
#define RB rbegin
#define RE rend
 
typedef long long ll;
typedef unsigned long long ull;
// typedef long double ld;
 
const int INF = 1e9 + 1;
const double EPS = 1e-7;
const ll P = 1e9 + 7;
const int Q = 47;
 
using namespace std;
 
void hello()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
 
void show(vector<int>& arr)
{
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}
void show(vector<vector<int>>& arr)
{
    for (auto i : arr)
        show(i);
    cout << endl;
}


signed main()
{
    hello();
    
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double r1 = sqrt(x1 * x1 + y1 * y1);
    double r2 = sqrt(x2 * x2 + y2 * y2);
    cout << fixed;
    cout.precision(8);
    double angle = abs(atan2(x1 * y2 - x2 * y1, x1 * x2 + y1 * y2));
    cout << min(r1 + r2, angle * min(r1, r2) + max(r1, r2) - min(r1, r2)) << endl;

}