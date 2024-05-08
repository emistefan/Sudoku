#include "Square.h"

// Default constructor
Square::Square() {}

// Constructor with parameters
Square::Square(sf::Vector2f pos, int _correct_number, ResourceHolder* _rh) :
    correct_number(_correct_number), // Set the correct number
    entered_number(_correct_number), // Set the entered number
    rh(_rh), // Set the resource holder pointer
    locked(true) // Set locked flag to true by default
{
    // Set position, fill color, and size of the square
    setPosition(pos);
    setFillColor(rh->clear_color);
    setSize(sf::Vector2f(rh->square_pixel_size, rh->square_pixel_size));

    // Set up text properties
    text.setFont(rh->number_font);
    text.setCharacterSize(20);
    text.setFillColor(rh->black_color);

    // Calculate text origin and position it in the center of the square
    auto rect = getGlobalBounds();
    auto textRect = text.getGlobalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);
    text.setPosition({ rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f });
}

// Destructor
Square::~Square() {}

// Update method to update the square appearance based on the entered number and mode
void Square::update(bool manual_mode)
{
    // Set text to the entered number or empty string if it's 0
    if (entered_number != 0)
        text.setString(std::to_string(entered_number));
    else
        text.setString("");

    // Update appearance based on manual mode
    if (manual_mode)
    {
        correct_number = entered_number;
        text.setFillColor(rh->black_color);
    }
    else
    {
        if (entered_number == correct_number && !locked)
            text.setFillColor(rh->blue_color);
        else if (entered_number != correct_number && !locked)
            text.setFillColor(rh->red_color);
    }
}

// Draw method to draw the square and its text
void Square::draw(sf::RenderWindow& window)
{
    window.draw(*this);
    window.draw(text);
}