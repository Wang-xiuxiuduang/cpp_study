#ifndef MAN_H_
#define MAN_H_

#include "action.h"
#include "person.h"

class Man : public Person {
public:
    void accept(Action& visitor);
};

#endif