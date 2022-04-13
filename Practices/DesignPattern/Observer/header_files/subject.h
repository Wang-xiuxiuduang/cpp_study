#ifndef SUBJECT_H_
#define SUBJECT_H_

#include <list>

#include "observer.h"

// 通知者基类
class Subject {
private:
    std::list<Observer*> m_observer_list;  // 存放具体的观察者

public:
    void Attach(Observer* concrete_observer) {
        m_observer_list.push_back(concrete_observer);
    }

    void notify() {
        for (Observer* concrete_object : m_observer_list) {
            concrete_object->update();
        }
    }
};

#endif