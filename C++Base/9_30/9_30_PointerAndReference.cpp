/**
 * 测试指针与引用
 */
#include "iostream"
using namespace std;

int main() {
    double i_1 = 100;
    double &i_2 = i_1;
    cout << i_2 << endl;
    double *i_3 = &i_1;
    cout << i_3 << endl;
    i_3 = &i_2;
    cout << i_3 << " " << &i_2 << " " << i_2 << endl;
    cout << *i_3 << endl;
    cout << "i_1: " << sizeof(i_1) << endl;
    cout << "i_2: " << sizeof(i_2) << endl;
    cout << "i_3: " << sizeof(i_3) << endl;
    const int &i_4 = 50;
    cout << "i_4: " << i_4 << " size: " << sizeof(i_4) << endl;
    double &i_5 = i_1;
    cout << i_5 << " " << sizeof(i_5) << endl;
    double *i_6 = i_3;
    cout << "i_6: " << i_6 << " " << *i_6 << " " << sizeof(i_6) << endl;
    int i = 2;
    int *ii = &i;
    cout << sizeof(ii) << " " << sizeof(ii) << endl;
    char *ch1 = nullptr;
    cout << "sizeof(ch1): " << sizeof(ch1) << endl;
    // cout << "===" << ch1;
    char *ch2;
    cout << "sizeof(ch2): " << sizeof(ch2) << endl;
    // cout << "+++" << ch2;
    return 0;
}