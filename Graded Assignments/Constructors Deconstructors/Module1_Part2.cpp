#include<iostream>
#include<string>

class SaveFile{
private:
    std::string fileName;
    std::string fileType;
    int fileSize;

public:
    SaveFile() : fileName("default_file"), fileType("default_type"), fileSize(0){
        std::cout << "Default file " << fileName << " was saved, with type " << fileType << " and with size " << fileSize << '\n';
    }

    SaveFile(std::string name, std::string type, int size) : fileName(name), fileType(type), fileSize(size){
        std::cout << "File " << fileName << " was saved, with type " << fileType << " and with size " << fileSize << '\n';
    }

    ~SaveFile(){
        std::cout << "File was removed";
    }
};