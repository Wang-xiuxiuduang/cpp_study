#include "../header_files/department.h"

void Department::Display() {
    std::cout << "-----" << this->GetConcreteCompanyName() << std::endl;
}

Department::Department(std::string department_name)
    : Company(department_name) {}