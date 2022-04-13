#include <iostream>

using namespace std;

// class A {};

// class B {
// private:
//     int a = 10;

// public:
//     virtual void Show();
// };

// class C : public B {
// public:
//     void Show();
// };

// class D : public B {};

// // 此时 E 的实例对象中会存在两份 B 中的成员变量
// class E : public C, public D {
// public:
//     void Show() {
//         cout << "E Show" << endl;
//         C::Show();
//     }
// };

// int main() {
//     A a;
//     cout << sizeof(a) << endl;  // 空类对象大小是一个字节
//     A* a_point;
//     cout << sizeof(a_point) << endl;  // 64 位操作系统中指针大小是一个字节

//     B b;
//     cout << sizeof(b) << endl;
//     C c;
//     cout << sizeof(c) << endl;
//     D d;
//     cout << sizeof(d) << endl;
//     E e;
//     cout << sizeof(e) << endl;
// }

class A {
public:
    A() : a(1){};
    void printA() { cout << a << endl; }
    long long a;
};

class B : virtual public A {};

class C : virtual public A {};

class D : public B, public C {};

int main() {
    D d;
    cout << sizeof(d) << endl;
    d.a = 10;
    d.printA();
    // d.B::printA();
    // d.C::printA();
    C c;
    c.printA();
    B b;
    b.printA();
}