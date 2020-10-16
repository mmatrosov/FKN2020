template <typename T>
class IntegrationMethod {
public:
    virtual double Integrate(T& func, double l, double r, int n) = 0;
};

template <typename T>
class RectangleRule : public IntegrationMethod<T> {
public:
    double Integrate(T& func, double l, double r, int n) override {
        double ans = 0;
        double seglen = (r - l) / static_cast<double>(n);
        double x0 = l - seglen;
        double x1 = l;
        for (int i = 0; i < n; ++i) {
            x0 += seglen;
            x1 += seglen;
            ans += func((x0 + x1) / 2.0) * (x1 - x0);
        }
        return ans;
    }
};

template <typename T>
class TrapezoidalRule : public IntegrationMethod<T> {
public:
    double Integrate(T& func, double l, double r, int n) override {
        double ans = 0;
        double seglen = (r - l) / static_cast<double>(n);
        double x0 = l - seglen;
        double x1 = l;
        for (int i = 0; i < n; ++i) {
            x0 += seglen;
            x1 += seglen;
            ans += (func(x0) + func(x1)) / 2.0 * (x1 - x0);
        }
        return ans;
    }
};