#include <cmath>
#include <iostream>
#include <memory>
#include <string>

template<typename F>
class IntegrationMethod {
public:
    IntegrationMethod() {}
    virtual long double Integrate(F f, double x, double y, int n) {}
};

template<typename F>
class RectangleRule : public IntegrationMethod<F> {
public:
    virtual long double Integrate(F f, double x, double y, int n) {
        double ans = 0;
        double d = (y - x) / n;
        for (int i = 0; i < n; ++i) {
            double x1 = x + d * i;
            double x2 = x + d * i + d;
            ans += f((x1 + x2) / 2) * (x2 - x1);
        }
        return ans;
    }
};

template<typename F>
class TrapezoidalRule : public IntegrationMethod<F> {
public:
    virtual long double Integrate(F f, double x, double y, int n) {
        double ans = 0;
        double d = (y - x) / n;
        for (int i = 0; i < n; ++i) {
            double x1 = x + d * i;
            double x2 = x + d * i + d;
            ans += ((f(x1) + f(x2)) / 2) * (x2 - x1);
        }
        return ans;
    }
};