#include <iostream>
#include <string>

// 送礼接口
class ISendGift {
public:
    virtual void sendFlower() = 0;
    virtual void sendChocolates() = 0;
};

// 被追求者
class GirlGod {
private:
    std::string name;

public:
    void setName(std::string name) { this->name = name; }
    std::string getName() { return name; }
};

// 追求者类 Real Subject
class Pursuit : public ISendGift {
private:
    GirlGod* girl;

public:
    Pursuit(GirlGod* girl) { this->girl = girl; }
    void sendFlower() override;
    void sendChocolates() override;
};

void Pursuit::sendFlower() {
    std::cout << "send flower to " << girl->getName() << std::endl;
}

void Pursuit::sendChocolates() {
    std::cout << "send chocolates to " << girl->getName() << std::endl;
}

// 代理类 Proxy
class Proxy : public ISendGift {
private:
    Pursuit* pursuit;

public:
    Proxy(GirlGod* girl) { pursuit = new Pursuit(girl); }
    void sendFlower() override;
    void sendChocolates() override;
};

void Proxy::sendFlower() { pursuit->sendFlower(); }

void Proxy::sendChocolates() { pursuit->sendChocolates(); }

// 客户端
int main() {
    GirlGod* girl = new GirlGod();
    girl->setName("Miss Wang");

    Proxy* proxy = new Proxy(girl);

    proxy->sendFlower();
    proxy->sendChocolates();

    return 0;
}
