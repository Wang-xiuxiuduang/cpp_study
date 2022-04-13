#include <iostream>

using namespace std;

class A {
private:
    int num1;
    int num2;

public:
    int (*arr_ptr)[5];
    virtual void func1(){};
    virtual void func2(){};
    virtual void func3(){};
    virtual void func4(){};
};

class B : public A {
private:
    // int num3;
};

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    A a;
    void (*ptr)();
    cout << sizeof(a) << endl;
    B b;
    cout << sizeof(b) << endl;
    B* b_ptr = new B();
    b_ptr->arr_ptr = &arr;
    return 0;
}