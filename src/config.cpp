#include "config.hpp"


Config::Config() {}

bool Config::load(std::string fileName) {
    if (!Utils::isFileExists(fileName)) {
        this->save(fileName);
    }

    std::ifstream infile(fileName);
    std::string line;

    // Start reading from file
    if (infile.is_open()) {
        while (std::getline(infile, line)) {

            std::string key;
            std::string value;
            bool parseKey = true;

            // Parse each line char by char
            for (uint8_t i = 0; i < line.length(); i++) {
                if (line[i] == ' ') {
                    continue;
                }

                if (line[i] == '=') {
                    parseKey = false;
                    continue;
                }

                if (parseKey) {
                    key += line[i];
                }
                else {
                    value += line[i];
                }
            }

            this->parseConfigKey(key, value);
        }
        infile.close();
    }

    // Load fonts
    if (!this->MAIN_FONT.loadFromFile(BASE_FOLDER + "fonts/FreeSans.ttf")) {
        return false;
    }
    this->BG_COLOR = sf::Color(0, 0, 0);

    // Check errorous settings
    if (this->WINDOW_WIDTH < 800) {
        this->WINDOW_WIDTH = 800;
    }
    else if (this->WINDOW_HEIGHT < 600) {
        this->WINDOW_HEIGHT = 600;
    }
    else if (this->CHARACTER_SIZE < 10) {
        this->CHARACTER_SIZE = 15;
    }
    return true;
}

void Config::save(std::string fileName) {
    std::string data = "";
    std::ofstream configFile;
    configFile.open(fileName);

    data += "WINDOW_WIDTH=" + Utils::to_string(this->WINDOW_WIDTH) + "\n";
    data += "WINDOW_HEIGHT=" + Utils::to_string(this->WINDOW_HEIGHT) + "\n";
    data += "FPS_LIMIT=" + Utils::to_string(this->FPS_LIMIT) + "\n";
    data += "CHARACTER_SIZE=" + Utils::to_string(this->CHARACTER_SIZE) + "\n";
    data += "KEY_UP=" + Utils::to_string(this->KEY_UP) + "\n";
    data += "KEY_DOWN=" + Utils::to_string(this->KEY_DOWN) + "\n";
    data += "KEY_LEFT=" + Utils::to_string(this->KEY_LEFT) + "\n";
    data += "KEY_RIGHT=" + Utils::to_string(this->KEY_RIGHT) + "\n";
    data += "MASTER_VOLUME=" + Utils::to_string(this->MASTER_VOLUME) + "\n";
    data += "SOUND_VOLUME=" + Utils::to_string(this->SOUND_VOLUME) + "\n";
    data += "MUSIC_VOLUME=" + Utils::to_string(this->MUSIC_VOLUME) + "\n";
    data += "IS_FULLSCREEN=" + Utils::to_string(this->IS_FULLSCREEN) + "\n";

    configFile.write(data.c_str(), data.length());
    configFile.close();
}

void Config::parseConfigKey(std::string key, std::string value) {
    if ("WINDOW_WIDTH" == key) {
        try {
            this->WINDOW_WIDTH = std::stoi(value.c_str());
        } catch (std::exception) {}
    }
    else if ("WINDOW_HEIGHT" == key) {
        try {
            this->WINDOW_HEIGHT = std::stoi(value.c_str());
        } catch (std::exception) {}
    }
    else if ("FPS_LIMIT" == key) {
        try {
            this->FPS_LIMIT = std::stoi(value.c_str());
        } catch (std::exception) {}
    }
    else if ("CHARACTER_SIZE" == key) {
        try {
            this->CHARACTER_SIZE = std::stoi(value.c_str());
        } catch (std::exception) {}
    }
    else if ("KEY_UP" == key) {
        try {
            this->KEY_UP = (sf::Keyboard::Key) std::stoi(value.c_str());
        } catch (std::exception) {}
    }
    else if ("KEY_DOWN" == key) {
        try {
            this->KEY_DOWN = (sf::Keyboard::Key) std::stoi(value.c_str());
        } catch (std::exception) {}
    }
    else if ("KEY_LEFT" == key) {
        try {
            this->KEY_LEFT = (sf::Keyboard::Key) std::stoi(value.c_str());
        } catch (std::exception) {}
    }
    else if ("KEY_RIGHT" == key) {
        try {
            this->KEY_RIGHT = (sf::Keyboard::Key) std::stoi(value.c_str());
        } catch (std::exception) {}
    }
    else if ("MASTER_VOLUME" == key) {
        try {
            this->MASTER_VOLUME = std::stoi(value.c_str());
        } catch (std::exception) {}
    }
    else if ("SOUND_VOLUME" == key) {
        try {
            this->SOUND_VOLUME = std::stoi(value.c_str());
        } catch (std::exception) {}
    }
    else if ("MUSIC_VOLUME" == key) {
        try {
            this->MUSIC_VOLUME = std::stoi(value.c_str());
        } catch (std::exception) {}
    }
    else if ("IS_FULLSCREEN" == key) {
        try {
            this->IS_FULLSCREEN = (bool) std::stoi(value.c_str());
        } catch (std::exception) {}
    }
}
