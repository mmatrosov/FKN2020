#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define pb push_back
#define all(x) x.begin(), x.end()
#define vi vector<int>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, j, x, y;
    set<int> D;
    cin >> n;
    for (int i = 0; i < n; ++i) {cin >> x; D.insert(x);}
    vi diego;
	for (auto v : D) diego.pb(v);
    cin >> k;
	for (int i = 0; i < k; ++i)
	{
		cin >> y;
		cout << (lower_bound(all(diego), y) - diego.begin()) << endl;
	}
}