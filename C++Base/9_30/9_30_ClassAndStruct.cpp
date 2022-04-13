/**
 * 测试 class 与 struct 的区别
 */
#include "iostream"
using namespace std;

struct str {
    void printVal() { cout << val << endl; }
    int getVal() { return val + 1; }
    void setVal(int v) { val = v; }

private:
    int val;
} st;

int main() {
    cout << "This is test class and struct..." << endl;
    str testStr;
    testStr.setVal(456);
    testStr.printVal();
    // st.val = 100;
    st.setVal(123);
    cout << st.getVal() << endl;
    int null = 11, *pr = &null;
    cout << null << endl;
    cout << pr << " " << *pr << endl;
    // s.val = 100;
    // int i = s.getVal();
    // cout << i << endl;
    return 0;
}