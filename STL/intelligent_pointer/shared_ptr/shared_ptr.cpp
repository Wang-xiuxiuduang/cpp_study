#include <iostream>
#include <memory>

void foo(std::shared_ptr<int> i) { (*i)++; }

int main() {
    // auto pointer = new int(10); // illegal, no direct assignment
    // Constructed a std::shared_ptr
    std::shared_ptr<int> pointer = std::make_shared<int>(10);
    foo(pointer);
    std::cout << *pointer << std::endl;  // 11
    std::cout << pointer.use_count() << std::endl;

    std::shared_ptr<int> pointer_2 = pointer;
    std::cout << pointer.use_count() << std::endl;

    int* p = pointer_2.get();
    std::cout << p << "=====" << *p << std::endl;
    std::cout << pointer.use_count() << std::endl;

    std::shared_ptr<int> pointer_3 = pointer;
    std::cout << pointer.use_count() << std::endl;

    pointer.reset();
    std::cout << pointer.use_count() << std::endl;

    // The shared_ptr will be destructed before leaving the scope
    return 0;
}