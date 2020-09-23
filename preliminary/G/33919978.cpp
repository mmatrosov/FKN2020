#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#pragma optimizitaion_level 3
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bitset>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cmath>
#include <functional>
#include <algorithm>
#include <set>
#include <cassert>
#include <deque>
#include <unordered_set>
#include <numeric>
using namespace std;
#define kekek ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long

struct edge {
	int to, w;
};

struct node {
	node* zero, * one;
	int term;

	node() {
		zero = one = nullptr;
		term = 0;
	}
};

const int lg = 32;
int n;
vector<vector<edge>> g;
vector<int> xo;

int ans = 0, best1 = 1, best2 = 1;

void dfs(int v, int p = -1) {
	for (auto u : g[v]) {
		if (u.to != p) {
			xo[u.to] = xo[v] ^ u.w;
			dfs(u.to, v);
		}
	}
}

node* tree = nullptr;
bitset<lg> kek;
int num;
void add(int j, node*& now) {
	if (now == nullptr) {
		now = new node();
	}

	if (j >= 0) {
		if (kek[j]) {
			add(j - 1, now->one);
		}
		else {
			add(j - 1, now->zero);
		}
	}
	else {
		now->term = num;
	}
}

void down(int j, node*& now) {
	if (now->term != 0 || j < 0) {
		if (ans < (xo[num] ^ xo[now->term])) {
			ans = xo[num] ^ xo[now->term];
			best1 = num;
			best2 = now->term;
		}
		return;
	}

	if (kek[j]) {
		if (now->zero != nullptr) down(j - 1, now->zero);
		else down(j - 1, now->one);
	}
	else {
		if (now->one != nullptr) down(j - 1, now->one);
		else down(j - 1, now->zero);
	}
}

signed main() {
	kekek;
	cin >> n;
	g.resize(n + 1);
	xo.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		g[a].push_back({ b, w });
		g[b].push_back({ a, w });
	}

	dfs(1);

	for (int i = 1; i <= n; i++) {
		bitset<lg> kek1(xo[i]);
		kek = kek1;
		num = i;
		add(lg - 1, tree);
	}

	for (int i = 1; i <= n; i++) {
		bitset<lg> kek1(xo[i]);
		kek = kek1;
		num = i;
		down(lg - 1, tree);
	}

	cout << best1 << " " << best2;

	return 0;
}