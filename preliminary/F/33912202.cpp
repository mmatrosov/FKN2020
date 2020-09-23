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
    int n, k;
    cin >> n >> k;
    vector<int> ar;
    vector<int> kol;
    map<int, int> M;
    forn(i, 0, n) {
        int a;
        cin >> a;
        if (a > 0) {
            M[a] += 1;
        }
        //cin >> ar[i];
    }
    fora(i, M) {
        ar.pb(i.ft);
        kol.push_back(i.sd);
        //cout << i.ft << " " << i.sd << endl;
    }
    //sort_(ar);
    if (k >= sz(ar)) {
        if (sz(ar) == 0) {
            ar.push_back(1);
        }
        forn(i, 0, sz(ar)) {
            cout << ar[i] << " ";
        }
        forn(i, 0, k - sz(ar)) {
            cout << ar.back() + 1 + i << " ";
        }
    }
    else {
        n = sz(ar);
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(n, 0)));
        vector<vector<int>> dp2(n + 1, vector<int>(k + 1, 0));
        vector<int> su(n + 1, 0);
        forn(i, 1, n + 1) {
            su[i] = su[i - 1] + kol[i - 1];
           // cout << su[i] << endl;
        }
        forn(i, 1, n + 1) {
            forn(j, 1, k + 1) {
                forn(u, j - 1, i) {
                    if (ar[u] <= ar[i - 1]) {
                        if (ar[u] < ar[i - 1]) {
                            dp[i][j][u] = dp2[u][j - 1] + ar[u] * (su[i] - su[u]);
                        }
                        else {
                            dp[i][j][u] = dp2[i - 1][j - 1] + ar[u] * kol[i - 1];
                        }
                       // dp[i][j][u] = max(dp[i - 1][j][u] + ar[u] * kol[u], dp2[i - 1][j - 1] + ar[u] * kol[u]);
                        dp2[i][j] = max(dp2[i][j], dp[i][j][u]);
                    }

                }
                
            }
        }
        //cout << "A\n";
        int cu = k;
        vector<int> an;
        int i = n;
       while(i > 0){
            if (cu > 0) {
                int ma = -1, in = 0;
                forn(u, 0, i) {
                    if (ma < dp[i][cu][u]) {
                        ma = dp[i][cu][u];
                        in = u;
                    }
                }
                an.push_back(ar[in]);
                cu--;
                i = in;
            }
            else {
                i = 0;
            }
        }
        sort_(an);
        forn(i, 0, k) {
            cout << an[i] << " ";
        }
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
