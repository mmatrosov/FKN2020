#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    size_t M;
    cin >> M;
    string dummy;
    getline(cin, dummy);
    vector<vector<string>> v(M);
    size_t Nmax = 0;
    for (size_t i = 0; i != M; ++i) {
        size_t Ni;
        cin >> Ni;
        if (Ni > Nmax)
            Nmax = Ni;
        getline(cin, dummy);
        v[i].resize(Ni);
        for (size_t j = 0; j != Ni; ++j)
             getline(cin, v[i][j]);
    }
    for (size_t j = 0; j != Nmax; ++j) {
        for (size_t i = 0; i != M; ++i) {
            if (i > 0)
                cout << "\t";
            if (j < v[i].size())
                cout << v[i][j];
        }
        cout << "\n";
    }
}
