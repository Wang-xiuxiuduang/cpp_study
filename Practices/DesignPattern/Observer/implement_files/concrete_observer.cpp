#include "../header_files/concrete_observer.h"

void ConcreteObserver::update() {
    std::cout << "I'm " << getName() << "  " << getCry() << std::endl;
}