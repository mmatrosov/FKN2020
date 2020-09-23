#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <cstdlib>
#include <deque>
#include <stack>
#include <set>
using namespace std;




int main()
{
	int n;
	cin >> n;
	set<string> main;
	vector<string> v;
	string ok, ok1;
	cin >> ok >> ok1;
	for (int i = 0; i < n; ++i)
	{
		string d;
		cin >> d;
		if (ok == "no")
		{
			for (int i = 0; i < d.size(); ++i)
			{
				d[i] = tolower(d[i]);
			}
		}
		main.insert(d);
	}
	string s;
	while (getline(cin, s))
	{
		v.push_back(s);
	}
	if (ok == "no")
	{
		for (int i = 0; i < v.size(); ++i)
		{
			for (int j = 0; j < v[i].size(); ++j)
			{
				v[i][j] = tolower(v[i][j]);
			}
		}
	}
	vector<string> a;
	for (int i = 0; i < v.size(); ++i)
	{
		string x;
		bool st = false;


		for (int j = 0; j < v[i].size(); ++j)
		{
			if (!(v[i][j] >= 'a' && v[i][j] <= 'z') && !(v[i][j] >= 'A' && v[i][j] <= 'Z') && !(v[i][j] >= '0' && v[i][j] <= '9') && !(v[i][j] == '_'))
			{
				st = true;
				while (v[i].size() > 0)
				{
					for (int lol = 0; (v[i][lol] >= 'a' && v[i][lol] <= 'z') || (v[i][lol] >= 'A' && v[i][lol] <= 'Z') || (v[i][lol] >= '0' && v[i][lol] <= '9') || v[i][lol] == '_'; ++lol)
					{
						x.push_back(v[i][lol]);
						v[i].erase(v[i].begin() + lol);
						--lol;
					}
					if (v[i].size() > 0)
					{
						v[i].erase(v[i].begin());
					}
					if (x.size() > 0 && (x[0] >= 'a' && x[0] <= 'z') || (x[0] >= 'A' && x[0] <= 'Z') || (x[0] >= '0' && x[0] <= '9' && x.size() > 1) || x[0] == '_')
					{
						a.push_back(x);
					}
					x = "";
				}

			}
		}

		if (st)

		{

		}
		else
		{
			if (v[i].size() > 0 && (v[i][0] >= 'a' && v[i][0] <= 'z') || (v[i][0] >= 'A' && v[i][0] <= 'Z') || (x[0] >= '0' && x[0] <= '9' && x.size() > 1) || v[i][0] == '_')
			{
				a.push_back(x);
			}
			if (v.size() > 0)
			{
				v.erase(v.begin() + i);
			}
		}
		--i;
	}
	vector<pair<string, int>> ans;
	if (ok == "no")
	{
		for (int i = 0; i < a.size(); ++i)
		{
			for (int j = 0; j < a[i].size(); ++j)
			{
				a[i][j] = tolower(a[i][j]);
			}
		}
	}
	for (int i = 0; i < a.size(); ++i)
	{
		if (main.find(a[i]) != main.end())
		{
			a.erase(a.begin() + i);
			--i;
		}
	}
	for (int i = 0; i < a.size(); ++i)
	{
		if ((a[i][0] >= 'a' && a[i][0] <= 'z') || (a[i][0] >= 'A' && a[i][0] <= 'Z') || (a[i][0] >= '0' && a[i][0] <= '9') || a[i][0] == '_')
		{

		}
		else
		{
			a.erase(a.begin() + i);
			--i;
		}
	}
	/*for (int i = 0; i < a.size(); ++i)
	{
	cout << a[i] << endl;
	}
	system("pause");*/
	if (ok == "no" && ok1 == "no")
	{
		for (int i = 0; i < a.size(); ++i)
		{
			if (a[i][0] >= '0' && a[i][0] <= '9')
			{
				a.erase(a.begin() + i);
				--i;
			}
		}
		for (int i = 0; i < a.size(); ++i)
		{
			for (int j = 0; j < a[i].size(); ++j)
			{
				a[i][j] = tolower(a[i][j]);
			}
		}
		set<string> cnt;
		for (int i = 0; i < a.size(); ++i)
		{
			if (cnt.find(a[i]) != cnt.end())
			{
				for (int j = 0; j < ans.size(); ++j)
				{
					if (ans[j].first == a[i])
					{
						++ans[j].second;
						break;
					}
				}
			}
			else
			{
				cnt.insert(a[i]);
				ans.push_back({ a[i], 1 });
			}
		}
	}
	else if (ok == "yes" && ok1 == "no")
	{
		for (int i = 0; i < a.size(); ++i)
		{
			if (a[i][0] >= '0' && a[i][0] <= '9')
			{
				a.erase(a.begin() + i);
				--i;
			}
		}
		set<string> cnt;
		for (int i = 0; i < a.size(); ++i)
		{
			if (cnt.find(a[i]) != cnt.end())
			{
				for (int j = 0; j < ans.size(); ++j)
				{
					if (ans[j].first == a[i])
					{
						++ans[j].second;
						break;
					}
				}
			}
			else
			{
				cnt.insert(a[i]);
				ans.push_back({ a[i], 1 });
			}
		}
	}
	else if (ok == "yes" && ok1 == "yes")
	{
		set<string> cnt;
		for (int i = 0; i < a.size(); ++i)
		{
			if (cnt.find(a[i]) != cnt.end())
			{
				for (int j = 0; j < ans.size(); ++j)
				{
					if (ans[j].first == a[i])
					{
						++ans[j].second;
						break;
					}
				}
			}
			else
			{
				cnt.insert(a[i]);
				ans.push_back({ a[i], 1 });
			}
		}
	}
	else if (ok == "no" && ok1 == "yes")
	{
		for (int i = 0; i < a.size(); ++i)
		{
			for (int j = 0; j < a[i].size(); ++j)
			{
				a[i][j] = tolower(a[i][j]);
			}
		}
		set<string> cnt;
		for (int i = 0; i < a.size(); ++i)
		{
			if (cnt.find(a[i]) != cnt.end())
			{
				for (int j = 0; j < ans.size(); ++j)
				{
					if (ans[j].first == a[i])
					{
						++ans[j].second;
						break;
					}
				}
			}
			else
			{
				cnt.insert(a[i]);
				ans.push_back({ a[i], 1 });
			}
		}
	}
	pair<int, int> ans1 = { -1, 0 };
	for (int i = 0; i < ans.size(); ++i)
	{
		if (ans1.second < ans[i].second)
		{
			ans1.second = ans[i].second;
			ans1.first = i;
		}
	}
	cout << ans[ans1.first].first;
}
