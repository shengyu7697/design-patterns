

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
