// g++ cpp-observer-2.cpp -std=c++11
#include <iostream>
#include <string>
#include <list>
#include <memory>
using namespace std;

// 觀察者抽象介面
class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void update(const std::string& msg) = 0;
};

// 主題抽象介面
class ISubject {
public:
    virtual ~ISubject() = default;
    virtual void addObserver(const std::shared_ptr<IObserver>& observer) = 0;
    virtual void removeObserver(const std::shared_ptr<IObserver>& observer) = 0;
    virtual void notify() = 0;
};

// 實作觀察者
class Observer : public IObserver {
public:
    Observer(const std::string& name) : name(name) {
    }

    void update(const std::string& msg) override {
        std::cout << "Observer " << name << " received message: " << msg << std::endl;
    }
private:
    std::string name;
};

// 實作主題
class Subject : public ISubject {
public:
    ~Subject() {};
    void addObserver(const std::shared_ptr<IObserver>& observer) override {
        observers.push_back(observer);
    }
    void removeObserver(const std::shared_ptr<IObserver>& observer) override {
        observers.remove(observer);
    }
    void notify() override {
        for (const auto& observer : observers) {
            observer->update(message);
        }
    }

    void createMessage(const std::string &msg) {
        message = msg;
        notify();
    }
private:
    std::list<std::shared_ptr<IObserver>> observers;
    std::string message;
};

int main() {
    std::shared_ptr<Observer> observerA = std::make_shared<Observer>("A");
    std::shared_ptr<IObserver> observerB = std::make_shared<Observer>("B");

    Subject subject;
    subject.addObserver(observerA);
    subject.addObserver(observerB);
    subject.addObserver(std::make_shared<Observer>("C"));

    subject.createMessage("hello world");

    return 0;
}
