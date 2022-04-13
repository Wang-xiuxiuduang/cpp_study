#include <iostream>

#include "header_files/concrete_observer.h"
#include "header_files/observer.h"
#include "header_files/subject.h"

int main() {
    Subject* tiger = new Subject();
    tiger->Attach(new ConcreteObserver("sheep", "miemiemie~"));
    tiger->Attach(new ConcreteObserver("dog", "wangwangwang~"));
    tiger->Attach(new ConcreteObserver("cat", "miaomiaomiao~"));
    tiger->notify();
}