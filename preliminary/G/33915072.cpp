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
pair<int, int> fun(vector<pair<int, int>> &ar, int n){
    int maxx = 0, mask = 0;
    unordered_set<int> S;
    for (int i = 32; i >= 0; i--) {
        mask |= (1LL << i);
        forn(i, 0, n) {
            S.insert((ar[i].ft & mask));
        }
        int newM = (maxx | (1LL << i));
        fora (pre, S) {
            if (S.find(newM ^ pre) != S.end()) {
                maxx = newM;
                break;
            }

        }    
        S.clear();
    }
    set<pair<int, int>> S2;
    forn(i, 0, n) {
        S2.insert(ar[i]);
        S.insert(ar[i].ft);
    }
    fora(pre, S2) {
        if (S.find(maxx ^ pre.ft) != S.end()) {
            forn(i, 0, n) {
                if (ar[i].ft == (maxx ^ pre.ft)) {
                    return { ar[i].sd, pre.sd };
                }
           }
        }

    }

}
vector<int> kol;

void dfs(int v, int pr, vector <vector<pair<int, int>>>& g, int cu) {
    kol[v] = cu;
    fora(u, g[v]) {
        if (u.ft != pr) {
            dfs(u.ft, v, g, (cu ^ u.sd));
        }
    }
}

signed main()
{
    fast_;

    int n;
    cin >> n;
    vector <vector<pair<int, int>>> g(n);
    forn(i, 0, n - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
    }
    kol.resize(n);
    dfs(0, -1, g, 0);
    vector<pair<int, int>> ar;
    forn(i, 0, n) {
        //cout << kol[i] << endl;
        ar.pb({ kol[i], i + 1 });
    }
    pair<int, int> an = fun(ar, n);
    cout << an.ft << " " << an.sd;
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
