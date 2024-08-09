// g++ cpp-strategy.cpp -std=c++11
#include <iostream>
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
    Strategy* strategy_;
public:
    void setStrategy(Strategy* s) {
        strategy_ = s;
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
    StrategyA strategyA;
    StrategyB *strategyB = new StrategyB();
    Strategy *strategyC = new StrategyC();

    context.setStrategy(&strategyA);
    std::cout << "Result of Strategy A: " << context.doOperation(5, 3) << std::endl;
    
    context.setStrategy(strategyB);
    std::cout << "Result of Strategy B: " << context.doOperation(5, 3) << std::endl;

    context.setStrategy(strategyC);
    std::cout << "Result of Strategy C: " << context.doOperation(5, 3) << std::endl;

    delete strategyB;
    delete strategyC;

    return 0;
}
