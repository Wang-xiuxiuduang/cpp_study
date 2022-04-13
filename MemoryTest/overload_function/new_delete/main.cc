#include <iostream>

using namespace std;

/**
 * 用于测试 new 与 delete 在类中的重载
 */
namespace wzz_new_delete {
class Foo {
private:
    int id;

public:
    Foo() { cout << "default construct\n"; }
    Foo(int id) { this->id = id; }
    ~Foo() { cout << "default destruct\n"; }
    // ============= overload per-class operator new/delete/new[]/delete[] =============
    static void* operator new(size_t size) {
        cout << "my operator new\n";
        Foo* p = (Foo*)malloc(size);
        return p;
    }
    // size 没有用到
    static void operator delete(void* pdead, size_t size) {
        cout << "my operator delete\n";
        free(pdead);
        return;
    }
    static void* operator new[](size_t size) {
        cout << "my operator new[]\n";
        Foo* p = (Foo*)malloc(size);
        return p;
    }
    static void operator delete[](void* pdead, size_t size) {
        cout << "my operator delete[]\n";
        free(pdead);
        return;
    }
    // ============= end overload =============
    // 获取私有变量 id
    int getId() { return id; }
};
}  // namespace wzz_new_delete

// ============= overload global operator new =============
inline void* operator new(size_t size) {
    cout << "inline operator new\n";
    wzz_new_delete::Foo* p = (wzz_new_delete::Foo*)malloc(size);
    return p;
}
inline void operator delete(void* pdead, size_t size) {
    cout << "inline operator delete\n";
    free(pdead);
    return;
}
// ============= overload end =============

int main() {
    cout << sizeof(wzz_new_delete::Foo) << endl;

    // 调用 overload_function version operator new/delete/new[]/delete[]
    wzz_new_delete::Foo* pdead01 = new wzz_new_delete::Foo();
    delete pdead01;

    // 这样调用会略过所有的 overload_function，强制使用 global version
    wzz_new_delete::Foo* pdead02 = ::new wzz_new_delete::Foo();
    ::delete pdead02;

    // 测试 placement new
    wzz_new_delete::Foo* pdead03 = new wzz_new_delete::Foo(100);
    cout << pdead03->getId() << " ===== pdead03 ===== " << pdead03 << endl;
    // 将一个新的 Foo 对象放入到 pdead03 所指向的地址空间上去
    wzz_new_delete::Foo* pdead04 = ::new (pdead03) wzz_new_delete::Foo(200);
    cout << pdead04->getId() << " ===== pdead04 ===== " << pdead04 << endl;
    cout << pdead03->getId() << " ===== pdead03 ===== " << pdead03 << endl;

    // wzz_new_delete::Foo* pdead02 = new wzz_new_delete::Foo[3];
    // for (int i = 0; i < 2; ++i) {
    //     cout << pdead02->getId() << endl;
    // }
    // delete[] pdead02;
    return 0;
}