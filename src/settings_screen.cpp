#include "settings_screen.hpp"


SettingsScreen::SettingsScreen() {
    this->backButton = Button(2 * CONFIG.CHARACTER_SIZE, CONFIG.WINDOW_HEIGHT - 3.5 * CONFIG.CHARACTER_SIZE, "BACK");
}

ScreenType SettingsScreen::display(sf::RenderWindow &window) {
    this->backButton.display(window);

    if (this->backButton.state == ButtonState::RELEASED) {
        return ScreenType::MAIN_MENU;
    }
    return ScreenType::SETTINGS;
}
