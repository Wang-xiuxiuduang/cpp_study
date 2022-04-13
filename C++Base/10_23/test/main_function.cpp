#include <iostream>

#include "../header_files/animal.h"
#include "../header_files/bird.h"
#include "../header_files/dog.h"
#include "../header_files/person.h"

using namespace std;

int main() {
    cout << "=========Test Start=========" << endl;
    Animal* animal = new Person();
    cout << "animal = " << animal << endl;
    animal->cry();
    animal->hello();
    cout << endl;

    Bird* bird = new Bird();
    cout << "bird = " << bird << endl;
    bird->cry();
    cout << endl;

    Person* person = new Person();
    cout << "person = " << person << endl;
    person->cry();
    cout << endl;

    animal = bird;
    cout << "animal = " << animal << endl;
    animal->cry();
    cout << endl;

    delete bird;
    delete person;

    cout << "animal = " << animal << endl;
    // animal->cry();  // 会出现错误，因为 animal 所指向的地址已经被释放了
    cout << endl;

    cout << "=========Test End=========" << endl;

    return 0;
}
