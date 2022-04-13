#include <iostream>
using namespace std;

/**
 * 测试 array new 与 array delete
 */
namespace november_21 {
class Test01 {
private:
    int id;
    int age;

public:
    Test01() {
        cout << "default ctor..."
             << "this = " << this << " id = " << id << endl;
    }
    Test01(int id) {
        this->id = id;
        cout << "parament ctor"
             << "this = " << this << " id = " << id << endl;
    }
    ~Test01() {
        cout << "default dtor..."
             << "this = " << this << " id = " << id << endl;
    }
};
}  // namespace november_21

int main() {
    int size = 3;
    november_21::Test01* test01 = new november_21::Test01[size];
    november_21::Test01* temp = test01;
    cout << "test01 = " << test01 << "  temp = " << temp << endl;
    // for (int i = 0; i < size; ++i) {
    //     // 由于不能直接调用构造函数，这里使用 spacement new（定点的 new）
    //     new (temp++) november_21::Test01(i);
    // }
    // cout << "test01 = " << test01 << "  temp = " << temp << endl;
    // 使用 array delete，调用 3 次构造函数，逆反调用
    delete[] test01;
    // delete test01;
    return 0;
}