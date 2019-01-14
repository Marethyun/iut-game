#include "Config.h"

#include <iostream>
#include <fstream>

using namespace std;

Config* Config::singleton = nullptr;

Config::Config()
{
    const string FILE_NAME = "game.properties";
    
    ifstream ifs(FILE_NAME);
    if (ifs.fail()) return;
    
    string line;
    
    while (getline(ifs, line)) {
        // A property must have at least a 1-char key and an = (2 chars)
        if (line.size() < 2) continue;
        
        unsigned long equalIndex = line.find('=');
        
        if (equalIndex == string::npos) continue;
        
        string key = line.substr(0, equalIndex);
        
        if (key.size() == 0) continue;
        
        string value = key.size() + 1 < line.size() ? line.substr(equalIndex + 1, string::npos) : "";
        
        this->properties.insert(pair<string, string>(key, value));        
    }
}

Config* Config::get() {
    if (!singleton) singleton = new Config();
    
    return singleton;
}

char Config::keyUp() {
    return getOrDefault("key_up", "z").substr(0, 1)[0];
}

char Config::keyLeft() {
    return getOrDefault("key_left", "q").substr(0, 1)[0];
}

char Config::keyDown() {
    return getOrDefault("key_down", "s").substr(0, 1)[0];
}

char Config::keyRight() {
    return getOrDefault("key_right", "d").substr(0, 1)[0];
}

char Config::keyGiveUp() {
    return getOrDefault("key_giveup", "g").substr(0, 1)[0];
}

std::string Config::getOrDefault(const std::string &key, const std::string &def) {
    return this->properties.find(key) != this->properties.end() && this->properties[key].size() > 0 ? this->properties[key] : def;
}
