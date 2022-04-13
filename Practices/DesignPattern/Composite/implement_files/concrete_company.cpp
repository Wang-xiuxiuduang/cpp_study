#include "../header_files/concrete_company.h"

void ConcreteCompany::Display() {
    std::cout << "--" << this->GetConcreteCompanyName() << std::endl;
    for (Company* concrete_company : department_list_) {
        concrete_company->Display();
    }
}

void ConcreteCompany::Add(Company* concrete_department) {
    department_list_.push_back(concrete_department);
}

// void ConcreteCompany::Remove(Company* concrete_department) {
//     auto ite = find(department_list_.begin(), department_list_.end(),
//                     concrete_department);
//     if (ite != department_list_.end()) {
//         department_list_.erase(ite);
//         std::cout << "find it and delete it\n";
//     } else {
//         std::cout << "can't find...\n";
//     }
// }

ConcreteCompany::ConcreteCompany(std::string company_name)
    : Company(company_name) {}