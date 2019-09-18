#include "button.hpp"


Button::Button() : Button(0, 0, "-") {}

Button::Button(const unsigned int xPos, const unsigned int yPos, const std::string label)
    : Button(xPos, yPos, label, 0, 0) {}

Button::Button(const unsigned int xPos, const unsigned int yPos, const std::string label,
               const unsigned int width, const unsigned int height) {
    this->xPos = xPos;
    this->yPos = yPos;
    this->label = sf::Text(label, CONFIG.MAIN_FONT, CONFIG.CHARACTER_SIZE);
    this->width = width == 0 ? (CONFIG.CHARACTER_SIZE * label.length() + 1.5 * CONFIG.CHARACTER_SIZE) : width;
    this->height = height == 0 ? (2 * CONFIG.CHARACTER_SIZE) : height;
    this->state = ButtonState::NORMAL;
    this->outlineThickness = 3;

    this->bodyColor = sf::Color(0, 0, 0);
    this->outlineColor = sf::Color(255, 255, 255);
    this->fontColor = sf::Color(255, 255, 255);
    this->hoverFontColor = sf::Color(255 - this->fontColor.r, 255 - this->fontColor.g, 255 - this->fontColor.b);

    this->body.setPosition(this->xPos, this->yPos);
    this->body.setFillColor(this->bodyColor);
    this->body.setSize(sf::Vector2f(this->width, this->height));
    this->body.setOutlineColor(this->outlineColor);
    this->body.setOutlineThickness(this->outlineThickness);

    this->label.setFont(CONFIG.MAIN_FONT);
    this->label.setCharacterSize(CONFIG.CHARACTER_SIZE);
    this->label.setOrigin((int)(this->label.getLocalBounds().width / 2), (int)(this->label.getLocalBounds().height / 2));
    this->label.setPosition(this->xPos + (int)(this->width / 2), this->yPos + (int)(this->height / 2 - CONFIG.CHARACTER_SIZE / 4));
}

void Button::display(sf::RenderWindow &window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    if (mousePos.x > this->xPos && mousePos.y > this->yPos && mousePos.x < this->xPos + this->width && mousePos.y < this->yPos + this->height) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->state = ButtonState::CLICKED;
        }
        else if (state == ButtonState::CLICKED) {
            this->state = ButtonState::RELEASED;
        }
        else {
            this->state = ButtonState::HOVERED;
        }
    }
    else {
        this->state = ButtonState::NORMAL;
    }

    this->body.setOutlineColor(this->outlineColor);

    if (this->state == ButtonState::HOVERED) {
        this->body.setFillColor(this->outlineColor);
        this->label.setFillColor(this->hoverFontColor);
    }
    else if (this->state == ButtonState::CLICKED) {
        this->body.setOutlineColor(this->bodyColor);
        this->body.setFillColor(this->outlineColor);
        this->label.setFillColor(this->hoverFontColor);
    }
    else if (this->state == ButtonState::RELEASED) {
        this->body.setFillColor(this->outlineColor);
        this->label.setFillColor(this->hoverFontColor);
    }
    else {
        this->body.setFillColor(this->bodyColor);
        this->label.setFillColor(this->fontColor);
    }

    window.draw(this->body);
    window.draw(this->label);
}
