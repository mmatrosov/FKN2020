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
    if(n==1){
        cout << "YES";
        return 0;
    }
    for(int i = 1; ; i++){
        int jij = 4*i-4;
        if(jij==n){
            cout << "YES";
            return 0;
        }
        if(jij>n)
            break;
    }
    cout << "NO";

    return 0;
}
