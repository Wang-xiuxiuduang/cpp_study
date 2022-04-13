#include <iostream>

using namespace std;

namespace generic_program {
template <typename T>
void swap(T& a, T& b) {
    T c = a;
    a = b;
    b = c;
}

template <typename T>
class Test_1 {
private:
    T tt;

public:
    void set(T t) { this->tt = t; }
    T get() { return this->tt; }
};

class Test_2 {
private:
    int id;

public:
    Test_2(int id) : id(id) {}
    int getId() { return id; }
};
}  // namespace generic_program

int main() {
    int i = 10, j = 20;
    generic_program::swap(i, j);
    cout << i << " " << j << endl;
    string str_1 = "Hello";
    string str_2 = "World";
    generic_program::swap(str_1, str_2);
    // cout << str_1 << " " << str_2 << endl;
    cout << "=========== template class ===========\n";
    generic_program::Test_1<int>* test_1 = new generic_program::Test_1<int>;
    test_1->set(12);
    cout << test_1->get() << endl;
    cout << "=========== template class of my class ===========\n";
    generic_program::Test_2 test_2(100);
    cout << test_2.getId() << endl;
    // generic_program::Test_1<generic_program::Test_2> test_3(const generic_program::Test_2
    // test_4(99)); test_3.set(generic_program::Test_2 t);

    return 0;
}