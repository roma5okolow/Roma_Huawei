#ifndef Documents_Huawei_My_complex_h
#define Documents_Huawei_My_complex_h

struct Complex {
    double re;
    double im;    

    Complex();
    Complex(double val_re, double val_im);
    Complex(const Complex& z);
    ~Complex();

    void print();
    double abs()const;

    Complex& operator=(const Complex& z);
    Complex operator+(const Complex& z)const;
    Complex operator+(double rhs)const;
    Complex operator-(const Complex& z)const;
    Complex operator-(double rhs)const;
    Complex operator*(const Complex& z)const;
    Complex operator*(double rhs)const;
    Complex operator/(const Complex& z)const;
    Complex operator/(double rhs)const;

    Complex& operator+=(const Complex& z);
    Complex& operator-=(const Complex& z);
    Complex& operator*=(const Complex& z);
    Complex& operator/=(const Complex& z);
    
    Complex operator+()const;
    Complex operator-()const;

    bool operator == (const Complex& z)const;
    bool operator != (const Complex& z)const;

    Complex conjugate()const;
    Complex operator^(int c) const;
};

Complex operator+(double lhs, const Complex& z);
Complex operator-(double lhs, const Complex& z);
Complex operator*(double lhs, const Complex& z);
Complex operator/(double lhs, const Complex& z);
#endif

