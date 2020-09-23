#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(all(v));

    v.erase(unique(all(v)), v.end());

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;

        cout << lower_bound(all(v), x) - v.begin() << "\n";
    }

	return 0;
}