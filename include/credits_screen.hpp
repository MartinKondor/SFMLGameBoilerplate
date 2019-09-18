#ifndef CREDITS_SCREEN_HPP
#define CREDITS_SCREEN_HPP

#include <SFML/Graphics.hpp>
#include <screen.hpp>
#include <button.hpp>
#include <config.hpp>

extern Config CONFIG;


class CreditsScreen : public Screen {
    /**
    Credits.
    */
    private:
        Button backButton;

    public:
        CreditsScreen();
        virtual ScreenType display(sf::RenderWindow& window);
};

#endif // CREDITS_SCREEN_HPP
