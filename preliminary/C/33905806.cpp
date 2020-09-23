#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define F first
#define S second
#define pb push_back
mt19937 rnd;

void delete_copies(vector<int>& a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
}

vector<int> a;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    delete_copies(a);
    n = a.size();
    int k;
    cin >> k;
    while (k--) {
        int p;
        cin >> p;
        if (a.empty()) {
            cout << "0\n";
        }
        else if (a[0] >= p) {
            cout << "0\n";
        }
        else {
            int lef = 0, rig = n - 1;
            while (lef < rig) {
                int mid = (lef + rig) / 2;
                if (a[mid + 1] < p) {
                    lef = mid + 1;
                }
                else {
                    rig = mid;
                }
            }
            cout << lef + 1 << "\n";
        }
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
