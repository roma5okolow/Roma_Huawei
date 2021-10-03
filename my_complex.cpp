#include <iostream>
#include <cmath>
#include "my_complex.h"

#define EPSILON 1e-9

Complex::Complex() {};

Complex::Complex(double val_re, double val_im){
    re = val_re;
    im = val_im;
}
Complex::Complex(const Complex& z){
    re = z.re; 
    im = z.im;
}
Complex::~Complex(){};

void Complex::print(){
    if (im >= 0) {std::cout << "z = " << re << " + " << im << "i\n";}
    else         {std::cout << "z = " << re << " - " << -im << "i\n";}        
}

double Complex::abs() const{
    return sqrt(re*re + im*im);
}

Complex& Complex::operator=(const Complex& z){
    re = z.re;
    im = z.im;
    return (*this);
}

Complex Complex::operator+(const Complex& z)const{
    return Complex(re + z.re, im + z.im);
}

Complex Complex::operator+(double rhs)const{
    return Complex(re + rhs, im);
}

Complex Complex::operator-(const Complex& z)const{
    return Complex(re - z.re, im - z.im);
 }

Complex Complex::operator-(double rhs)const{
    return Complex(re - rhs, im);
}

Complex Complex::operator*(const Complex& z)const{
    return Complex(re*z.re - im*z.im, im*z.re + re*z.im);
}

Complex Complex::operator*(double rhs)const{
    return Complex(re*rhs, im*rhs);
}

Complex Complex::operator/(const Complex& z) const{
    double new_re = (re*z.re + im*z.im) / (z.abs()*z.abs());
    double new_im = (im*z.re - re*z.im) / (z.abs()*z.abs());
    return Complex(new_re, new_im);
}

Complex Complex::operator/(double rhs)const{
    return Complex(re/rhs, im/rhs);
}

Complex& Complex::operator+=(const Complex& z){
    re += z.re;
    im += z.im;
    return (*this);
}

Complex& Complex::operator-=(const Complex& z){
    re -= z.re;
    im -= z.im;
    return (*this);
}

Complex& Complex::operator*=(const Complex& z){
    double re_cp = re*z.re - im*z.im;
    double im_cp = im*z.re + re*z.im;
    re = re_cp;
    im = im_cp;
    return (*this);
}

Complex& Complex::operator/=(const Complex& z){
    double re_cp = (re*z.re + im*z.im) / (z.abs() * z.abs());
    double im_cp = (im*z.re - re*z.im) / (z.abs() * z.abs());
    re = re_cp;
    im = im_cp;
    return *this;
}
Complex Complex::operator+()const{
    return Complex(this->re, this->im);
}

Complex Complex::operator-()const{
    return Complex(-this->re, -this->im);
}

bool Complex::operator==(const Complex& z)const{ 
    Complex delta = *this - z;
    return (delta.abs() < EPSILON);
}

bool Complex::operator!=(const Complex& z)const{
    Complex delta = *this - z;
    return (delta.abs() >= EPSILON);
}

Complex Complex::conjugate()const{
    return Complex(re, -im);
}

Complex Complex::operator^(int c) const{
    double arg = atan(im / re);
    double abs = sqrt(re*re + im*im);
    double new_re = pow(abs, c) * cos(c * arg);
    double new_im = pow(abs, c) * sin(c * arg);
    return Complex(new_re, new_im);
}

Complex operator+(double lhs, const Complex& z){
    return Complex(lhs + z.re, z.im);
}

Complex operator-(double lhs, const Complex& z){
    return Complex(lhs - z.re, -z.im);
}

Complex operator*(double lhs, const Complex& z){
    return Complex(lhs * z.re, lhs * z.im);
}

Complex operator/(double lhs, const Complex& z){
    return Complex(lhs, 0) / z;
}