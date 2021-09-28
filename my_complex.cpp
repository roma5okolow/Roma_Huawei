#include <iostream>
#include <cmath>
#include "my_complex.h"

Complex::Complex() {};
Complex::Complex(double r){
    re = r;
    im = 0;
}
Complex::Complex(double r, double i){
    re = r;
    im = i;
}
Complex::Complex(const Complex& c){
    re = c.re; 
    im = c.im;
}
Complex::~Complex(){};

void Complex::print(){
    if (im >= 0) {std::cout << "z = " << re << " + " << im << "i\n";}
    else         {std::cout << "z = " << re << " - " << -im << "i\n";}
        
}

double Complex::abs(){
    return sqrt(re*re + im*im);
}

Complex& Complex::operator=(const Complex& a){
    re = a.re;
    im = a.im;
    return (*this);
}

Complex Complex::operator+(const Complex& a){
    Complex temp;
    temp.re = re + a.re;
    temp.im = im + a.im;
    return temp;
}

Complex Complex::operator-(const Complex& a){
    Complex temp;
    temp.re = re - a.re;
    temp.im = im - a.im;
    return temp;
 }

Complex Complex::operator*(const Complex& a){
    Complex temp;
    temp.re = re*a.re - im*a.im;
    temp.im = im*a.re + re*a.im;
    return temp;
}

Complex Complex::operator*(double num){
    Complex temp;
    temp.re = re*num;
    temp.im = im*num;
    return temp;
}

Complex Complex::operator/(const Complex& a){
    Complex temp;
    double abs = (a.re*a.re + a.im*a.im);
    temp.re = (re*a.re + im*a.im) / abs;
    temp.im = (im*a.re - re*a.im) / abs;
    return temp;
}

Complex Complex::operator/(double num){
    Complex temp;
    temp.re = re/num;
    temp.im = im/num;
    return temp;
}

Complex& Complex::operator+=(const Complex& a){
    re += a.re;
    im += a.im;
    return (*this);
}

Complex& Complex::operator-=(const Complex& a){
    re -= a.re;
    im -= a.im;
    return (*this);
}

Complex& Complex::operator*=(const Complex& a){
    double re_cp = re*a.re - im*a.im;
    double im_cp = im*a.re + re*a.im;
    re = re_cp;
    im = im_cp;
    return (*this);
}

Complex& Complex::operator/=(const Complex& a){
    double abs = (a.re*a.re + a.im*a.im);
    double re_cp = (re*a.re + im*a.im) / abs;
    double im_cp = (im*a.re - re*a.im) / abs;
    re = re_cp;
    im = im_cp;
    return *this;
}
Complex Complex::operator+(){
    return Complex(this->re, this->im);
}

Complex Complex::operator-(){
    return Complex(-this->re, -this->im);
}

bool Complex::operator == (Complex a){
    return (re == a.re && im  == a.im);
}

bool Complex::operator != (Complex a){
    return (re != a.re || im  != a.im);
}

Complex Complex::conjugate(){
    Complex temp(re, -im);
    return temp;
}

Complex Complex::operator^(int c){
    Complex temp;
    double abs = std::sqrt(re*re + im*im);
    double arg = std::atan(im / re);
    temp.re = std::pow(abs, c) * std::cos(c * arg);
    temp.im = std::pow(abs, c) * std::sin(c * arg);
    return temp;
}