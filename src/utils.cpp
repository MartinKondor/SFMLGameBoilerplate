#include "utils.hpp"


bool Utils::isFileExists(const std::string fileName) {
    struct stat buffer;
    return (stat(fileName.c_str(), &buffer) == 0);
}

std::string Utils::getBaseDir(const std::string exeFilePath) {
    int lastSlashIndex = 0;
    for (unsigned int i = 0; i < exeFilePath.length(); i++) {
        if (exeFilePath[i] == '\\' || exeFilePath[i] == '/') {
            lastSlashIndex = i;
        }
    }
    return exeFilePath.substr(0, lastSlashIndex + 1);
}
