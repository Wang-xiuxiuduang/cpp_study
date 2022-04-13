#include <iostream>
#include <memory>
struct Foo {
    Foo() { std::cout << "Foo::Foo" << std::endl; }
    ~Foo() { std::cout << "Foo::~Foo" << std::endl; }
    void foo() { std::cout << "Foo::foo" << std::endl; }
};

void f(const Foo&) { std::cout << "f(const Foo&)" << std::endl; }

int main() {
    // std::unique_ptr<Foo> p1(new Foo());
    std::unique_ptr<Foo> p1(new std::unique_ptr<Foo>::element_type());
    // p1 不空, 输出
    if (p1)
        p1->foo();
    {
        std::unique_ptr<Foo> p2(std::move(p1));
        f(*p2);
        if (p2) {
            p2->foo();
        }
        if (p1) {
            p1->foo();
        }
        p1 = std::move(p2);  // 可转移，但不可复制
        if (p2) {
            p2->foo();
        }
        std::cout << "p2 is destructed" << std::endl;
    }
    // p1 不空, 输出
    if (p1)
        p1->foo();
    // Foo 的实例会在离开作用域时被销毁
}