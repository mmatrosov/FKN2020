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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i<n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end())-a.begin());
    int k;
    cin >> k;
    for(int i = 0; i<k; i++){
        int x;
        cin >> x;
        int l = -1, r = a.size();
        while(r-l>1){
            int m = (l+r)/2;
            if(a[m]>=x)
                r = m;
            else
                l = m;
        }
        cout << l+1 << '\n';
    }

    return 0;
}
