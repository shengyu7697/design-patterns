// g++ cpp-template-method.cpp -std=c++11
#include <iostream>
#include <string>
using namespace std;

// 抽象父類，定義了讀取檔案的樣板方法
class DataReader {
public:
    virtual ~DataReader() = default;

    void readFile(const std::string& filename) {
        openFile(filename);
        parseData();
        closeFile();
    }

protected:
    virtual void openFile(const std::string& filename) = 0;
    virtual void parseData() = 0;
    virtual void closeFile() = 0;
};

// 具體子類，處理XML檔案
class XMLReader : public DataReader {
protected:
    void openFile(const std::string& filename) override {
        std::cout << "Opening XML file: " << filename << std::endl;
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
protected:
    void openFile(const std::string& filename) override {
        std::cout << "Opening CSV file: " << filename << std::endl;
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
protected:
    void openFile(const std::string& filename) override {
        std::cout << "Opening JSON file: " << filename << std::endl;
    }

    void parseData() override {
        std::cout << "Parsing JSON data." << std::endl;
    }

    void closeFile() override {
        std::cout << "Closing JSON file." << std::endl;
    }
};

int main() {
    DataReader* xmlReader = new XMLReader();
    xmlReader->readFile("example.xml");

    DataReader* csvReader = new CSVReader();
    csvReader->readFile("example.csv");

    DataReader* jsonReader = new JSONReader();
    jsonReader->readFile("example.json");

    delete xmlReader;
    delete csvReader;
    delete jsonReader;

    return 0;
}
