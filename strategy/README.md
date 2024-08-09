
class Strategy 為 抽象介面，不能直接實例化，需要繼承以及實作對應的介面，
實作的策略子類別有：加法策略、減法策略、乘法策略

class Context 為上下文類別
基本寫法，override 關鍵字需要 C++11
cpp-strategy.cpp

特別注意，虛擬解構子的部分，以免子類別沒有正常釋放記憶體造成記憶體洩漏問題。
virtual ~Strategy() = default;

加上智慧指標 unique_ptr 的寫法，std::make_unique 需要 C++14 
cpp-strategy-2.cpp
