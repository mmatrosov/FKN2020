template <typename F>
class IntegrationMethod {
public:
    virtual double Integrate(F func, double left, double right, int count) {
        return 0;
    }
};

template <typename F>
class RectangleRule: public IntegrationMethod<F> {
public:
     double Integrate(F func, double left, double right, int count) {
        double dx = (right - left) / count;
        double x = left + dx / 2;
        double area = 0;
        for (int i = 1; i <= count; i++) {
            area += dx * func(x);
            x += dx;
        }
        return area;
    }
};

template <typename F>
class TrapezoidalRule: public IntegrationMethod<F> {
public:
    double Integrate(F func, double left, double right, int count) {
        double dx = (right - left) / count;
        double x = left + dx;
        double area = 0;
        for (int i = 1; i <= count; i++) {
            area += dx * (func(x) + func(x - dx)) / 2;
            x += dx;
        }
        return area;
    }
};