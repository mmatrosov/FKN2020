#include <iostream>

using namespace std;

int main()
{
    int k;
    cin >> k;
    if (k % 4 == 0 || k == 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
