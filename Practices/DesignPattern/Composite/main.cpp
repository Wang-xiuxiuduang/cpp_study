#include "header_files/company.h"
#include "header_files/concrete_company.h"
#include "header_files/department.h"

int main() {
    ConcreteCompany* root = new ConcreteCompany("beijing headquarters");
    root->Add(new Department("beijing hr deparment"));
    root->Add(new Department("beijing finance deparment"));

    ConcreteCompany* company_shanghai =
        new ConcreteCompany("shanghai headquarters");
    company_shanghai->Add(new Department("shanghai hr deparment"));
    company_shanghai->Add(new Department("shanghai finance deparment"));
    root->Add(company_shanghai);

    ConcreteCompany* company_guangdong =
        new ConcreteCompany("guangdong headquarters");
    company_guangdong->Add(new Department("guangdong hr deparment"));
    company_guangdong->Add(new Department("guangdong finance deparment"));
    root->Add(company_guangdong);

    root->Display();

    return 0;
}