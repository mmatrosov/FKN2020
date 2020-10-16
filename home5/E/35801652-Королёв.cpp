template <typename T>
class IntegrationMethod {
public:
    virtual double Integrate(T func, double l, double r, int k) {}
};

template <typename T>
class RectangleRule : public IntegrationMethod<T> {
public:
    virtual double Integrate(T func, double l, double r, int k) {
        double ans = 0;
        double step = (r - l) / k;
        for (double i = l; i < r - step / 2; i += step) {
            double tl = i, tr = i + step;
            ans += func((tr + tl) / 2) * (tr - tl);
        }
        return ans;
    }
};

template <typename T>
class TrapezoidalRule : public IntegrationMethod<T> {
public:
    virtual double Integrate(T func, double l, double r, int k) {
        double ans = 0;
        double step = (r - l) / k;
        for (double i = l; i < r - step / 2; i += step) {
            double tl = i, tr = i + step;
            ans += ((func(tl) + func(tr)) / 2) * (tr - tl);
        }
        return ans;
    }
};