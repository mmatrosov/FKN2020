#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <bitset>
#include <thread>
#include <random>
#include <queue>
#include <deque>
#include <ctime>
#include <cmath>
#include <stack>
#include <set>
#include <map>

using namespace std;

//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long double ans = sqrt(x1*x1+y1*y1)+sqrt(x2*x2+y2*y2);
    ans = min(ans, fabs(sqrt(x1*x1+y1*y1)-sqrt(x2*x2+y2*y2))+fabs(atan2(y1, x1)-atan2(y2, x2))*min(sqrt(x1*x1+y1*y1), sqrt(x2*x2+y2*y2)));
    cout << setprecision(15) << ans;

    return 0;
}
