# 靜態工廠方法
C++ 中的靜態工廠方法（Static Factory Method）是一種設計模式，用於建立物件而無需直接使用建構子。它是一個靜態方法，通常定義在類別內部，也就是一個靜態成員函數，它負責根據不同的條件或參數建立並回傳類型的實例。  

靜態工廠方法的主要優點包括：  

1. 封裝建立邏輯：建立物件的邏輯集中在工廠方法內部，而不是分散在客戶程式碼中，這使得程式碼更加整潔且易於維護。  

2. 靈活性：可以根據傳遞給工廠方法的參數來決定回傳的物件類型或設定，使得程式碼在面對變更需求時更具彈性。  

3. 避免暴露建構子：當類的建構子不想被直接呼叫時，可以使用靜態工廠方法來控制物件的建立，這在某些設計模式中非常有用，如單例模式。  

靜態工廠方法範例:  
```cpp
#include <iostream>
#include <memory>

class Product {
public:
    virtual ~Product() = default;
    virtual void use() = 0;
};

class ConcreteProductA : public Product {
public:
    void use() override {
        std::cout << "Using ConcreteProductA" << std::endl;
    }
};

class ConcreteProductB : public Product {
public:
    void use() override {
        std::cout << "Using ConcreteProductB" << std::endl;
    }
};

class ProductFactory {
public:
    static std::unique_ptr<Product> createProduct(const std::string& type) {
        if (type == "A") {
            return std::make_unique<ConcreteProductA>();
        } else if (type == "B") {
            return std::make_unique<ConcreteProductB>();
        } else {
            return nullptr;
        }
    }
};

int main() {
    auto productA = ProductFactory::createProduct("A");
    auto productB = ProductFactory::createProduct("B");

    if (productA) productA->use();
    if (productB) productB->use();

    return 0;
}
```
在這個範例中，ProductFactory 類中的靜態方法 createProduct 根據傳入的參數（如 "A" 或 "B"）來建立並回傳不同類型的 Product 物件。這樣客戶端程式碼不需要知道具體的物件是如何建立的細節，只需透過工廠方法請求所需的物件。  

## 靜態工廠方法跟工廠模式有什麼不同？
靜態工廠方法（Static Factory Method）和工廠模式（Factory Pattern）都是建立物件的設計模式，但它們有一些重要的區別。  

**靜態工廠方法**  
靜態工廠方法是一個靜態方法，通常存在於類別中，用於建立並回傳該類型的實例或其子類的實例。由於它是靜態的，不需要實例化工廠類就能夠建立物件。  

特點:  
1. 靜態方法: 不需要建立工廠類的實例即可使用。  
2. 簡單: 一般用於簡化物件的建立過程，避免直接使用建構子。  
3. 封裝邏輯: 建立邏輯封裝在靜態方法中，外部只需要呼叫該方法即可建立物件。  

使用場景:  
- 當物件建立過程中包含一些複雜的邏輯或需要根據不同的參數建立不同的實例時。使用靜態工廠方法可以很好地將這些邏輯封裝起來，減少客戶端程式碼的複雜度。例如，在需要基於參數選擇不同實現類型時，可以使用靜態工廠方法來集中管理這些選擇邏輯。  
- 當不想讓使用者直接呼叫建構子建立物件時。  

範例:  
在上個範例中提到的 ProductFactory::createProduct 就是一個靜態工廠方法。  

**工廠模式**  
工廠模式是一種更為複雜的設計模式，通常包括兩種類型：`簡單工廠模式`和`工廠方法模式`。  

簡單工廠模式（Simple Factory Pattern）: 與靜態工廠方法類似，通常使用一個類的靜態方法來建立不同類型的物件。由於很簡單，這種模式有時被認為不是真正的設計模式，而只是工廠方法的一種特殊情況。  

工廠方法模式（Factory Method Pattern）: 更加靈活和抽象。它定義了一個接口，讓子類來決定實例化哪個類。建立物件的過程被延遲到子類中處理。  

特點:
- 多態性: 工廠方法模式使用多態性，讓具體的子類來決定要建立的物件類型。
- 可擴展性: 當需要新增產品時，只需要增加新的子類和對應的工廠類，而不需要修改現有的程式碼。
- 建立與使用分離: 物件的建立過程與使用過程被解耦合，遵循開放封閉原則。

使用場景:  
- 當系統需要根據當前情況建立多種類型的物件，並且這些類型可能會在未來擴展時。
- 當建立物件的過程比較複雜或會發生變化時。

