#include <SFML/Graphics.hpp>
#include <Windows.h> // Necessary for ShowWindow() and GetConsoleWindow()
#include "Screen_1.h"
#include <ctime> // For time function
#include "ResourceHolder.h"

int main()
{
    // Hide the console window
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    // Create a ResourceHolder instance
    ResourceHolder* rh = new ResourceHolder();

    // Create SFML RenderWindow
    sf::RenderWindow window(sf::VideoMode(1600, 1200), "Sudoku");
    window.setIcon(rh->icon.getSize().x, rh->icon.getSize().y, rh->icon.getPixelsPtr());

    // Vector to store different screens
    std::vector<cScreen*> Screens;

    // Initialize screen index
    int screen = 0;

    // Create the first screen instance and add it to the vector
    cScreen* s0 = new Screen_1(rh, window);
    Screens.push_back(s0);

    // Main loop for running the screens
    while (screen <= 0)
    {
        // Run the current screen and get the next screen index
        screen = Screens[screen]->Run(window);

        // Break out of the loop if the next screen index is 0
        if (screen == 0) break;

        // If the next screen index is 2, restart the game
        if (screen == 2)
        {
            // Delete the previous screen instance
            delete Screens[0];

            // Create a new instance of Screen_1 and add it to the vector
            cScreen* s0 = new Screen_1(rh, window);
            Screens.push_back(s0);

            // Reset the screen index
            screen = 0;
        }
    }

    return 0;
}
