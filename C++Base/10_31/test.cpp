#include <iostream>
#include <vector>

int main() {
    std::vector<double> vec(10);
    // 看了.size()的使用
    std::cout << vec.size() << std::endl;
    // 输出 24，因为在64位系统中一个指针占8个字节
    std::cout << sizeof(vec) << std::endl;
}