# 裝飾者模式
裝飾模式（Decorator Pattern）是一種結構型設計模式，用來動態地為物件新增新功能，而不改變其結構。透過將物件包裝在一個裝飾器類中，裝飾器類可以在不改變原有物件介面的前提下，增強物件的功能或改變其行為。  

核心概念：  
1. 組件介面（Component Interface）： 定義了物件的基本行為，所有被裝飾的物件和裝飾器類都實現這個介面。  
2. 具體組件（Concrete Component）： 被裝飾的物件，提供裝飾器所需的基本功能。  
3. 裝飾器類（Decorator）： 持有一個組件介面的引用，並且實現該介面，可以透過呼叫組件物件的方法來擴展或修改其行為。  
4. 具體裝飾器（Concrete Decorators）： 實現了裝飾器類的擴展功能，可以在呼叫原有組件功能前後增加額外的行為。  

使用場景：  
- 需要為物件新增功能，但不希望透過繼承來實現。  
- 希望動態地為物件新增功能，且功能可以被撤銷。  
- 需要對多個物件進行功能擴展，但希望避免為每個物件都建立一個子類。  

範例：  
假設有一個基本的咖啡類（Concrete Component），我們可以透過不同的裝飾器（如牛奶、糖）來動態地增加不同的配料，而不影響咖啡類本身。  

範例  

在這個範例中，MilkDecorator 和 SugarDecorator 都是裝飾器，它們分別向咖啡物件中新增了牛奶和糖的功能，而不改變咖啡類的本質。  

## 範例1. 基本的裝飾者模式
  
```cpp cpp-decorator.cpp
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
        return coffee->cost() + 15;
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
```

執行結果，  
```
Coffee
$50
Coffee, Milk, Sugar
$70
```

## 範例2. 進階的裝飾者模式(智慧指標)

```cpp cpp-decorator-2.cpp
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
```

執行結果，  
```
Coffee
$50
Coffee, Milk, Sugar
$70
```
