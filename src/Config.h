#ifndef CONFIG_H
#define CONFIG_H

/**
 * @file Config.h
 * @brief header for the Config class
 */

#include <map>

/**
 * @class Config
 * @brief Provides a way to read from the game configuration file
 *
 * The default configuration file is named 'game.properties', it's a Java properties file.
 * I preferred this format instead of YAML because we don't need all of its advantages, so
 * a property file (under a format that i often use) is perfect for this usage.
 */
class Config
{
private:
    /**
     * @brief The only class constructor
     *
     * Reads the configuration file, and put the properties in the map.
     */
    Config();

    /**
     * @brief The only instance of the class, a singleton
     */
    static Config* singleton;

    /**
     * @brief The properties map
     */
    std::map<std::string, std::string> properties;
    
public:

    /**
     * @brief Used to get the singleton class instance
     *
     * Instantiate the class if @ref #singleton contains a nullptr
     *
     * @return The pointer to the class instance
    */
    static Config* get();

    /**
     * @brief Custom function to get the up key
     * @return The up key as a character
     */
    char keyUp();

    /**
     * @brief Custom function to get the left key
     * @return The left key as a character
     */
    char keyLeft();

    /**
     * @brief Custom function to get the down key
     * @return The down key as a character
     */
    char keyDown();

    /**
     * @brief Custom function to get the right key
     * @return The right key as a character
     */
    char keyRight();

    /**
     * @brief Custom function to get the give up key
     * @return The give up key as a character
     */
    char keyGiveUp();

    /**
     * @brief Gets the value associated to the provided key
     *
     * @param key The key
     * @param def The default value
     * @return the value associated to the key, the default value if this value is an empty string
     */
    std::string getOrDefault(const std::string &key, const std::string &def);
};


#endif
