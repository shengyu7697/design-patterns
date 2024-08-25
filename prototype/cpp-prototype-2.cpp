// g++ cpp-prototype.cpp -std=c++14
#include <iostream>
#include <memory>
#include <string>

// 定義一個抽象基類，包含clone()方法
class Enemy {
public:
    virtual ~Enemy() = default;
    virtual std::unique_ptr<Enemy> clone() const = 0;
    virtual void attack() const = 0;
    virtual void setAttributes(std::string newType, int newHealth, int newAttackPower) = 0;
};

// 具體的敵人類(哥布林)
class Goblin : public Enemy {
private:
    std::string type;
    int health;
    int attackPower;
public:
    Goblin(std::string type, int health, int attackPower)
        : type(type), health(health), attackPower(attackPower) {}

    std::unique_ptr<Enemy> clone() const override {
        return std::make_unique<Goblin>(*this);
    }

    void attack() const override {
        std::cout << type << " attacks with power " << attackPower << " and has " << health << " health!\n";
    }

    void setAttributes(std::string newType, int newHealth, int newAttackPower) override {
        type = newType;
        health = newHealth;
        attackPower = newAttackPower;
    }
};

int main() {
    std::unique_ptr<Enemy> baseGoblin = std::make_unique<Goblin>("Goblin", 100, 15);

    // 複製多個Goblin並改變屬性
    std::unique_ptr<Enemy> strongerGoblin = baseGoblin->clone();
    strongerGoblin->setAttributes("Stronger Goblin", 150, 25);
    
    std::unique_ptr<Enemy> bossGoblin = baseGoblin->clone();
    bossGoblin->setAttributes("Boss Goblin", 300, 50);

    baseGoblin->attack();
    strongerGoblin->attack();
    bossGoblin->attack();

    return 0;
}
