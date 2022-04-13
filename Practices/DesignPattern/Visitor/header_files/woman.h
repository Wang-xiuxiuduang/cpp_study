#ifndef WOMAN_H
#define WOMAN_H

#include "action.h"
#include "person.h"

class Woman : public Person {
public:
    void accept(Action& visitor);
};

#endif