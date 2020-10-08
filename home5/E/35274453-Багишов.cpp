template <class F>
class IntegrationMethod {
public:
    virtual double Integrate(F const& func, double begin, double end, int parts) const = 0;
};

IntegrationMethod<int>* fff1;

template <class F>
class RectangleRule : public IntegrationMethod<F> {
    double Integrate(F const& func, double begin, double end, int parts) const override {
        double res = 0;
        double unit = (end - begin) / parts;
        for (int i = 0; i < parts; ++i) {
            double x1 = begin + i * unit;
            double x2 = x1 + unit;
            res += func((x1 + x2) / 2);
        }
        res *= unit;
        return res;
    }
};

template <class F>
class TrapezoidalRule : public IntegrationMethod<F> {
    double Integrate(F const& func, double begin, double end, int parts) const override {
        double res = 0;
        double unit = (end - begin) / parts;
        for (int i = 0; i < parts; ++i) {
            double x1 = begin + i * unit;
            double x2 = x1 + unit;
            res += (func(x1) + func(x2)) / 2;
        }
        res *= unit;
        return res;
    }
};