工廠模式範例:  
```cpp
class Product {
public:
    virtual ~Product() = default;
    virtual void use() = 0;
};

class ConcreteProductA : public Product {
public:
    void use() override {
        std::cout << "Using ConcreteProductA" << std::endl;
    }
};

class ConcreteProductB : public Product {
public:
    void use() override {
        std::cout << "Using ConcreteProductB" << std::endl;
    }
};

class Factory {
public:
    virtual ~Factory() = default;
    virtual Product* createProduct() = 0;
};

class ConcreteFactoryA : public Factory {
public:
    Product* createProduct() override {
        return new ConcreteProductA();
    }
};

class ConcreteFactoryB : public Factory {
public:
    Product* createProduct() override {
        return new ConcreteProductB();
    }
};
```

`靜態工廠方法`通常是工廠模式的一種簡化形式，簡單且方便，尤其在建立過程相對簡單且變化不多的情況下。  
`工廠方法模式`提供了更大的靈活性和可擴展性，適用於物件建立過程複雜且需要擴展的情況。  
兩者的區別主要在於複雜度和靈活性，靜態工廠方法偏向於簡單實現，而工廠模式則更注重可擴展性和設計上的嚴謹性。  

## 常見的靜態工廠方法範例
以下是一些在實務開發中常見使用靜態工廠方法的情況和範例，  

1. 資料庫連接管理
在需要建立資料庫連接時，通常會使用靜態工廠方法來封裝連接的建立過程，特別是在需要管理連接池或根據不同的設定建立連接時。

```cpp
class DatabaseConnection {
public:
    static DatabaseConnection* createConnection(const std::string& dbType) {
        if (dbType == "MySQL") {
            return new MySQLConnection();
        } else if (dbType == "SQLite") {
            return new SQLiteConnection();
        }
        return nullptr;
    }
    virtual ~DatabaseConnection() = default;
    virtual void connect() = 0;
};

class MySQLConnection : public DatabaseConnection {
public:
    void connect() override {
        std::cout << "Connecting to MySQL database." << std::endl;
    }
};

class SQLiteConnection : public DatabaseConnection {
public:
    void connect() override {
        std::cout << "Connecting to SQLite database." << std::endl;
    }
};
```

2. 日誌系統
記錄日誌時，可能會根據不同的日誌級別（如 INFO, DEBUG, ERROR）或不同的輸出方式（如檔案、控制台、遠端伺服器）來建立日誌物件。靜態工廠方法可以用來封裝這些建立邏輯。
```cpp
class Logger {
public:
    static Logger* createLogger(const std::string& logType) {
        if (logType == "File") {
            return new FileLogger();
        } else if (logType == "Console") {
            return new ConsoleLogger();
        }
        return nullptr;
    }
    virtual ~Logger() = default;
    virtual void log(const std::string& message) = 0;
};

class FileLogger : public Logger {
public:
    void log(const std::string& message) override {
        std::cout << "Logging to file: " << message << std::endl;
    }
};

class ConsoleLogger : public Logger {
public:
    void log(const std::string& message) override {
        std::cout << "Logging to console: " << message << std::endl;
    }
};
```

3. UI 元件的建立
在使用者介面（UI）開發中，可能需要根據不同的條件建立不同類型的 UI 元件（如按鈕、文字框、下拉選單等）。靜態工廠方法可以用來根據條件建立並回傳適當的 UI 元件。
```cpp
class Widget {
public:
    static Widget* createWidget(const std::string& widgetType) {
        if (widgetType == "Button") {
            return new Button();
        } else if (widgetType == "TextBox") {
            return new TextBox();
        }
        return nullptr;
    }
    virtual ~Widget() = default;
    virtual void draw() = 0;
};

class Button : public Widget {
public:
    void draw() override {
        std::cout << "Drawing a button." << std::endl;
    }
};

class TextBox : public Widget {
public:
    void draw() override {
        std::cout << "Drawing a text box." << std::endl;
    }
};
```

4. 通訊協定處理
在網路通訊中，根據不同的協定類型（如 HTTP、FTP、SMTP）來建立相應的處理物件，是靜態工廠方法的典型應用場景。這有助於根據設定靈活地切換不同的協定處理。
```cpp
class ProtocolHandler {
public:
    static ProtocolHandler* createHandler(const std::string& protocol) {
        if (protocol == "HTTP") {
            return new HTTPHandler();
        } else if (protocol == "FTP") {
            return new FTPHandler();
        }
        return nullptr;
    }
    virtual ~ProtocolHandler() = default;
    virtual void handleRequest() = 0;
};

class HTTPHandler : public ProtocolHandler {
public:
    void handleRequest() override {
        std::cout << "Handling HTTP request." << std::endl;
    }
};

class FTPHandler : public ProtocolHandler {
public:
    void handleRequest() override {
        std::cout << "Handling FTP request." << std::endl;
    }
};
```

## 靜態工廠方法是設計模式中的一種嗎？  
靜態工廠方法本身並不是一種獨立的設計模式，而是`工廠方法模式`（Factory Method Pattern）的一種實現變體。
