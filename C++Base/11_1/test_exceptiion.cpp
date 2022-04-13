#include <iostream>

int calculate(int num) {
    if (num <= 0)
        throw "bad parameter";  // throw 负责抛出异常
    return num + num;
}

int main() {
    for (int i = 0; i < 10; ++i) {
        int num = (int)rand() - (int)rand();
        int result = 0;
        // try 块负责标识其中特定的异常可能被激活的代码块
        // catch 块负责捕获对应的异常
        try {  // start of try block
            result = calculate(num);
        } catch (int n) {  // start of exception handler
            std::cout << "is int" << std::endl;
        } catch (const char* s) {
            std::cout << s << std::endl;
        }
        if (result != 0)
            std::cout << result << std::endl;
    }
    return 0;
}