#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <iostream>
#include <string>

/**
 * 单例模式测试类
 */
class Singleton {
private:
    static Singleton* instance;
    Singleton() { std::cout << "Singleton constructor..." << std::endl; };
    // 不允许存在拷贝构造函数
    Singleton(const Singleton& other);
    // 不允许存在 = Clone接口
    Singleton& operator=(const Singleton& other);

public:
    ~Singleton() { std::cout << "Singleton deconstructor..." << std::endl; }
    // thread unsafe
    static Singleton* GetInstance1();
    // 局部静态变量只会初始化一次，并且是线程安全的
    static Singleton* GetInstance2();
};

#endif