#ifndef CONFIG_H
#define CONFIG_H

#include <map>

class Config
{
private:
    Config();
    
    static Config* singleton;
    std::map<std::string, std::string> properties;
    
public:
    static Config* get();
    
    char keyUp();
    char keyLeft();
    char keyDown();
    char keyRight();
    char keyGiveUp();
    
    std::string getOrDefault(const std::string &key, const std::string &def);
};


#endif
