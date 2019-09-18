#ifndef MAIN_MENU_SCREEN_HPP
#define MAIN_MENU_SCREEN_HPP

#include <SFML/Graphics.hpp>
#include <screen.hpp>
#include <button.hpp>

extern Config CONFIG;
extern std::string IMAGE_FOLDER;


enum class MainMenuSubScreen {
    NONE,
    NEW_GAME,
    LOAD_GAME
};


class MainMenuScreen : public Screen {
    /**
    Main menu screen.
    */
    private:
        Button newGameButton;
        Button loadSaveGameButton;
        Button settingsButton;
        Button creditsButton;
        Button exitButton;
        Button subScreenBackButton;
        sf::Texture logoTexture;
        sf::Sprite logo;
        MainMenuSubScreen subScreen;

    public:
        MainMenuScreen();
        ScreenType displaySubScreen(sf::RenderWindow &window);
        virtual ScreenType display(sf::RenderWindow& window);
};

#endif // MAIN_MENU_SCREEN_HPP
