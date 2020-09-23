#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n % 4 == 0 || n == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
