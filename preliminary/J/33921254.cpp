#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n, m;
vector<vector<char>> A(1005, vector<char>(1005, '0'));

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    char cur = 'A';
    int s = 1, sum = 0;
    int i = 0, j = 0;
    bool r = 1;
    while (sum + s <= n * m) {
        int p = s;
        if (sum + 2 * s + 1 > n * m) p = n * m - sum;
        map<char, bool> used;
        int tmp = p;
        int q = i, w = j;
        bool u = r;
        while (tmp--) {
            if (i > 0) used[A[i - 1][j]] = 1;
            if (j > 0) used[A[i][j - 1]] = 1;
            if (j < m - 1) used[A[i][j + 1]] = 1;
            if (r) ++j;
            else --j;
            if (j >= m) j = m - 1, r = 0, ++i;
            if (j < 0) j = 0, ++i, r = 1;
        }
        for (char a = 'A'; a <= 'Z'; ++a) {
            if (!used[a]) {
                cur = a;
                break;
            }
        }
        i = q, j = w, r = u;
        while (p--) {
            A[i][j] = cur;
            if (r) ++j;
            else --j;
            if (j >= m) j = m - 1, r = 0, ++i;
            if (j < 0) j = 0, ++i, r = 1;
        }
        sum += s;
        ++s;
    }
    --s;
    cout << s << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (A[i][j] == '0') A[i][j] = cur;
            cout << A[i][j];
        }
        cout << "\n";
    }
    return 0;
}
