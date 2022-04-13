#include <iostream>

using std::cout;
using std::endl;

class Fun {
private:
    int m_num;

public:
    Fun(int num) { m_num = num; }
    int getNum() { return m_num; }
    // 重载 () 以达到实现对象函数的目的
    int operator()(char num) { return num + m_num; }

    void fun(int num_1, int num_2) { cout << "This is fun_1" << endl; }
    int fun(int num_1) {
        cout << "This is fun_2" << endl;
        return 0;
    }
    void fun(char ch) { cout << "This is fun_3" << endl; }
};

int main() {
    Fun fun(12);
    cout << sizeof(fun(100)) << endl;
    cout << fun(100) << endl;

    fun.fun(1, 2);
    cout << fun.fun(12) << endl;
    fun.fun('A');

    return 0;
}