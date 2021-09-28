#ifndef MY_COMPLEX_H
#define MY_COMPLEX_H
struct Complex {
    double re;
    double im;    

    Complex();
    Complex(double r);
    Complex(double r, double i);
    Complex(const Complex& c);
    ~Complex();

    void print();
    double abs();
    Complex& operator=(const Complex& a);
    Complex operator+(const Complex& a);
    Complex operator-(const Complex& a);
    Complex operator*(const Complex& a);
    Complex operator*(double num);
    Complex operator/(const Complex& a);
    Complex operator/(double num);

    Complex& operator+=(const Complex& a);
    Complex& operator-=(const Complex& a);
    Complex& operator*=(const Complex& a);
    Complex& operator/=(const Complex& a);
    
    Complex operator+();
    Complex operator-();

    bool operator == (Complex a);
    bool operator != (Complex a);

    Complex conjugate();
    Complex operator^(int c);
};
#endif

