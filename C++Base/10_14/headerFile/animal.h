#ifndef ANIMAL_H
#define ANIMAL_H

using std::cout;
using std::endl;

/**
 * 动物类，作为基类
 */
class Animal {
private:
    bool sex;  // 动物雌雄

public:
    // constructors
    Animal();
    Animal(bool);
    // deconstructor
    ~Animal();
    // other functions
    virtual void eatFood();
    virtual void sleep();
    void getSex() const;
    void getAge(int);
};

#endif