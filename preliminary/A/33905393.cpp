#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back

const int MAXN = 1e4 + 10;

int main()
{
    int n;
    cin >> n;
    if (n % 4 == 0 || n == 1)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}

