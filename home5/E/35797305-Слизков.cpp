template <typename F>
class IntegrationMethod {
public:
    virtual double Integrate(F, double, double, int) const = 0;
};

template <typename F>
class RectangleRule : public IntegrationMethod<F> {
public:
    double Integrate(F f, double left, double right, int n) const override {
        double result = 0, dx = (right - left) / n;
        for (int i = 0; i < n; ++i) {
            double x_left = left + dx * i, x_right = left + dx * (i + 1);
            result += f((x_left + x_right) / 2) * dx;
        }
        return result;
    }
};

template <typename F>
class TrapezoidalRule : public IntegrationMethod<F> {
public:
    double Integrate(F f, double left, double right, int n) const override {
        double result = 0, dx = (right - left) / n;
        for (int i = 0; i < n; ++i) {
            double x_left = left + dx * i, x_right = left + dx * (i + 1);
            result += (f(x_left) + f(x_right)) / 2 * dx;
        }
        return result;
    }
};
