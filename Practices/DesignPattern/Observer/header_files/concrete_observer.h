#ifndef CONCRETE_OBSERVER_H_
#define CONCRETE_OBSERVER_H_

#include "observer.h"

class ConcreteObserver : public Observer {
public:
    ConcreteObserver(std::string name, std::string cry) : Observer(name, cry) {}
    void update() override;
};

#endif