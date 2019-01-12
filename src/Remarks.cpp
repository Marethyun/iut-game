#include "Remarks.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Remarks::Remarks() {}

std::string Remarks::getRandom() {
    
    srand(time(NULL));
    
    const string FILE_NAME = "REMARKS";
    
    string line;
    vector<string> remarks;
    
    ifstream ifs(FILE_NAME);
    if (ifs.fail()) {
        return "Could not load the file " + FILE_NAME;
    }
    
    while (getline(ifs, line)) remarks.push_back(line);
    
    ifs.close();
    
    if (remarks.size() == 0) return "";
    
    return remarks[rand() % remarks.size()];
}
