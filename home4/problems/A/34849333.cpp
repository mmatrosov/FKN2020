#include <iostream>
#include <cmath>

class Complex {
 private:
    double r, i;

 public:
    Complex(double _r = 0.0, double _i = 0.0) {
        r = _r;
        i = _i;
    }

    double Re() const {
        return r;
    }

    double Im() const {
        return i;
    }

    inline bool operator==(const Complex& z) const {
        return ((r == z.Re()) && (i == z.Im()));
    }

    inline bool operator!=(const Complex& z) const {
        return !((r == z.Re()) && (i == z.Im()));
    }

    Complex operator=(const Complex& z) {
        r = z.Re();
        i = z.Im();
        return *this;
    }

    Complex operator+(const Complex& z) const {
        Complex res = Complex(r + z.Re(), i + z.Im());
        return res;
    }

    Complex operator+(double a) const {
        Complex res = Complex(r + a, i);
        return res;
    }

    Complex operator-(const Complex& z) const {
        Complex res = Complex(r - z.Re(), i - z.Im());
        return res;
    }

    Complex operator-(double a) const {
        Complex res = Complex(r - a, i);
        return res;
    }

    Complex operator+() const {
        Complex res = Complex(r, i);
        return res;
    }

    Complex operator-() const {
        Complex res = Complex(-r, -i);
        return res;
    }

    Complex operator*(const Complex& z) const {
        double nr = r * z.Re() - i * z.Im(), ni = r * z.Im() + i * z.Re();
        Complex res = Complex(nr, ni);
        return res;
    }

    Complex operator*(double a) const {
        Complex res = Complex(r * a, i * a);
        return res;
    }

    Complex operator/(const Complex& z) const {
        double ab = z.Re() * z.Re() + z.Im() * z.Im();
        Complex res = Complex(r, i);
        if (ab == 0) {
            return res;
        }
        double nr = (r * z.Re() + i * z.Im()) / ab, ni = (i * z.Re() - r * z.Im()) / ab;
        res = Complex(nr, ni);
        return res;
    }

    Complex operator/(double a) const {
        Complex res = Complex(r, i);
        if (a == 0) {
            return res;
        }
        res = Complex(r / a, i / a);
        return res;
    }
};

double abs(const Complex& z) {
    return std::sqrt(z.Re() * z.Re() + z.Im() * z.Im());
}

Complex operator*(double a, const Complex& z) {
    double nr = a * z.Re(), ni = a * z.Im();
    Complex res = Complex(nr, ni);
    return res;
}