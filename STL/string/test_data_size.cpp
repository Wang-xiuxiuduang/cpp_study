#include <cfloat>
#include <climits>
#include <iostream>

class Test {
public:
    Test() { std::cout << "constructor\n"; }
    ~Test() { std::cout << "destructor\n"; }
};

int main() {
    // Test test;
    Test* test_1 = new Test();
    delete test_1;
    std::cout << "==============\n";
    Test* test_2 = new Test[3];
    delete[] test_2;
    std::cout << "==============\n";
    int num1;
    std::cout << "int sizeof = " << sizeof(num1) << std::endl;
    std::cout << INT_MAX << std::endl;
    std::cout << INT_MIN << std::endl;
    short num2;
    std::cout << "short sizeof = " << sizeof(num2) << std::endl;
    std::cout << SHRT_MIN << std::endl;
    long num3;
    std::cout << "long sizeof = " << sizeof(num3) << std::endl;
    std::cout << LONG_MAX << std::endl;
    std::cout << LONG_MIN << std::endl;
    long long num4;
    std::cout << "long long sizeof = " << sizeof(num4) << std::endl;
    std::cout << LLONG_MAX << std::endl;
    std::cout << LLONG_MIN << std::endl;
    float num5;
    std::cout << "float sizeof = " << sizeof(num5) << std::endl;
    std::cout << FLT_MAX << std::endl;
    std::cout << FLT_MIN << std::endl;
    double num6;
    std::cout << "double sizeof = " << sizeof(num6) << std::endl;
    std::cout << DBL_MAX << std::endl;
    std::cout << DBL_MIN << std::endl;
    long double num7;
    std::cout << "long double sizeof = " << sizeof(num7) << std::endl;
    unsigned int num8;
    std::cout << "unsigned int sizeof = " << sizeof(num8) << std::endl;
    std::cout << UINT_MAX << std::endl;
    unsigned short num9;
    std::cout << "unsigned short sizeof = " << sizeof(num9) << std::endl;
    unsigned long num10;
    std::cout << "unsigned long sizeof = " << sizeof(num10) << std::endl;
    std::cout << ULONG_MAX << std::endl;
    std::cout << ULLONG_MAX << std::endl;
}