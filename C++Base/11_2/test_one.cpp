#include <iostream>

class HeadMaster {
private:
    static HeadMaster* m_head_master;
    HeadMaster() = default;
    HeadMaster(const HeadMaster& other);
    HeadMaster& operator=(const HeadMaster& other);

public:
    static HeadMaster* GetInstance();
};

HeadMaster* HeadMaster::GetInstance() {
    if (m_head_master == nullptr) {
        m_head_master = new HeadMaster();
    }
    return m_head_master;
}

class Test {
private:
    HeadMaster* m_head_master;

public:
    Test(HeadMaster* head_master) : m_head_master(head_master) {
        std::cout << "This is test \n";
    }
};

HeadMaster* HeadMaster::m_head_master = nullptr;

int main() {
    Test* test = new Test(HeadMaster::GetInstance());
    HeadMaster* h = HeadMaster::GetInstance();
}