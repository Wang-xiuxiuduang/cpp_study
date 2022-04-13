#include <iostream>
#include <string>

/**
 * 基类 —— 人
 */
class Player {
private:
    std::string name;

public:
    Player(std::string name) { this->name = name; }
    Player() = default;
    ~Player() = default;
    void attack() { std::cout << name << " attack \n"; }
    void defense() { std::cout << name << " defense \n"; }
};

/**
 * 外国人
 */
class ForeignPlayer {
private:
    std::string name;

public:
    ForeignPlayer(std::string name) { this->name = name; }
    ~ForeignPlayer() = default;
    void attack_2() { std::cout << name << " attack \n"; }
    void defense_2() { std::cout << name << " defense \n"; }
};

class Adapter : public Player {
private:
    ForeignPlayer* foreignPlayer;

public:
    Adapter(std::string name) { foreignPlayer = new ForeignPlayer("Miss Yao"); }
    void attack() { foreignPlayer->attack_2(); }
    void defense() { foreignPlayer->defense_2(); }
};

int main() {
    Player player_1("player_1");
    player_1.attack();
    Adapter* player_2 = new Adapter("Miss Yao");
    player_2->attack();
    player_2->defense();
}
