#include <iostream>
#include <math.h>
#define double long double
using namespace std;

const double pi = acos(-1);

int main()
{
    double x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    double len1 = sqrt(x1 * x1 + y1 * y1), len2 = sqrt(x2 * x2 + y2 * y2);
    if (len1 > len2) {
        std::swap(x1, x2);
        std::swap(y1, y2);
        std::swap(len1, len2);
    }
    std::cout.precision(10);
    double ang1 = atan2(y1, x1), ang2 = atan2(y2, x2), angdiff = fabs(ang1 - ang2);
    if (angdiff > pi)
        angdiff = 2 * pi - angdiff;
    std::cout << std::min(len1 + len2, len2 - len1 + len1 * angdiff);
    return 0;
}
