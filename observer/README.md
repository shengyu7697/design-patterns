# 觀察者模式
觀察者模式在 C++ 程式碼中很常見， 特別是在 GUI 開發中，因為它允許對不同的事件做出反應，而不需要與觸發事件的對象直接耦合。  

例如：按鈕點擊事件，當使用者點擊按鈕時，按鈕對象會通知所有註冊的觀察者（通常是事件處理函數或回呼函數）來處理這個事件。這使得按鈕本身不需要知道將如何處理點擊，只需要通知所有註冊的觀察者。  

在 Qt 或 MFC 中，按鈕通常會觸發一個 clicked 訊號，這個訊號可以被多個槽函數（觀察者）連接和處理。  

使用觀察者模式同時保持程式碼的模組化和解耦。  

## 範例1. 基本的觀察者模式
cpp-observer.cpp  
定義一個觀察者抽象類別 IObserver class，然後實作一個觀察者類別 Observer class  
定義一個主題類別 Subject class  

執行結果，  
```
Observer A received message: hello world
Observer B received message: hello world
Observer C received message: hello world
```

## 範例2. 進階的觀察者模式
cpp-observer-2.cpp  
定義一個觀察者抽象類別 IObserver class，然後實作一個觀察者類別 Observer class  
考慮到有很多主題，所以也設計一個主題抽象類別 ISubject class，那麼就可以實作多種主題 Subject class 

再加上 shared_ptr  

執行結果，  
```
Observer A received message: hello world
Observer B received message: hello world
Observer C received message: hello world
```
