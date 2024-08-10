// g++ cpp-template-method-2.cpp -std=c++14
#include <iostream>
#include <string>
#include <memory>
using namespace std;

// 抽象父類，定義了讀取檔案的樣板方法
class DataReader {
public:
    DataReader(const std::string& filename) : filename_(filename) {}
    virtual ~DataReader() = default;

    void readFile() {
        hook1();
        openFile();
        parseData();
        closeFile();
        hook2();
    }

protected:
    virtual void hook1() {} ;
    virtual void openFile() = 0;
    virtual void parseData() = 0;
    virtual void closeFile() = 0;
    virtual void hook2() {} ;

    std::string filename_;
};

// 具體子類，處理XML檔案
class XMLReader : public DataReader {
public:
    XMLReader(const std::string& filename) : DataReader(filename) {}
protected:
    void openFile() override {
        std::cout << "Opening XML file: " << filename_ << std::endl;
    }

    void parseData() override {
        std::cout << "Parsing XML data." << std::endl;
    }

    void closeFile() override {
        std::cout << "Closing XML file." << std::endl;
    }
};

// 具體子類，處理CSV檔案
class CSVReader : public DataReader {
public:
    using DataReader::DataReader; // 繼承父類的構造函式
protected:
    void openFile() override {
        std::cout << "Opening CSV file: " << filename_ << std::endl;
    }

    void parseData() override {
        std::cout << "Parsing CSV data." << std::endl;
    }

    void closeFile() override {
        std::cout << "Closing CSV file." << std::endl;
    }
};

// 具體子類，處理JSON檔案
class JSONReader : public DataReader {
public:
    using DataReader::DataReader; // 繼承父類的構造函式
protected:
    void openFile() override {
        std::cout << "Opening JSON file: " << filename_ << std::endl;
    }

    void parseData() override {
        std::cout << "Parsing JSON data." << std::endl;
    }

    void closeFile() override {
        std::cout << "Closing JSON file." << std::endl;
    }
};

void ClientCode(std::unique_ptr<DataReader> reader) {
  // ...
  reader->readFile();
  // ...
}

int main() {
    std::unique_ptr<XMLReader> xmlReader = make_unique<XMLReader>("example.xml");
    ClientCode(std::move(xmlReader));

    std::unique_ptr<DataReader> csvReader = make_unique<CSVReader>("example.csv");
    ClientCode(std::move(csvReader));

    ClientCode(make_unique<JSONReader>("example.json"));

    return 0;
}
