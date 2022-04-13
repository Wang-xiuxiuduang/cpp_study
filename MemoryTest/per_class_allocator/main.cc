#include <iostream>

using namespace std;

class Screen {
public:
    Screen(int x) : id(x){};
    int get() { return id; }
    void* operator new(size_t);
    void operator delete(void*, size_t);

private:
    Screen* next;
    static Screen* free_store;
    static const int screen_chunk;

private:
    int id;
};
Screen* Screen::free_store = nullptr;
const int Screen::screen_chunk = 24;

void* Screen::operator new(size_t size) {
    Screen* p;
    if (!free_store) {
        // linked list 是空的，所以攫取一大塊 memory
        // 以下呼叫的是 global operator new
        size_t chunk = screen_chunk * size;
        free_store = p = reinterpret_cast<Screen*>(new char[chunk]);
        // 將分配得來的一大塊 memory 當做 linked list 般小塊小塊串接起來
        for (; p != &free_store[screen_chunk - 1]; ++p) p->next = p + 1;
        p->next = 0;
    }
    p = free_store;
    free_store = free_store->next;
    return p;
}

// void* Screen::operator new(size_t size) {
//     Screen* p;
//     if (!free_store) {
//         // linked list 为空，申请一大块内存出来
//         size_t chunk = screen_chunk * size;
//         free_store = p = reinterpret_cast<Screen*>(new char[chunk]);
//         // 将一大块分割成片片，当做 linked list 串接起来
//         for (; p != &free_store[screen_chunk - 1]; ++p) {
//             p->next = p + 1;
//         }
//         p->next = NULL;
//     }
//     p = free_store;
//     free_store = free_store->next;
//     return p;
// }

void Screen::operator delete(void* p, size_t) {
    // 将 delete object 插回 free list 前端
    static_cast<Screen*>(p)->next = free_store;
    free_store = static_cast<Screen*>(p);
}

int main() {
    cout << sizeof(Screen) << endl;
    size_t const N = 100;
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