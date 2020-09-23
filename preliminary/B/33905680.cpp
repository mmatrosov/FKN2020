#include <iostream>

using namespace std;

int main()
{
    int k1, b1, k2, b2;
    cin >> k1 >> b1 >> k2 >> b2;
    if (k1 == k2){
        if (b1 == b2){
            cout << "coincide" << endl;
        }else{
            cout << "parallel" << endl;
        }
    }else{
        cout << "intersect" << endl;
        double b = b2 - b1;
        double k = k1 - k2;
        double x = b / k;
        double y = k1 * x + b1;
        cout.precision(100);
        cout << x << ' ' << y << endl;
    }
    return 0;
}
