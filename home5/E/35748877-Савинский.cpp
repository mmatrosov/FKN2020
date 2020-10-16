template <typename T>
class IntegrationMethod {
   protected:
    virtual double Term(const T&, double, double) const {
    }

   public:
    double Integrate(const T& f, double a, double b, int n) const {
        double x = a, res = 0;
        for (int i = 0; i < n; ++i) {
            double wid = (b - a) / n;
            res += Term(f, x, x + wid) * wid;
            x += wid;
        }
        return res;
    }
};

template <typename T>
class RectangleRule : public IntegrationMethod<T> {
    double Term(const T& f, double x1, double x2) const {
        return f((x1 + x2) / 2);
    }
};

template <typename T>
class TrapezoidalRule : public IntegrationMethod<T> {
    double Term(const T& f, double x1, double x2) const {
        return (f(x1) + f(x2)) / 2;
    }
};
