#ifndef TEST_10_12_H
#define TEST_10_12_H
#include <string>

class Student {
private:
    std::string name;
    int age;
    bool sex;

public:
    Student();  // default constructor
    Student(std::string name, int age, bool sex);
    ~Student();
    void getMsg();
};

#endif
