#include<bits/stdc++.h>
#define int long long int
#define ld long double
#define ft first
#define sc second
#define pb push_back
using namespace std;
const int maxn = 1001;
char tab[maxn][maxn];
signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int col = 0;
    int ans = 0;
    int tk = 1;
    int add = 0;
    for (int d = 0; d < n * m; d++) {
        if (d + tk <= n * m) {
            col++;
            col %= 2;
            if (((d + tk ) / m) > d / m) {
                add += 2;
            }
            ans++;
            for (int i = d; i < d + tk; i++) {
                tab[i / m][i % m] = 'A' + (col + add) % 26;
            }
            //col++;
            d = d + tk - 1;
            tk++;
        } else {
            for (int i = d; i < n * m; i++) {
                tab[i / m][i % m] = 'A' + (col + add) % 26;
            }
            break;
        }
    }
    cout << ans << "\n";
    for (int d = 0; d < n; d++) {
        if (d % 2 == 0) {
            for (int i = 0; i < m; i++) {
                cout << tab[d][i];
            }
        } else {
            for (int i = m - 1; i >= 0; i--) {
                cout << tab[d][i];
            }
        }
        cout << "\n";
    }
}
