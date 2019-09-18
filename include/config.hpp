#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <utils.hpp>

extern std::string BASE_FOLDER;


class Config {
    /**
    Stores the configuration of the game.

    Declared in "global.cpp", defined in main.
    */
    public:
        unsigned int WINDOW_WIDTH = 800;
        unsigned int WINDOW_HEIGHT = 600;
        unsigned int FPS_LIMIT = 60;
        unsigned int CHARACTER_SIZE = 14;
        unsigned int MASTER_VOLUME = 100;
        unsigned int SOUND_VOLUME = 100;
        unsigned int MUSIC_VOLUME = 100;
        bool IS_FULLSCREEN = false;
        sf::Keyboard::Key KEY_UP = sf::Keyboard::W;
        sf::Keyboard::Key KEY_DOWN = sf::Keyboard::S;
        sf::Keyboard::Key KEY_LEFT = sf::Keyboard::A;
        sf::Keyboard::Key KEY_RIGHT = sf::Keyboard::D;

        // Not settable variables
        sf::Font MAIN_FONT;
        sf::Color BG_COLOR;

        Config();

        /**
        @returns true if loading was successful.
        */
        bool load(std::string fileName);
        void save(std::string fileName);

    private:

        /**
        Setting the "config" class variable "key" to the given "value"
        */
        void parseConfigKey(std::string key, std::string value);
};

#endif // CONFIG_HPP
