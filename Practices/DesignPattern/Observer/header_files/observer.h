#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <iostream>
#include <string>

// 观察者基类
class Observer {
private:
    std::string m_name;
    std::string m_cry;

public:
    Observer(std::string name, std::string cry) : m_name(name), m_cry(cry) {}
    ~Observer() = default;

    virtual void update() = 0;

    std::string getName() { return m_name; }
    std::string getCry() { return m_cry; }
};

#endif