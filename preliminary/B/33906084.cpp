#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<set>
#include<random>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<cstdio>
#include<cassert>
#include<sstream>
#include<set>

#define int long long int

using namespace std;

signed main(){
    int k1, b1; cin >> k1 >> b1;
    int k2, b2; cin >> k2 >> b2;
    if(k1 == k2 && b1 == b2)cout << "coincide\n";
    else if(b1 != b2 && k1 == k2)cout << "parallel\n";
    else{
        double x = 1.0 * (b2 - b1) / (k1 - k2);
        double y = k1 * x + b1;
        cout.precision(20);
        cout << "intersect\n" << x << " " << y << "\n";
    }
    return 0;
}

