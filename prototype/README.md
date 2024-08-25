# 原型模式
原型模式（Prototype Pattern）是一種建立型設計模式，它允許透過複製已有的實例來建立新物件，而不是直接透過構造函式來建立。這對於需要產生相似物件並希望避免高成本的初始化過程時非常有用。原型模式的核心思想是使用已有物件作為藍本，透過複製這個物件來產生新的實例。

以下是使用原型模式的 C++ 範例：
## 範例1. 基本的原型模式
cpp-prototype.cpp  

Prototype基類：定義了clone()方法，所有具體的原型類都需要實現這個方法，用來產生自身的複製品。  
ConcretePrototype具體類：實現了clone()方法，該方法回傳該類型的一個拷貝（透過呼叫拷貝構造函式）。  
在 main 函式中展示了如何使用原型模式來產生物件的複製品，從而避免直接透過構造函式建立物件。  
這個範例展示了如何使用原型模式在C++中實現物件的複製，使得可以輕鬆建立相似的物件，而不需要關心它們的初始化細節。  
```cpp
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
```

執行結果，  
```
Name: Original, Value: 123
Name: Original, Value: 123
```

## 範例2. 進階的原型模式
cpp-prototype-2.cpp  

執行結果，  
```

```
