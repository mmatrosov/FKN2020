#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define l first
#define r second
#define pb push_back
#define int long long

using namespace std;

const int maxn = 2e5 + 1, mod = 1e9 + 7;

int a[maxn], pf[maxn];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = -1;
    sort(a + 1, a + n + 1);
    set<int> st;
    for (int i = 1; i <= n; i++) {
        pf[i] = pf[i - 1] + (st.find(a[i]) == st.end());
        st.insert(a[i]);
    }
    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        int cp; cin >> cp;
        cout << pf[(int)(lower_bound(a, a + n + 1, cp) - a) - 1] << '\n';
    }
    return 0;
}
