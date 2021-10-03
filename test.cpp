#include "my_complex.h"
#include <iostream>

static bool err_flag = false;

void test_construct();
void test_asign();
void test_sum();
void test_sub();
void test_mult();
void test_div();
void test_plus_asign();
void test_sub_asign();
void test_mult_asign();
void test_div_asign();
void test_bin_plus();
void test_bin_minus();
void test_equal();
void test_nonequal();
void test_abs();
void test_conjugate();
void test_power();

int main()
{
    test_construct();
    test_abs();
    test_sum();
    test_sub();
    test_mult();
    test_div();
    test_asign();
    test_plus_asign();
    test_sub_asign();
    test_mult_asign();
    test_div_asign();
    test_bin_plus();
    test_bin_minus();
    test_equal();
    test_nonequal();
    test_conjugate();
    test_power();

    if (!err_flag)
        std::cout << "ALL TESTS PASSED\n";

    return 0;
}

void test_construct()
{
    Complex val1(1, 2);
    Complex val2(val1);
    if (val1.re != 1 || val1.im != 2 || val2.re != 1 || val2.im != 2)
    {
        std::cout << "TEST CONSTRUCT FAILED\n";
        err_flag = true;
    }
}

void test_abs()
{
    Complex val(-3, 4);
    double abs = 5;

    if (val.abs() != abs)
    {
        std::cout << "TEST ABS FAILED\n";
        err_flag = true;
    }
}

void test_sum()
{
    Complex val1(1, -1);
    Complex val2(-2, 2);
    Complex sum1(11.1, -1);
    Complex sum2(-1, 1);
    double num = 10.1;

    if (val1 + num != sum1 || num + val1 != sum1 || val1 + val2 != sum2)
    {
        std::cout << "TEST SUM FAILED\n";
        err_flag = true;
    }
}

void test_sub()
{
    Complex val1(1, -1);
    Complex val2(-2, 2);
    Complex sub1(0.9, -1);
    Complex sub2(3, -3);
    Complex sub3(-0.9, 1);
    double num = 0.1;

    if (val1 - num != sub1 || val1 - val2 != sub2 || num - val1 != sub3)
    {
        std::cout << "TEST SUB FAILED\n";
        err_flag = true;
    }
}

void test_mult()
{
    Complex val1(1, -1);
    Complex val2(-2, 2);
    Complex mult1(0, 4);
    Complex mult2(-10.5, 10.5);
    double num = -10.5;

    if (val1 * val2 != mult1 || val1 * num != mult2 || num * val1 != mult2)
    {
        std::cout << "TEST MULT FAILED\n";
        err_flag = true;
    }
}

void test_div()
{
    Complex val1(1, -1);
    Complex val2(-2, 2);
    Complex div1(-0.5, 0);
    Complex div2(4, -4);
    Complex div3(0.125, 0.125);
    double num(0.25);

    if (val1 / val2 != div1 || val1 / num != div2 || num / val1 != div3)
    {
        std::cout << "TEST DIV FAILED\n";
        err_flag = true;
    }
}

void test_asign()
{
    Complex val1(1, -1);
    Complex val2(-2, 2);

    if ((val1 = val2) != val2)
    {
        std::cout << "TEST ASIGNMENT FAILED\n";
        err_flag = true;
    }
}

void test_plus_asign()
{
    Complex val1(1, -1);
    Complex val2(-2, 2);
    Complex sum(-1, 1);

    if ((val1 += val2) != sum)
    {
        std::cout << "TEST SUM ASIGN FAILED\n";
        err_flag = true;
    }
}

void test_sub_asign()
{
    Complex val1(1, -1);
    Complex val2(-2, 2);
    Complex sub(3, -3);

    if ((val1 -= val2) != sub)
    {
        std::cout << "TEST SUB ASIGN FAILED\n";
        err_flag = true;
    }
}

void test_mult_asign()
{
    Complex val1(1, -1);
    Complex val2(-2, 2);
    Complex mult(0, 4);

    if ((val1 *= val2) != mult)
    {
        std::cout << "TEST MULT ASIGN FAILED\n";
        err_flag = true;
    }
}

void test_div_asign()
{
    Complex val1(1, -1);
    Complex val2(-2, 2);
    Complex div(-0.5, 0);

    if ((val1 /= val2) != div)
    {
        std::cout << "TEST DIV ASIGN FAILED\n";
        err_flag = true;
    }
}

void test_bin_plus()
{
    Complex val(1, -1);

    if (+val != val)
    {
        std::cout << "TEST UNAR PLUS FAILED\n";
        err_flag = true;
    }
}

void test_bin_minus()
{
    Complex val1(1, -1);
    Complex val2(-1, 1);

    if (-val1 != val2)
    {
        std::cout << "TEST UNAR MINUS FAILED\n";
        err_flag = true;
    }
}

void test_equal()
{
    Complex val(1, -1);

    if ((val == val) != true || (val == -val) != false)
    {
        std::cout << "TEST EQUALITY FAILED\n";
        err_flag = true;
    }
}

void test_nonequal()
{
    Complex val(1, -1);

    if ((val != val) != false || (val != -val) != true)
    {
        std::cout << "TEST NONEQUALITY FAILED\n";
        err_flag = true;
    }
}

void test_conjugate()
{
    Complex val1(1, -1);
    Complex val2(1, 1);

    if (val1.conjugate() != val2)
    {
        std::cout << "TEST CONJUGATE FAILED\n";
        err_flag = true;
    }
}

void test_power()
{
    Complex val1(5, -2);
    Complex val2(65.0, -142.0);
    int pow = 3;
    if ((val1 ^ pow) != val2)
    {
        std::cout << "TEST POWER FAILED\n";
        err_flag = true;
    }
}
