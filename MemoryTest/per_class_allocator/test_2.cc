#include <cstddef>
#include <iostream>

#pragma pack(4)

using namespace std;

class Screen {
public:
    Screen(int x) : i(x){};
    int get() { return i; }
    // 其实这里最规范的写法应该添加 static 关键字！！
    // 虽然不添加系统也会默认将其看成 static 函数去调用！！
    static void* operator new(size_t size);
    static void operator delete(void* p, size_t size);

private:
    int i;

private:
    Screen* next;              // 创建一个自身类型的指针对象
    static Screen* freeStore;  // 静态变量必须类内声明，类外定义赋初值
    static const int screenChunk;
};
Screen* Screen::freeStore = 0;  // 静态变量必须类内声明，类外定义赋初值
const int Screen::screenChunk = 24;

void* Screen::operator new(size_t size) {
    Screen* p;
    if (!freeStore) {
        // linked list是空的，则申请一大块内存空间
        size_t chunk = screenChunk * size;
        freeStore = p = reinterpret_cast<Screen*>(new char[chunk]);
        // 将new出来的一大块内存块分割片片，当作linked list串接起来
        for (; p != &freeStore[screenChunk - 1]; ++p) p->next = p + 1;
        p->next = 0;
    }
    p = freeStore;
    freeStore = freeStore->next;
    return p;
}
void Screen::operator delete(void* p, size_t) {
    // 将所需删掉的object在整个linked list中的位置调整为后面空白表free
    // list【即未使用链表】的最前端
    (static_cast<Screen*>(p))->next = freeStore;
    freeStore = static_cast<Screen*>(p);
}

class Test {
private:
    int id;
    double height;
};

struct Test_2 {
    char height;
    double id;
    char weight;
};

int main() {
    cout << sizeof(Test) << endl;
    cout << sizeof(Test_2) << endl;
    cout << sizeof(Screen) << endl;
    size_t const N = 10;
    Screen* p[N];
    for (int i = 0; i < N; ++i) {
        p[i] = new Screen(i);
    }
    // 输出前 10 个 pointers，比较其间隔
    for (int i = 0; i < 10; ++i) {
        cout << p[i] << endl;
    }
    for (int i = 0; i < 10; ++i) {
        delete p[i];
    }
}
