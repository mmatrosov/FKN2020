#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>

using namespace std;

//#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;

#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << endl
#else
#define debug(x) 0
#endif

template<typename T = int>
T input() {
    T res;
    cin >> res;
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr) {
        cin >> i;
    }
    sort(all(arr));
    arr.erase(unique(all(arr)), arr.end());
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int p;
        cin >> p;
        cout << lower_bound(all(arr), p) - arr.begin() << endl;
    }
}
