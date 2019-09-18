#include "loading_screen.hpp"


LoadingScreen::LoadingScreen() {
    this->loadingText = sf::Text("Loading ...", CONFIG.MAIN_FONT, CONFIG.CHARACTER_SIZE);
    this->loadingText.setPosition((int) (CONFIG.WINDOW_WIDTH / 2 - CONFIG.CHARACTER_SIZE * this->loadingText.getString().getSize() / 4),
                                  CONFIG.WINDOW_HEIGHT - 50);

    sf::Image logoImage;
    sf::Image sfmlLogoImage;

    logoImage.loadFromFile(IMAGE_FOLDER + "logo.png");
    this->logoTexture.loadFromImage(logoImage);
    sfmlLogoImage.loadFromFile(IMAGE_FOLDER + "sfml_logo.png");
    this->sfmlLogoTexture.loadFromImage(sfmlLogoImage);

    this->logo.setTexture(this->logoTexture);
    this->logo.setPosition((int) (CONFIG.WINDOW_WIDTH / 2) - this->logoTexture.getSize().x / 2,
                            (int) (CONFIG.WINDOW_HEIGHT / 2) - this->logoTexture.getSize().y / 2);

    this->sfmlLogo.setTexture(this->sfmlLogoTexture);
    this->sfmlLogo.setScale(0.15, 0.15);
    this->sfmlLogo.setPosition(25, CONFIG.WINDOW_HEIGHT - 75);
}

ScreenType LoadingScreen::display(sf::RenderWindow &window) {
    window.draw(this->logo);
    window.draw(this->loadingText);
    window.draw(this->sfmlLogo);
    window.display();

    // sf::sleep(sf::seconds(1));

    return ScreenType::MAIN_MENU;
}
