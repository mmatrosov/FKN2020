#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <bitset>
#include <fstream>
#include <unordered_set>
#include <unordered_map>

using namespace std;


#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")


#define int long long
#define eb emplace_back
#define pb push_back
#define ld long double
#define mp make_pair
#define f first
#define s second
#define deb(a) cerr << #a << " = " << a << '\n';
#define fast() { \
    ios_base::sync_with_stdio(0); \
    cin.tie(0); \
    cout << fixed << setprecision(20); \
    cerr << fixed << setprecision(11); \
}



const int INF = 1e18 + 7;
const ld EPS = 1e-7;
const int MAXI = 350;
const int MOD = 1e9 + 7;
const int MOD1 = 998244353;
const int MAXST = 2000000;
const int P = 31;
const int P1 = 37;
const ld PI = 3.14159265358979323;


ostream &operator<<(ostream &stream, const pair <int, int> &p) {
    stream << p.first << ' ' << p.second << ' ';
    return stream;
}

vector < char > ans;

signed main(){
    fast();
    srand(time(0));
    int n, m;
    cin >> n >> m;
    int x = 1, all = n * m, cur = x;
    char s = 'A';
    for (int i = 0; i < n; i++){
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {
                ans.eb(s);
                cur--;
                all--;
                if (cur == 0) {
                    if (all >= x + 1) {
                        x++;
                        cur = x;
                        int dist = m - 1 - j;
                        if (dist >= x){
                            if ((s - 'A') % 2 == 0)
                                s++;
                            else
                                s--;
                        }
                        else {
                            s = s + 2 - (s - 'A') % 2;
                            if (s >= 'Z')
                                s = 'A';
                        }
                    }
                    else
                        cur = x;
                }
            }
        }
        else {
            vector < char > ans1;
            for (int j = m - 1; j >= 0; j--) {
                ans1.eb(s);
                cur--;
                all--;
                if (cur == 0) {
                    if (all >= x + 1) {
                        x++;
                        cur = x;
                        int dist = j;
                        if (dist >= x){
                            if ((s - 'A') % 2 == 0)
                                s++;
                            else
                                s--;
                        }
                        else {
                            s = s + 2 - (s - 'A') % 2;
                            if (s >= 'Z')
                                s = 'A';
                        }
                    }
                    else
                        cur = x;
                }
            }
            reverse(ans1.begin(), ans1.end());
            for (auto j: ans1)
                ans.eb(j);
        }
    }
    cout << x << '\n';
    for (int i = 0; i < n; i++, cout << '\n'){
        for (int j = 0; j < m; j++){
            cout << ans[i * m + j];
        }
    }


    return 0;
}