#include <iostream>
#include <vector>
using namespace std;
class TestDemo {
public:
    TestDemo(int num, char ch) : num(num), ch(ch) { std::cout << "Construct function" << endl; }
    TestDemo(const TestDemo& other) : num(other.num), ch(other.ch) {
        std::cout << "Copy construct function" << endl;
    }
    TestDemo(TestDemo&& other) : num(other.num) {
        std::cout << "Move copy construct function" << endl;
    }

private:
    int num;
    char ch;
};

int main() {
    cout << "emplace_back:" << endl;
    std::vector<TestDemo> demo1;
    // demo1.emplace_back(2, 'a');
    // demo1.emplace_back(TestDemo(20, 'a'));

    cout << "push_back:" << endl;
    std::vector<TestDemo> demo2;
    demo1.push_back(TestDemo(20, 'a'));
}
