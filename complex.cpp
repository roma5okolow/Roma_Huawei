//sum, sub, mult, div, pow, Conjugate, log, sqrt, abs

#include <stdio.h>
#include <iostream>
#include <math.h>
//#include <doctest.h>

class Complex {
    double re;
    double im;    

public:
    Complex() {};

    Complex(double r){
        re = r;
        im = 0;
    }

    Complex(double r, double i){
        re = r;
        im = i;
    }

    ~Complex(){};

    void print(){
        if (im >= 0) {std::cout << "z = " << re << " + " << im << "i\n";}
        else         {std::cout << "z = " << re << " - " << -im << "i\n";}
        
    }

    float abs(){
        return sqrt(re*re + im*im);
    }

    Complex& operator=(const Complex& a){
        re = a.re;
        im = a.im;
        return (*this);
    }

    Complex operator+(Complex a){
        Complex temp;
        temp.re = re + a.re;
        temp.im = im + a.im;
        return temp;
    }

    Complex operator-(Complex a){
        Complex temp;
        temp.re = re - a.re;
        temp.im = im - a.im;
        return temp;
    }

    Complex operator*(Complex a){
        Complex temp;
        temp.re = re*a.re - im*a.im;
        temp.im = im*a.re + re*a.im;
        return temp;
    }

    Complex operator/(Complex a){
        Complex temp;
        float abs = (a.re*a.re + a.im*a.im);
        temp.re = (re*a.re + im*a.im) / abs;
        temp.im = (im*a.re - re*a.im) / abs;
        return temp;
    }

    Complex operator+(){
        return Complex(this->re, this->im);
    }

    Complex operator-(){
        return Complex(-this->re, -this->im);
    }


    bool operator == (Complex a){
        return (re == a.re && im  == a.im);
    }

    bool operator != (Complex a){
        return (re != a.re || im  != a.im);
    }

    Complex conjugate(){
        Complex temp(re, -im);
        return temp;
    }

    Complex operator^(int c){
        Complex temp;
        float abs = sqrt(re*re + im*im);
        float arg = atan(im / re);
        temp.re = pow(abs, c) * cos(c * arg);
        temp.im = pow(abs, c) * sin(c * arg);
        return temp;
    }
};

int main(){

    Complex a (1.5, 10.5);
    a.print();
    Complex b (0.5, 0.5);
    Complex c = a + b;
    c.print();
    c = (a * b);
    c.print();
    c = (a / b);
    c.print();
    bool d = a == a;
    bool e = a != a;
    std::cout << d << " " << e << "\n";
    Complex f = a.conjugate();
    f.print();
    f = a ^ 3;
    f.print();
    Complex g = -f;
    g.print();
    return 0;
}
