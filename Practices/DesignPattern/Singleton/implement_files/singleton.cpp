#include "../headerFiles/singleton.h"

#include <iostream>

Singleton* Singleton::GetInstance1() {
    if (instance == nullptr) {
        instance = new Singleton();
    }
    return instance;
}

Singleton* Singleton::GetInstance2() {
    static Singleton* ins = new Singleton();
    return ins;
}
Singleton* Singleton::instance = nullptr;  // 静态成员需要先初始化
