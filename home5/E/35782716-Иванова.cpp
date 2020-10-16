#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <functional>

template<typename T>
class IntegrationMethod {
public:
    virtual double Integrate(std::function<T> f, double left_end, double right_end,
                                                                    int num_parts) {
        return 0;
    }

    virtual ~IntegrationMethod() {
    }
};

template<typename T>
class RectangleRule: public IntegrationMethod<T> {
    public:
    double Integrate(std::function<T> f, double left_end, double right_end, int num_parts)
                                                                                override {
        double res = 0;
        for (int i = 0; i < num_parts; ++i) {
            double x1 = (left_end * (num_parts - i) + right_end * i) / num_parts;
            double x2 = (left_end * (num_parts - (i + 1)) + right_end * (i + 1)) / num_parts;
            res += f((x1 + x2) / 2) * (x2 - x1);
        }
        return res;
    }
};

template<typename T>
class TrapezoidalRule: public IntegrationMethod<T> {
    public:
    double Integrate(std::function<T> f, double left_end, double right_end, int num_parts)
                                                                                override {
        double res = 0;
        for (int i = 0; i < num_parts; ++i) {
            double x1 = (left_end * (num_parts - i) + right_end * i) / num_parts;
            double x2 = (left_end * (num_parts - (i + 1)) + right_end * (i + 1)) / num_parts;
            res += ((f(x1) + f(x2)) / 2) * (x2 - x1);
        }
        return res;
    }
};