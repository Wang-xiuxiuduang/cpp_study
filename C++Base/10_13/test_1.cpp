#include <iostream>
#include <stack>

using namespace std;

/**
 * 测试 stack 的一些方法
 */
int main() {
    cout << "---------------This is test_1.cpp---------------" << endl;
    stack<int> st_1;
    st_1.push(1);
    st_1.push(2);
    st_1.push(3);
    cout << st_1.top() << endl;
    st_1.pop();  // pop() 的返回值是 void，需要将 pop 与 top 分开使用
    cout << st_1.top() << endl;
    while (!st_1.empty()) {
        cout << "move first element" << endl;
        st_1.pop();
    }
    cout << st_1.size() << endl;
    return 0;
}