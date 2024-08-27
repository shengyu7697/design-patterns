// g++ cpp-decorator-2.cpp -std=c++11
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Coffee {
public:
    virtual std::string getDescription() const {
        return "Coffee";
    }
    virtual int cost() const {
        return 50;
    }
    virtual ~Coffee() = default;
};

class MilkDecorator : public Coffee {
private:
    std::shared_ptr<Coffee> coffee;
public:
    MilkDecorator(const std::shared_ptr<Coffee>& c) : coffee(c) {}

    std::string getDescription() const override {
        return coffee->getDescription() + ", Milk";
    }

    int cost() const override {
        return coffee->cost() + 15;
    }
};

class SugarDecorator : public Coffee {
private:
    std::shared_ptr<Coffee> coffee;
public:
    SugarDecorator(const std::shared_ptr<Coffee>& c) : coffee(c) {}

    std::string getDescription() const override {
        return coffee->getDescription() + ", Sugar";
    }

    int cost() const override {
        return coffee->cost() + 5;
    }
};

int main() {
    std::shared_ptr<Coffee> myCoffee = std::make_shared<Coffee>();
    std::shared_ptr<Coffee> myMilkCoffee = std::make_shared<MilkDecorator>(myCoffee);
    std::shared_ptr<Coffee> mySugarMilkCoffee = std::make_shared<SugarDecorator>(myMilkCoffee);

    std::cout << myCoffee->getDescription() << std::endl;
    std::cout << "$" << myCoffee->cost() << std::endl;

    std::cout << mySugarMilkCoffee->getDescription() << std::endl;
    std::cout << "$" << mySugarMilkCoffee->cost() << std::endl;

    return 0;
}
