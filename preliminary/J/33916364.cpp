// Bippolar disorder is very cool

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <set>

using namespace std;

typedef int64_t ll;
typedef long double ld;

ll n, m;
vector<vector<ll>> a;
vector<pair<ll, ll>> path;

ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, 1, 0, -1};

void dfs(ll x, ll y) {
	path.emplace_back(x, y);
	a[x][y] = -2;
	if (x + 1 < n && a[x + 1][y] == -1) {
		dfs(x + 1, y);
		return;
	}
	if (x - 1 >= 0 && a[x - 1][y] == -1) {
		dfs(x - 1, y);
		return;
	}
	if (y + 1 < m) {
		dfs(x, y + 1);
	}
}

int main() {
    cin >> n >> m;
    a.resize(n, vector<ll>(m, -1));
    dfs(0, 0);
    ll kek = 1;
    ll lol = n * m;
    ll id = 0;
    ll res = 0;
    while (lol >= kek) {
    	++res;
    	lol -= kek;
    	if (lol < kek + 1) {
    		kek += lol;
    	}
    	vector<ll> used(26);
    	vector<pair<ll, ll>> arr;
    	for (ll i = 0; i < kek; ++i) {
    		ll x = path[id].first;
    		ll y = path[id].second;
    		++id;
    		arr.emplace_back(x, y);
    		for (ll dir = 0; dir < 4; ++dir) {
    			ll new_x = x + dx[dir];
    			ll new_y = y + dy[dir];
    			if (new_x < 0 || new_x >= n) {
    				continue;
    			}
    			if (new_y < 0 || new_y >= m) {
    				continue;
    			}
    			if (a[new_x][new_y] == -2) {
    				continue;
    			}
    			used[a[new_x][new_y]] = 1;
    		}
    	}
    	ll color = -1;
    	for (ll i = 0; i < 26; ++i) {
    		if (used[i]) {
    			continue;
    		}
    		color = i;
    		break;
    	}
    	for (auto i : arr) {
    		a[i.first][i.second] = color;
    	}
    	++kek;
    }
    cout << res << endl;
    for (ll i = 0; i < n; ++i) {
    	for (ll j = 0; j < m; ++j) {
    		cout << char('A' + a[i][j]);
    	}
    	cout << endl;
    }
    return 0;
}
