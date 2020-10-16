#include <cmath>

template <typename T>
class IntegrationMethod {
public:
    virtual double Integrate(T func, double leftBorder, double rightBorder, int partsCount) const {
    }
};

template <typename T>
class RectangleRule : public IntegrationMethod<T> {
public:
    double Integrate(T f, double leftBorder, double rightBorder, int partsCount) const override {
        double result = 0.0;
        double xl = leftBorder, xr;
        double diff = (rightBorder - leftBorder) / partsCount;
        for (int i = 0; i < partsCount; ++i) {
            xr = xl + diff;
            result += f((xl + xr) / 2.0);
            xl = xr;
        }
        return result * diff;
    }
};

template <typename T>
class TrapezoidalRule : public IntegrationMethod<T> {
public:
    double Integrate(T f, double leftBorder, double rightBorder, int partsCount) const override {
        double result = 0.0;
        double xl = leftBorder, xr;
        double diff = (rightBorder - leftBorder) / partsCount;
        for (int i = 0; i < partsCount; ++i) {
            xr = xl + diff;
            result += (f(xl) + f(xr)) / 2.0;
            xl = xr;
        }
        return result * diff;
    }
};