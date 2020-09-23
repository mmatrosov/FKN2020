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

double PI = 3.14159265358979323846;

struct Point{
    double x, y;
    Point(double x0 = 0, double y0 = 0){
        this->x = x0;
        this->y = y0;
    }
};

struct Vector{
    double x, y;
    Vector(double x0 = 0, double y0 = 0){
        this->x = x0;
        this->y = y0;
    }
    Vector(const Point & A, const Point & B){
        this->x = B.x - A.x;
        this->y = B.y - A.y;
    }
    
    double len(){
        return sqrt(x * x + y * y);
    }
    
    double angle(){
        return atan2(y, x);
    }
};

double dot_product(const Vector & A, const Vector & B){
    return A.x * B.x + A.y * B.y;
}

double cross_product(const Vector & A, const Vector & B){
    return A.x * B.y - A.y * B.x;
}

double angle(Vector A, Vector B){
    return atan2(cross_product(A, B), dot_product(A, B));
}

Point O(0, 0);

signed main(){
    Point A, B;
    cin >> A.x >> A.y >> B.x >> B.y;
    Vector OA(O, A), OB(O, B);
    double ang = fabs(angle(OA, OB));
    double rA = OA.len();
    double rB = OB.len();
    double ans = min(fabs(rA - rB) + min(rA, rB) * ang, rA + rB);
    cout.precision(20);
    cout << ans << "\n";
    return 0;
}

