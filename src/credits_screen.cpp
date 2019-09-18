#include "credits_screen.hpp"


CreditsScreen::CreditsScreen() {
    this->backButton = Button(2 * CONFIG.CHARACTER_SIZE, CONFIG.WINDOW_HEIGHT - 3.5 * CONFIG.CHARACTER_SIZE, "BACK");
}

ScreenType CreditsScreen::display(sf::RenderWindow& window) {
    this->backButton.display(window);

    if (this->backButton.state == ButtonState::RELEASED) {
        return ScreenType::MAIN_MENU;
    }
    return ScreenType::CREDITS;
}
