#include <iostream> 
#include <vector> 

#include <ctime> 
#include <cstdlib> 

using namespace std;

using ll = long long;

int main() 
{
	int k;
	cin >> k;

	if (k % 4 == 0 || k == 1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	cin >> k;
}