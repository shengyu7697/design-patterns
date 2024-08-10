
cpp-template-method.cpp

cpp-template-method-2.cpp
在 DataReader 類中，定義了 hook1 和 hook2 作為虛函式並提供了預設實現。這是樣板方法模式中的一種變體，允許子類在需要時重寫這些鉤子函式。

子類別的建構子
如果你不使用 using 宣告，你通常會手動定義子類的構造函式，並在其中呼叫基類的構造函式。
using DataReader::DataReader; 告訴編譯器繼承 DataReader 基類中的構造函式。這樣，你不需要在子類中重覆定義構造函式：
using DataReader::DataReader; 是 C++11 引入的一種語法，用於在子類中繼承基類的構造函式。這一特性可以讓你在子類中直接使用基類的構造函式，從而簡化子類的程式碼。
