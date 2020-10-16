#include <iostream>

template <typename T>
class IntegrationMethod {
public:
    virtual double Integrate(T f, double a, double b, int cnt) {
    }
    virtual ~IntegrationMethod() {
    }
};

template <typename T>
class RectangleRule : public IntegrationMethod<T> {
public:
    double Integrate(T f, double a, double b, int cnt) override {
        double ans = 0;
        for (int i = 0; i < cnt; ++i) {
            double x_1 = a + (b - a) * static_cast<double>(i) / static_cast<double>(cnt);
            double x_2 = a + (b - a) * static_cast<double>(i + 1) / static_cast<double>(cnt);
            ans += f((x_1 + x_2) / 2) * (x_2 - x_1);
        }
        return ans;
    }
    ~RectangleRule() {
    }
};

template <typename T>
class TrapezoidalRule : public IntegrationMethod<T> {
public:
    double Integrate(T f, double a, double b, int cnt) override {
        double ans = 0;
        for (int i = 0; i < cnt; ++i) {
            double x_1 = a + (b - a) * static_cast<double>(i) / static_cast<double>(cnt);
            double x_2 = a + (b - a) * static_cast<double>(i + 1) / static_cast<double>(cnt);
            ans += (f(x_1) + f(x_2)) / 2 * (x_2 - x_1);
        }
        return ans;
    }
    ~TrapezoidalRule() {
    }
};
