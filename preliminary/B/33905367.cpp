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
    int k1, b1, k2, b2;
    cin >> k1 >> b1 >> k2 >> b2;
    if(k1==k2){
        if(b1==b2)
            cout << "coincide";
        else
            cout << "parallel";
        return 0;
    }
    long double x = ((long double)(b2-b1))/(k1-k2);
    long double y = k1*x+b1;
    cout << "intersect\n";
    cout << setprecision(15) << x << ' ' << y;

    return 0;
}
