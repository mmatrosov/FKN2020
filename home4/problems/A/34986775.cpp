#include <cmath>

class Complex {
    double re;
    double im;

   public:
    // constructors

    explicit Complex(double _re) : re(_re), im(0) {
    }
    Complex(double _re, double _im) : re(_re), im(_im) {
    }

    // operations

    Complex& operator+=(Complex const& that) {
        re += that.re;
        im += that.im;
        return *this;
    }

    friend Complex operator+(Complex self, Complex const& that) {
        self += that;
        return self;
    }

    Complex& operator-=(Complex const& that) {
        re -= that.re;
        im -= that.im;
        return *this;
    }

    friend Complex operator-(Complex self, Complex const& that) {
        self -= that;
        return self;
    }

    friend Complex operator*(Complex const& self, Complex const& that) {
        return {self.re * that.re - self.im * that.im, self.re * that.im + self.im * that.re};
    }

    Complex& operator*=(Complex const& that) {
        // it is not really possible to multiply in-place
        // without creating temporary object
        *this = *this * that;
        return *this;
    }

    Complex& operator*=(double lambda) {
        re *= lambda;
        im *= lambda;
        return *this;
    }

    friend Complex operator*(Complex self, double lambda) {
        self *= lambda;
        return self;
    }

    friend Complex operator*(double lambda, Complex self) {
        self *= lambda;
        return self;
    }

    Complex& operator/=(Complex const& that) {
        *this *= that.Inverse();
        return *this;
    }

    friend Complex operator/(Complex self, Complex const& that) {
        self /= that;
        return self;
    }

    Complex& operator/=(double lambda) {
        re /= lambda;
        im /= lambda;
        return *this;
    }

    friend Complex operator/(Complex self, double lambda) {
        self /= lambda;
        return self;
    }

    Complex operator+() const {
        return *this;
    }

    Complex operator-() const {
        return {-re, -im};
    }

    // ???
    friend bool operator==(Complex const& self, Complex const& that) {
        return (self.re == that.re) && (self.im == that.im);
    }

    friend bool operator!=(Complex const& self, Complex const& that) {
        return !(self == that);
    }

    // getters
    double Re() const {
        return re;
    }

    double Im() const {
        return im;
    }

    // functions
    double Abs() const {
        return std::hypot(re, im);
    }

    Complex Inverse() const {
        double d = (re * re + im * im);
        return Complex(re, -im) / d;
    }
};

double abs(Complex const& c) {
    return c.Abs();
}