#include <iostream>
#include <cmath>
#include "my_complex.h"

const double EPSILON = 1e-9;

Complex::Complex(double other_re, double other_im)
    : re(other_re), im(other_im)
{}

Complex::Complex(const Complex &other)
    : re(other.re), im(other.im)
{}

void Complex::print()
{
    if (im >= 0)
        std::cout << "rhs = " << re << " + " << im << "i\n";
    else
        std::cout << "rhs = " << re << " - " << -im << "i\n";
}

double Complex::abs() const
{
    return sqrt(re * re + im * im);
}

Complex &Complex::operator=(const Complex &rhs)
{
    re = rhs.re;
    im = rhs.im;
    return (*this);
}

Complex Complex::operator+(const Complex &rhs) const
{
    return Complex(re + rhs.re, im + rhs.im);
}

Complex Complex::operator+(double rhs) const
{
    return Complex(re + rhs, im);
}

Complex Complex::operator-(const Complex &rhs) const
{
    return Complex(re - rhs.re, im - rhs.im);
}

Complex Complex::operator-(double rhs) const
{
    return Complex(re - rhs, im);
}

Complex Complex::operator*(const Complex &rhs) const
{
    return Complex(re * rhs.re - im * rhs.im, im * rhs.re + re * rhs.im);
}

Complex Complex::operator*(double rhs) const
{
    return Complex(re * rhs, im * rhs);
}

Complex Complex::operator/(const Complex &rhs) const
{
    double new_re = (re * rhs.re + im * rhs.im) / (rhs.abs() * rhs.abs());
    double new_im = (im * rhs.re - re * rhs.im) / (rhs.abs() * rhs.abs());
    return Complex(new_re, new_im);
}

Complex Complex::operator/(double rhs) const
{
    return Complex(re / rhs, im / rhs);
}

Complex &Complex::operator+=(const Complex &rhs)
{
    re += rhs.re;
    im += rhs.im;
    return (*this);
}

Complex &Complex::operator-=(const Complex &rhs)
{
    re -= rhs.re;
    im -= rhs.im;
    return (*this);
}

Complex &Complex::operator*=(const Complex &rhs)
{
    double re_cp = re * rhs.re - im * rhs.im;
    double im_cp = im * rhs.re + re * rhs.im;
    re = re_cp;
    im = im_cp;
    return (*this);
}

Complex &Complex::operator/=(const Complex &rhs)
{
    double re_cp = (re * rhs.re + im * rhs.im) / (rhs.abs() * rhs.abs());
    double im_cp = (im * rhs.re - re * rhs.im) / (rhs.abs() * rhs.abs());
    re = re_cp;
    im = im_cp;
    return *this;
}

Complex &Complex::operator+=(double rhs)
{
    re += rhs;
    return (*this);
}

Complex &Complex::operator-=(double rhs)
{
    re -= rhs;
    return (*this);
}

Complex &Complex::operator*=(double rhs)
{
    re *= rhs;
    im *= rhs;
    return (*this);
}

Complex &Complex::operator/=(double rhs)
{
    re /= rhs;
    im /= rhs;
    return *this;
}

Complex Complex::operator+() const
{
    return Complex(this->re, this->im);
}

Complex Complex::operator-() const
{
    return Complex(-this->re, -this->im);
}

bool Complex::operator==(const Complex &rhs) const
{
    Complex delta = *this - rhs;
    return delta.abs() < EPSILON;
}

bool Complex::operator!=(const Complex &rhs) const
{
    return !(*this == rhs);
}

Complex Complex::conjugate() const
{
    return Complex(re, -im);
}

Complex Complex::operator^(int exp) const
{
    double arg = atan(im / re);
    double abs = sqrt(re * re + im * im);
    double new_re = pow(abs, exp) * cos(exp * arg);
    double new_im = pow(abs, exp) * sin(exp * arg);
    return Complex(new_re, new_im);
}

Complex operator+(double lhs, const Complex &rhs)
{
    return Complex(lhs + rhs.re, rhs.im);
}

Complex operator-(double lhs, const Complex &rhs)
{
    return Complex(lhs - rhs.re, -rhs.im);
}

Complex operator*(double lhs, const Complex &rhs)
{
    return Complex(lhs * rhs.re, lhs * rhs.im);
}

Complex operator/(double lhs, const Complex &rhs)
{
    return Complex(lhs, 0) / rhs;
}
