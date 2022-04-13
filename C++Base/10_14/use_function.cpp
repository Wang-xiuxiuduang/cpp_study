#include <iostream>
#include <string>

#include "headerFile/animal.h"
#include "headerFile/bird.h"

using namespace std;

int main() {
    cout << "-----------Start use "
            "function---------------------------------"
         << endl;
    // cout << "+++++++++ Test Animal Class +++++++++" << endl;
    // Animal a1;
    // Animal a2(true);
    // a2.getSex();
    // a2.eatFood();
    // a2.sleep();

    // cout << "+++++++++ Test Bird Class +++++++++" << endl;
    Bird b1(100);
    Bird b2(100, true);
    // b1.getSex();
    // b1.getFA();
    // b1.eatFood();
    // b1.sleep();
    // b1.getAge(12);
    // b1.getAge("wang");

    cout << "+++++++++ Test Class Pointer +++++++++" << endl;
    Animal& a3 = *(new Bird(300));
    Animal* a4 = &b2;
    Animal& a5 = b1;
    cout << "a3" << endl;
    a3.getAge(8);
    a3.eatFood();
    cout << "a4" << endl;
    a4->getAge(9);
    a4->eatFood();
    cout << "a5" << endl;
    a5.getAge(10);
    a5.eatFood();

    cout << "===================================" << endl;
    Animal* a6 = new Bird(11);
    a6->eatFood();
    a6->getSex();

    return 0;
}
