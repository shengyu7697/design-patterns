// g++ cpp-strategy-2.cpp -std=c++14
#include <iostream>
#include <memory>
using namespace std;

// 策略抽象介面
class Strategy {
public:
    virtual ~Strategy() = default;
    virtual int execute(int a, int b) const = 0;
};

// 策略A
class StrategyA : public Strategy {
public:
    int execute(int a, int b) const override {
        return a + b;
    }
};

// 策略B
class StrategyB : public Strategy {
public:
    int execute(int a, int b) const override {
        return a - b;
    }
};

// 策略C
class StrategyC : public Strategy {
public:
    int execute(int a, int b) const override {
        return a * b;
    }
};

// 上下文類別
class Context {
private:
    std::unique_ptr<Strategy> strategy_;
public:
    void setStrategy(std::unique_ptr<Strategy> &&s) {
        strategy_ = std::move(s);
    }
    
    int doOperation(int a, int b) {
        if (strategy_)
            return strategy_->execute(a, b);
        else
            return 0;
    }
};

int main() {
    Context context;
    std::unique_ptr<StrategyA> strategyA = std::make_unique<StrategyA>();
    std::unique_ptr<Strategy> strategyB = std::make_unique<StrategyB>();

    context.setStrategy(std::move(strategyA));
    std::cout << "Result of Strategy A: " << context.doOperation(5, 3) << std::endl;
    
    context.setStrategy(std::move(strategyB));
    std::cout << "Result of Strategy B: " << context.doOperation(5, 3) << std::endl;

    context.setStrategy(std::make_unique<StrategyC>());
    std::cout << "Result of Strategy C: " << context.doOperation(5, 3) << std::endl;

    return 0;
}
