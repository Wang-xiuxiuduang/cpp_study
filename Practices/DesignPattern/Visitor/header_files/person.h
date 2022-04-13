#ifndef PERSON_H_
#define PERSON_H_

class Person {
public:
    virtual void accept(Action& visitor) = 0;  // 第一次分派
};

#endif