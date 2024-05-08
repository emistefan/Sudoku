#include "Screen_1.h"

// Constructor
Screen_1::Screen_1(ResourceHolder* _rh, sf::RenderWindow& window) : rh(_rh), board(_rh, window)
{
}

// Destructor
Screen_1::~Screen_1()
{
}

// Function to handle mouse click events
void Screen_1::handle_mouseclick(sf::RenderWindow& window, sf::Vector2i m_pos)
{
    // Pass the mouse click event to the board for handling
    if (board.handle_click(window, m_pos)) return;
}

// Function to run the screen
int Screen_1::Run(sf::RenderWindow& window)
{
    while (true)
    {
        sf::Vector2i m_pos = sf::Mouse::getPosition(window); // Get mouse position
        sf::Event event;

        while (window.pollEvent(event))
        {
            // Check for window close event
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return 0;
            }

            // Check for mouse button press event
            if (event.type == sf::Event::MouseButtonPressed)
                if (event.key.code == sf::Mouse::Left)
                {
                    handle_mouseclick(window, m_pos); // Handle mouse click
                }

            // Check for keyboard key press event
            if (event.type == sf::Event::KeyPressed)
            {
                // Handle numpad key presses
                switch (event.key.code)
                {
                case sf::Keyboard::Numpad1:
                case sf::Keyboard::Numpad2:
                case sf::Keyboard::Numpad3:
                case sf::Keyboard::Numpad4:
                case sf::Keyboard::Numpad5:
                case sf::Keyboard::Numpad6:
                case sf::Keyboard::Numpad7:
                case sf::Keyboard::Numpad8:
                case sf::Keyboard::Numpad9:
                case sf::Keyboard::Numpad0:
                    board.handle_input(event.key.code - sf::Keyboard::Numpad0); // Pass the input to the board
                    break;

                    // Handle normal number key presses
                case sf::Keyboard::Num1:
                case sf::Keyboard::Num2:
                case sf::Keyboard::Num3:
                case sf::Keyboard::Num4:
                case sf::Keyboard::Num5:
                case sf::Keyboard::Num6:
                case sf::Keyboard::Num7:
                case sf::Keyboard::Num8:
                case sf::Keyboard::Num9:
                case sf::Keyboard::Num0:
                    board.handle_input(event.key.code - sf::Keyboard::Num0); // Pass the input to the board
                    break;
                }
            }
        }
        board.update_squares(); // Update board

        window.clear(rh->background_color); // Clear the window
        board.draw(window); // Draw the board
        for (auto b : rh->buttons) window.draw(b); // Draw buttons
        for (auto t : rh->texts) window.draw(t); // Draw texts
        window.display(); // Display the window
    }

    return 1;
}
