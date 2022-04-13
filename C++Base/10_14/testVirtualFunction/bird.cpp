#include "../headerFile/bird.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

Bird::Bird(float fa = 0) : Animal(), flightAltitude(fa) {
    cout << "Bird has one parameter constructor..." << endl;
}

Bird::Bird(float fa = 0, bool sex = false) : Animal(sex), flightAltitude(fa) {
    cout << "Bird has two parameter constructor..." << endl;
}

Bird::~Bird() { cout << "Bird deconstructor..." << endl; }

void Bird::eatFood() { cout << "Bird eatFood..." << endl; }

void Bird::sleep() { cout << "Bird sleep..." << endl; }

void Bird::getSex() { cout << "Bird getSex..." << endl; }

void Bird::getFA() { cout << "flightAltitude: " << flightAltitude << endl; }

void Bird::getAge(string name) { cout << "Bird getAge..." << name << endl; }
