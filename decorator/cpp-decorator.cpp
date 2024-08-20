// g++ cpp-decorator.cpp -std=c++11
#include <iostream>
#include <string>
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
    Coffee* coffee;
public:
    MilkDecorator(Coffee* c) : coffee(c) {}

    std::string getDescription() const override {
        return coffee->getDescription() + ", Milk";
    }

    int cost() const override {
        return coffee->cost() + 20;
    }
};

class SugarDecorator : public Coffee {
private:
    Coffee* coffee;
public:
    SugarDecorator(Coffee* c) : coffee(c) {}

    std::string getDescription() const override {
        return coffee->getDescription() + ", Sugar";
    }

    int cost() const override {
        return coffee->cost() + 5;
    }
};

int main() {
    Coffee* myCoffee = new Coffee();
    Coffee* myMilkCoffee = new MilkDecorator(myCoffee);
    Coffee* mySugarMilkCoffee = new SugarDecorator(myMilkCoffee);

    std::cout << myCoffee->getDescription() << std::endl;
    std::cout << "$" << myCoffee->cost() << std::endl;

    std::cout << mySugarMilkCoffee->getDescription() << std::endl;
    std::cout << "$" << mySugarMilkCoffee->cost() << std::endl;

    delete myCoffee;
    delete myMilkCoffee;
    delete mySugarMilkCoffee;

    return 0;
}
