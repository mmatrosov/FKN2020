#include <iostream> 
#include <vector> 
#include <set> 

#include <ctime> 
#include <algorithm> 
#include <cstdlib> 
#include <iomanip> 

using namespace std;

using ll = long long;
using ld = long double;

int main() 
{
	ll n;
	cin >> n;
	set<ll> s;
	vector<ll> a;

	ll b;
	
	for (int i = 0; i < n; i++)
	{
		cin >> b;
		s.insert(b);
	}

	for (auto it = s.begin(); it != s.end(); it++)
	{
		a.push_back(*it);
	}

	sort(a.begin(), a.end());

	ll k, p;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> p;

		cout << (lower_bound(a.begin(), a.end(), p) - a.begin()) << endl;
	}

	cin >> n;
}