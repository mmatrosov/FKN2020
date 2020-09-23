// A.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<set>
#include<unordered_set>
#include<deque>
#include<queue>
#include<string>
#include<map>
#include<unordered_map>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <cassert>

using namespace std;
#define int long long
typedef long long lli;
typedef long double ld;
//const double E = 0.0000001;
const int INF = 1e7;
#define forn(i, s, f) for (int i = s; i < f; ++i)
#define ft first
#define sd second
#define fora(i, n) for (auto i : n)
#define sz(a) (int)(a).size()
#define sort_(a) sort(a.begin(), a.end())
#define pb push_back
#define mp make_pair
#define fast_ cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

signed main()
{
    fast_;
    int k;
    cin >> k;
    if (k % 4 == 0 || k == 1) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
