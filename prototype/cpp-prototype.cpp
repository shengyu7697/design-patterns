// g++ cpp-prototype.cpp -std=c++14
#include <iostream>
#include <string>
#include <memory>

// 定義一個抽象基類，包含一個clone()方法
class Prototype {
public:
    virtual ~Prototype() = default;
    virtual std::unique_ptr<Prototype> clone() const = 0;
    virtual void printDetails() const = 0;
};

// 一個具體的類，實現了Prototype
class ConcretePrototype : public Prototype {
private:
    std::string name;
    int value;
public:
    ConcretePrototype(std::string name, int value) : name(name), value(value) {}
    
    // 實現clone方法，回傳自己的拷貝
    std::unique_ptr<Prototype> clone() const override {
        return std::make_unique<ConcretePrototype>(*this);
    }

    void printDetails() const override {
        std::cout << "Name: " << name << ", Value: " << value << std::endl;
    }
};

int main() {
    // 建立一個原型物件
    std::unique_ptr<Prototype> prototype = std::make_unique<ConcretePrototype>("Original", 123);

    // 使用原型建立一個新物件
    std::unique_ptr<Prototype> clone = prototype->clone();

    // 打印原型和拷貝的細節
    prototype->printDetails();
    clone->printDetails();

    return 0;
}
