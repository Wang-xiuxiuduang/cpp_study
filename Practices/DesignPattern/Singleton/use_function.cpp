#include "headerFiles/singleton.h"

int main() {
    Singleton* instance_1 = Singleton::GetInstance2();
    Singleton* instance_2 = Singleton::GetInstance2();
    Singleton* instance_3 = Singleton::GetInstance2();
    Singleton* instance_4 = Singleton::GetInstance2();
    Singleton* instance_5 = Singleton::GetInstance2();
    delete instance_1;
    return 0;
}
