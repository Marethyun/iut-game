#include "Remarks.h"

#include <iostream>
#include <fstream>

using namespace std;

Remarks::Remarks() {}

std::string Remarks::getRandom() {
    
    const string FILE_NAME = "REMARKS";
    
    string line;
    unsigned lineCount = 0;
    
    ifstream ifs(FILE_NAME);
    while (getline(ifs, line)) ++lineCount;
    
    ifs.clear();
    ifs.seekg(0, std::ios::beg);
    
    return "";
}
