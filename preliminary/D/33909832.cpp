#include <iostream> 
#include <vector> 
#include <set> 

#include <ctime> 
#include <cmath> 
#include <algorithm> 
#include <cstdlib> 
#include <iomanip> 

using namespace std;

using ll = long long;
using ld = long double;

ld eps = 1e-6;
ld pi = 3.14159265359;
ld INF = 1e16;

struct vec2
{
	vec2()
	{
		x = 0;
		y = 0;
	}
	vec2(ld _x, ld _y)
	{
		x = _x;
		y = _y;
	}
	ld x, y;

	vec2 operator* (ld r) const
	{
		return vec2(x * r, y * r);
	}
	vec2 operator/ (ld r) const
	{
		return vec2(x / r, y / r);
	}
};

ld vabs(vec2& v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}
vec2 vnorm(vec2& v)
{
	ld a = vabs(v);

	if (a < eps)
		return v;
	return v / a;
}

ld cross_prod(vec2 v1, vec2 v2)
{
	return (v1.x * v2.y - v2.x * v1.y);
}

ld dot_prod(vec2 v1, vec2 v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}

ld angle(vec2 v1, vec2 v2)
{
	return abs(atan2(cross_prod(v1, v2), dot_prod(v1, v2)));
}

int main() 
{
	ld xa, ya, xb, yb;
	cin >> xa >> ya >> xb >> yb;

	vec2 va(xa, ya);
	vec2 vb(xb, yb);

	ld ra = vabs(va);
	ld rb = vabs(vb);

	vec2 va1 = vnorm(va) * rb;
	vec2 vb1 = vnorm(vb) * ra;

	ld ang = angle(va, vb);

	vector<vector<pair<int, ld>>> g(5);

	/*
	v[0] = (0, 0)
	v[1] = va
	v[2] = va1
	v[3] = vb
	v[4] = vb1
	
	*/

	ld dr = abs(ra - rb);

	g[0].emplace_back(1, ra);
	g[0].emplace_back(2, rb);
	g[0].emplace_back(3, rb);
	g[0].emplace_back(4, ra);

	g[1].emplace_back(2, dr);
	g[1].emplace_back(4, ang * ra);
	g[1].emplace_back(0, ra);

	g[2].emplace_back(1, dr);
	g[2].emplace_back(3, ang * rb);
	g[2].emplace_back(0, rb);
	
	g[3].emplace_back(4, dr);
	g[3].emplace_back(2, ang * rb);
	g[3].emplace_back(0, rb);

	g[4].emplace_back(3, dr);
	g[4].emplace_back(1, ang * ra);
	g[4].emplace_back(0, ra);

	vector<bool> used(5, 0);
	vector<ld> dist(5, INF);

	dist[1] = 0;

	int v = 1;
	while (v != -1)
	{
		used[v] = 1;
		for (int i = 0; i < g[v].size(); i++)
		{
			int u = g[v][i].first;
			ld w = g[v][i].second;
			if (!used[u] && dist[u] > dist[v] + w)
			{
				dist[u] = dist[v] + w;
			}
		}

		v = -1;
		for (int i = 0; i < 5; i++)
		{
			if (used[i])
				continue;
			if (v == -1 || dist[i] < dist[v])
				v = i;
		}
	}
	cout << setprecision(20) << dist[3] << endl;
	cin >> xa;
}