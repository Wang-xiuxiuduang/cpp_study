#include <iostream>
using namespace std;

class Person {
private:
    std::string name;

public:
    Person(std::string);
    Person();
    ~Person() { std::cout << "Person deconstruct..." << std::endl; }

    virtual void Show();
};

class Finery : public Person {
protected:
    Person* component;

public:
    Finery();
    void Decorate(Person* comp) { component = comp; }
    virtual void Show() {
        if (component != nullptr) {
            component->Show();
        }
    }
};

class TShirts : public Finery {
public:
    virtual void Show() { cout << "TShirt" << endl; }
};

class BigTrouser : public Finery {
public:
    virtual void Show() { cout << "BigTrouser" << endl; }
};

class Sneakers : public Finery {
public:
    virtual void Show() { cout << "Sneakers" << endl; }
};

int main() {
    Person person("WangXiuxiu");
    cout << "First Decorate: \n";
    TShirts tShirts;
    BigTrouser bigTrouser;
    Sneakers sneakers;
    tShirts.Show();
    sneakers.Show();
    bigTrouser.Show();
    return 0;
}