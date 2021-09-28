#include <iostream>
#include "my_complex.h"
#include <cassert>

void test_abs(){
    Complex val(-3, 4);
    double abs = 5; 
    
    assert(val.abs() == abs);
    std::cout<<"TEST ABS OK\n";
}


void test_sum(){
    Complex val1(1, -1);
    Complex val2(-2, 2);
    Complex sum(-1, 1);
    
    assert(val1 + val2 == sum);
    std::cout<<"TEST SUM OK\n";
}

void test_sub(){
    Complex val1(1, -1);
    Complex val2(-2, 2);
    Complex sub(3, -3);
    
    assert(val1 - val2 == sub);
    std::cout<<"TEST SUB OK\n";
}

void test_mult_complex(){
    Complex val1(1, -1);
    Complex val2(-2, 2);
    Complex mult(0, 4);
    
    assert(val1 * val2 == mult);
    std::cout<<"TEST MULT COMPLEX OK\n";
}

void test_mult_scalar(){
    Complex val1(1, -1);
    double val2 = -10.5;
    Complex mult(-10.5, 10.5);
    
    assert(val1 * val2 == mult);
    std::cout<<"TEST MULT SCALAR OK\n";
}

void test_div_complex(){
    Complex val1(1, -1);
    Complex val2(-2, 2);
    Complex div(-0.5, 0);
    
    assert(val1 / val2 == div);
    std::cout<<"TEST DIV COMPLEX OK\n";
}

void test_div_scalar(){
    Complex val1(1, -1);
    double val2(0.25);
    Complex div(4, -4);
    
    assert(val1 / val2 == div);
    std::cout<<"TEST DIV SCALAR OK\n";
}

void test_asign(){
    Complex val1(1, -1);
    Complex val2(-2, 2);
    
    assert((val1 = val2) == val2);
    std::cout<<"TEST ASIGNMENT OK\n";
}

void test_plus_asign(){
    Complex val1(1, -1);
    Complex val2(-2, 2);
    Complex sum(-1, 1);
    
    assert((val1 += val2) == sum);
    std::cout<<"TEST SUM ASIGN OK\n";
}

void test_sub_asign(){
    Complex val1(1, -1);
    Complex val2(-2, 2);
    Complex sub(3, -3);
    
    assert((val1 -= val2) == sub);
    std::cout<<"TEST SUB ASIGN OK\n";
}

void test_mult_asign(){
    Complex val1(1, -1);
    Complex val2(-2, 2);
    Complex mult(0, 4);
    
    assert((val1 *= val2) == mult);
    std::cout<<"TEST MULT ASIGN OK\n";
}

void test_div_asign(){
    Complex val1(1, -1);
    Complex val2(-2, 2);
    Complex div(-0.5, 0);
    
    assert((val1 /= val2) == div);
    std::cout<<"TEST DIV ASIGN OK\n";
}

void test_bin_plus(){
    Complex val(1, -1);
    assert(+val == val);
    std::cout<<"TEST UNAR PLUS OK\n";
}

void test_bin_minus(){
    Complex val1(1, -1);
    Complex val2(-1, 1);
    assert(-val1 == val2);
    std::cout<<"TEST UNAR MINUS OK\n";
}

void test_equal(){
    Complex val(1, -1);

    assert((val == val) == true);
    assert((val == -val) == false);
    std::cout<<"TEST EQUALITY OK\n";
}

void test_nonequal(){
    Complex val(1, -1);

    assert((val != val) == false);
    assert((val != -val) == true);
    std::cout<<"TEST NONEQUALITY OK\n";
}

void test_conjugate(){
    Complex val1(1, -1);
    Complex val2(1, 1);
    assert(val1.conjugate() == val2);
    std::cout<<"TEST CONJUGATE OK\n";
}

void test_power(){
    Complex val1(5, -2);
    Complex val2(65.0, -142.0);
    int pow = 3;
    (val1^pow).print();
    val2.print();
    std::cout << val2.re << std::endl;
    assert((val1^pow) == val2);
    std::cout<<"TEST POWER OK\n";
}