#include <iostream> 
#include <fstream> 
#include <sstream> 
#include <vector> 
#include <set> 
#include <string> 

#include <ctime> 
#include <cctype> 
#include <cmath> 
#include <algorithm> 
#include <cstdlib> 
#include <iomanip> 

using namespace std;
using ll = long long;

void dfs(vector<vector<pair<ll, ll>>>& g, vector<bool>& used, vector<ll>& dist, ll p)
{
	used[p] = 1;
	for (ll i = 0; i < g[p].size(); i++)
	{
		ll u = g[p][i].first;
		ll w = g[p][i].second;
		if (!used[u])
		{
			dist[u] = dist[p] ^ w;
			dfs(g, used, dist, u);
		}
	}
}

ll get_bin(ll a, ll p)
{
	return !!(a & ((ll)1 << p));
}

string to_bin(ll a, ll s)
{
	string res(s, '0');
	for (ll i = 0; i < s; i++)
	{
		if (get_bin(a, i))
			res[i] = '1';
	}

	reverse(res.begin(), res.end());
	return res;
}

signed main() 
{
	ll n;
	cin >> n;

	vector<vector<pair<ll, ll>>> g(n);

	ll a, b, w;
	for (ll i = 0; i < n - 1; i++)
	{
		cin >> a >> b >> w;
		a--;
		b--;
		g[a].emplace_back(b, w);
		g[b].emplace_back(a, w);
	}

	vector<bool> used(n, 0);
	vector<ll> v(n, 0);

	dfs(g, used, v, 0);

	auto v1 = v;

	sort(v.begin(), v.end());

	/*
	for (ll i = 0; i < n; i++)
	{
		cout << to_bin(v[i], 33) << endl;
	}
	/**/

	ll mx = 0;

	ll r1 = 0;
	ll r2 = 0;

	for (ll i = 0; i < n; i++)
	{
		ll x = v[i];
		ll l = 0;
		ll r = n;
		ll k = 0;
		for (ll j = 33; j >= 0; j--)
		{
			ll dk = (ll)1 << j;
			ll m = lower_bound(v.begin() + l, v.begin() + r, k + dk) - v.begin();
			if (get_bin(x, j))
			{
				if (m != l)
					r = m;
			}
			else
			{
				if (m != r)
				{
					l = m;
					k += dk;
				}
			}
			/**
			cout << i << ' ' << l << ' ' << m << ' ' << r << ' ' << endl;
			cout << to_bin(x, 33) << endl;
			cout << to_bin(v[l], 33) << endl;
			cout << to_bin(k, 33) << endl;
			/**/
		}

		if ((x ^ v[l]) > mx)
		{
			mx = x ^ v[l];
			r1 = i;
			r2 = l;
		}
	}
	
	cout << find(v1.begin(), v1.end(), v[r1]) - v1.begin() + 1 << ' ' 
		 << find(v1.begin(), v1.end(), v[r2]) - v1.begin() + 1 << endl;
	cin >> n;
}