#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define int long long

using namespace std;
const int N = 207702;
double k1, b1, k2, b2;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> k1 >> b1;
    cin >> k2 >> b2;
    if (k1 == k2 && b1 == b2){
        cout << "coincide" << endl;
        return 0;
    }
    if (k1 == k2){
        cout << "parallel" << endl;
        return 0;
    }
    cout << "intersect" << endl;
    double a = b2 - b1;
    double b = k1 - k2;
    double x = a / b;
    double y = x * k1 + b1;
    cout.precision();
    cout << fixed << x << " " << y << endl;
}
