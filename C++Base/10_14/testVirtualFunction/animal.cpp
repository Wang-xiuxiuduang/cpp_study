#include "../headerFile/animal.h"

#include <iostream>

using std::cout;
using std::endl;

Animal::Animal() { cout << "Animal has'n parameter constructor..." << endl; };

Animal::Animal(bool sex) : sex(sex) { cout << "Animal has parameter constructor..." << endl; }

Animal::~Animal() { cout << "Animal Class deconstructor..." << endl; }

void Animal::eatFood() { cout << "Animal eatFood..." << endl; }

void Animal::sleep() { cout << "Animal sleep..." << endl; }

void Animal::getSex() const { cout << "Animal getSex..." << endl; }

void Animal::getAge(int age) { cout << "Animal getAge..." << age << endl; }
