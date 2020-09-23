#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int k;
    cin >> k;

    if (k == 1) {
        cout << "YES\n";
        return 0;
    }

    k += 4;

    if (k < 0 || k % 2) {
        cout << "NO\n";
    }
    else {
        k /= 2;
        if (k % 2 == 0 && k > 1) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

	return 0;
}