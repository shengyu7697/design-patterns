# 策略模式
策略模式是一種行為設計模式，它允許在執行時選擇演算法的行為。這種模式特別適用於實現一系列相關但不同的演算法，並使這些演算法可以互相替換。  
讓我們用壓縮器的例子來實現策略模式，而這個壓縮器可以抽換成Zip、Rar、7z等壓縮策略：  
```cpp
#include <iostream>
#include <string>
#include <memory>

// 抽象策略類
class CompressionStrategy {
public:
    virtual ~CompressionStrategy() = default;
    virtual void compress(const std::string& file) = 0;
};

// 具體策略類: ZIP壓縮
class ZipCompression : public CompressionStrategy {
public:
    void compress(const std::string& file) override {
        std::cout << "Use ZIP to compress file: " << file << std::endl;
    }
};

// 具體策略類: RAR壓縮
class RarCompression : public CompressionStrategy {
public:
    void compress(const std::string& file) override {
        std::cout << "Use RAR to compress file: " << file << std::endl;
    }
};

// 具體策略類: 7z壓縮
class SevenZipCompression : public CompressionStrategy {
public:
    void compress(const std::string& file) override {
        std::cout << "Use 7z to compress file: " << file << std::endl;
    }
};

class Compressor {
private:
    std::unique_ptr<CompressionStrategy> strategy;

public:
    void setStrategy(std::unique_ptr<CompressionStrategy> newStrategy) {
        strategy = std::move(newStrategy);
    }

    void compress(const std::string& file) {
        if (strategy) {
            strategy->compress(file);
        } else {
            std::cout << "未設定壓縮策略" << std::endl;
        }
    }
};

int main() {
    Compressor compressor;
    
    compressor.setStrategy(std::make_unique<ZipCompression>());
    compressor.compress("file1.txt");
    
    compressor.setStrategy(std::make_unique<RarCompression>());
    compressor.compress("file2.txt");
    
    compressor.setStrategy(std::make_unique<SevenZipCompression>());
    compressor.compress("file3.txt");

    return 0;
}
```

這個例子展示了策略模式的核心概念：  
- 抽象策略（CompressionStrategy）：定義了所有支持的演算法的公共接口。  
- 具體策略（ZipCompression， RarCompression， SevenZipCompression）：實現了具體的演算法。  
- 上下文（Compressor）：維護一個對Strategy物件的引用，並使用該物件執行所需的演算法。  
- 客戶端：建立一個特定的策略物件並傳遞給上下文。  

使用策略模式的好處：  
- 可以在執行時切換演算法（壓縮方法）。  
- 將演算法的實現與使用演算法的程式碼分離。  
- 符合開放封閉原則，可以輕鬆新增新的壓縮演算法而無需修改現有程式碼。  

這個模式非常適合處理需要動態選擇不同演算法或行為的場景，如壓縮、排序或支付方式等。  

## 範例1. 建立策略抽象介面
cpp-strategy.cpp  
class Strategy 為抽象介面，不能直接實例化，需要繼承以及實作對應的介面，
實作的策略子類別有：加法策略、減法策略、乘法策略

class Context 為上下文類別
基本寫法，override 關鍵字需要 C++11

特別注意，虛擬解構子的部分，以免子類別沒有正常釋放記憶體造成記憶體洩漏問題。
virtual ~Strategy() = default;

執行結果，  
```
Result of Strategy A: 8
Result of Strategy B: 2
Result of Strategy C: 15
```
## 範例2. 加上智慧指標的寫法
cpp-strategy-2.cpp  
加上智慧指標 unique_ptr 的寫法，std::make_unique 需要 C++14  

執行結果，  
```
Result of Strategy A: 8
Result of Strategy B: 2
Result of Strategy C: 15
```
## 範例3. 使用 lambda 函式實現策略模式
cpp-strategy-3.cpp  
策略模式在絕大部分現代程式語言中可以簡單地使用匿名 lambda 函式來實現。
