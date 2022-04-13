
#include "my_string.h"

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    // String s1;
    // String s2 = "Hello";
    // cout << "Hello world!\n";
    // cout << s2 << "==length=" << s2.GetStringLength() << endl;

    // cin >> s1;
    // cout << s1 << "==length=" << s1.GetStringLength() << endl;

    String s3("Hello world!");
    cout << s3 << "==length=" << s3.GetStringLength() << endl;
    cout << sizeof(s3) << endl;
}