#include "main_menu_screen.hpp"


MainMenuScreen::MainMenuScreen() {
    int buttonMargin = 45;
    int commonX = 15;

    this->newGameButton = Button(commonX, CONFIG.WINDOW_HEIGHT - 5 * buttonMargin, "NEW GAME", 157, 0);
    this->loadSaveGameButton = Button(commonX, CONFIG.WINDOW_HEIGHT - 4 * buttonMargin, "LOAD GAME", 157, 0);
    this->settingsButton = Button(commonX, CONFIG.WINDOW_HEIGHT - 3 * buttonMargin, "SETTINGS", 157, 0);
    this->creditsButton = Button(commonX, CONFIG.WINDOW_HEIGHT - 2 * buttonMargin, "CREDITS", 157, 0);
    this->exitButton = Button(commonX, CONFIG.WINDOW_HEIGHT - buttonMargin, "EXIT", 157, 0);
    this->subScreenBackButton = Button(2 * CONFIG.CHARACTER_SIZE, CONFIG.WINDOW_HEIGHT - 3.5 * CONFIG.CHARACTER_SIZE, "BACK");

    // Load logo
    sf::Image logoImage;

    logoImage.loadFromFile(IMAGE_FOLDER + "logo.png");
    this->logoTexture.loadFromImage(logoImage);
    this->logo.setTexture(logoTexture);
    this->logo.setPosition(CONFIG.WINDOW_WIDTH - logoImage.getSize().x, 0);

    this->subScreen = MainMenuSubScreen::NONE;
}

ScreenType MainMenuScreen::displaySubScreen(sf::RenderWindow &window) {
    this->subScreenBackButton.display(window);

    if (this->subScreenBackButton.state == ButtonState::RELEASED) {
        this->subScreen = MainMenuSubScreen::NONE;
    }
    return ScreenType::MAIN_MENU;
}

ScreenType MainMenuScreen::display(sf::RenderWindow &window) {
    if (this->subScreen != MainMenuSubScreen::NONE) {
        return this->displaySubScreen(window);
    }

    this->newGameButton.display(window);
    this->loadSaveGameButton.display(window);
    this->settingsButton.display(window);
    this->creditsButton.display(window);
    this->exitButton.display(window);
    window.draw(this->logo);

    if (this->exitButton.state == ButtonState::RELEASED) {
        return ScreenType::EXIT;
    }
    else if (this->newGameButton.state == ButtonState::RELEASED) {
        this->subScreen = MainMenuSubScreen::NEW_GAME;
        return ScreenType::MAIN_MENU;
    }
    else if (this->loadSaveGameButton.state == ButtonState::RELEASED) {
        this->subScreen = MainMenuSubScreen::LOAD_GAME;
        return ScreenType::MAIN_MENU;
    }
    else if (this->settingsButton.state == ButtonState::RELEASED) {
        return ScreenType::SETTINGS;
    }
    else if (this->creditsButton.state == ButtonState::RELEASED) {
        return ScreenType::CREDITS;
    }

    return ScreenType::MAIN_MENU;
}
