#include <iostream>
#include <string>
#include "binary.h"

class Container
{
    char * aPointer;
    int aNumber;
    std::string aString;
public:
    Container(std::string astring = "", int anumber = 0) : aNumber(anumber), aString(astring){};
    void printMe(){std::cout << "String: " << aString << ", number: " << aNumber << "\n"; }
    void saveMe(std::string path)
    {
        std::fstream file(path, std::ios::binary | std::ios::out);
        writeBinary<int>(file, aNumber);
        writeBinary<std::string>(file, aString);
        file.close();
    }
    void loadMe(std::string path)
    {
        std::fstream file(path, std::ios::binary | std::ios::in);
        readBinary<int>(file, aNumber);
        readBinary<std::string>(file, aString);
        file.close();
    }
};
