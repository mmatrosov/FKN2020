#include <bits/stdc++.h>

using namespace std;

#define all(a) a.begin(),a.end()

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    double k1, b1;
    double k2, b2;
    cin >> k1 >> b1;
    cin >> k2 >> b2;
    if (k1 == k2 && b1 == b2) {
        cout << "coincide" << endl;
        return 0;
    }
    if (k1 == k2) {
        cout << "parallel" << endl;
        return 0;
    }
    double x = (b2-b1)/(k1-k2);
    cout<<"intersect"<<endl;
    cout<<fixed<<x<<' '<<(k1*x+b1)<<endl;
    return 0;
}
