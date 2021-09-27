#include <iostream>
#include <cmath>

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
    Complex(const Complex& c){
      re = c.re; 
      im = c.im;
   }
    ~Complex(){};

    void print();
    float abs();
    Complex& operator=(const Complex& a);
    const Complex operator+(const Complex& a);
    const Complex operator-(const Complex& a);
    const Complex operator*(const Complex& a);
    const Complex operator/(const Complex& a);

    Complex operator+();
    Complex operator-();

    bool operator == (Complex a);
    bool operator != (Complex a);

    Complex conjugate();
    Complex operator^(int c);
};

void Complex::print(){
    if (im >= 0) {std::cout << "z = " << re << " + " << im << "i\n";}
    else         {std::cout << "z = " << re << " - " << -im << "i\n";}
        
}

float Complex::abs(){
    return sqrt(re*re + im*im);
}

Complex& Complex::operator=(const Complex& a){
    re = a.re;
    im = a.im;
    return (*this);
}

const Complex Complex::operator+(const Complex& a){
    Complex temp;
    temp.re = re + a.re;
    temp.im = im + a.im;
    return temp;
}

const Complex Complex::operator-(const Complex& a){
    Complex temp;
    temp.re = re - a.re;
    temp.im = im - a.im;
    return temp;
 }

const Complex Complex::operator*(const Complex& a){
    Complex temp;
    temp.re = re*a.re - im*a.im;
    temp.im = im*a.re + re*a.im;
    return temp;
}

const Complex Complex::operator/(const Complex& a){
    Complex temp;
    float abs = (a.re*a.re + a.im*a.im);
    temp.re = (re*a.re + im*a.im) / abs;
    temp.im = (im*a.re - re*a.im) / abs;
    return temp;
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
    float abs = sqrt(re*re + im*im);
    float arg = atan(im / re);
    temp.re = pow(abs, c) * cos(c * arg);
    temp.im = pow(abs, c) * sin(c * arg);
    return temp;
}


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
