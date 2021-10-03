#ifndef MY_COMPLEX_H
#define MY_COMPLEX_H

struct Complex
{
    double re;
    double im;

    Complex(double other_re, double other_im);
    Complex(const Complex &other);

    Complex &operator=(const Complex &rhs);
    Complex operator+(const Complex &rhs) const;
    Complex operator+(double rhs) const;
    Complex operator-(const Complex &rhs) const;
    Complex operator-(double rhs) const;
    Complex operator*(const Complex &rhs) const;
    Complex operator*(double rhs) const;
    Complex operator/(const Complex &rhs) const;
    Complex operator/(double rhs) const;

    Complex &operator+=(const Complex &rhs);
    Complex &operator-=(const Complex &rhs);
    Complex &operator*=(const Complex &rhs);
    Complex &operator/=(const Complex &rhs);
    Complex &operator+=(double rhs);
    Complex &operator-=(double rhs);
    Complex &operator*=(double rhs);
    Complex &operator/=(double rhs);

    Complex operator+() const;
    Complex operator-() const;

    bool operator==(const Complex &rhs) const;
    bool operator!=(const Complex &rhs) const;

    void print();
    double abs() const;
    Complex conjugate() const;
    Complex operator^(int exp) const;
};

Complex operator+(double lhs, const Complex &rhs);
Complex operator-(double lhs, const Complex &rhs);
Complex operator*(double lhs, const Complex &rhs);
Complex operator/(double lhs, const Complex &rhs);

#endif // MY_COMPLEX_H