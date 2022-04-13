#include "../header_files/company.h"

std::string Company::GetConcreteCompanyName() { return company_name_; }

Company::Company(std::string company_name) { company_name_ = company_name; }

bool Company::operator==(Company* p_company) {
    return this->GetConcreteCompanyName() ==
           p_company->GetConcreteCompanyName();
}