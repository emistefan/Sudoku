#include "ResourceHolder.h"

// Constructor
ResourceHolder::ResourceHolder() :
    background_color(0xDBDCDEFF), // Set background color
    chosen_square_color(0x708090AA), // Set chosen square color
    red_color(0xFF0000FF), // Set red color
    clear_color(0xFFFFFF00), // Set clear color
    black_color(0x000000FF), // Set black color
    blue_color(0x0000FFFF), // Set blue color
    button_color(0xFFFFFFFF), // Set button color
    button_line_color(0x000000FF) // Set button line color
{
    // Load fonts
    number_font.loadFromFile("fonts/Helvetica Black Condensed.otf");
    bohemian_font.loadFromFile("fonts/Helvetica Black Condensed.otf");

    // Initialize buttons and header

    // Header
    sf::Text headline("Sudosolver", bohemian_font, 100); // Create text for the header
    headline.setFillColor(sf::Color::Black); // Set text color
    headline.setStyle(sf::Text::Bold); // Set text style
    sf::FloatRect textRect = headline.getLocalBounds(); // Get local bounds of the text
    headline.setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f); // Set origin of the text
    headline.setPosition(sf::Vector2f((s_width - (s_width - board_size - board_offset_x) / 2), 150)); // Set position of the text
    texts.push_back(headline); // Add text to the vector

    // New Game button
    sf::RectangleShape new_button(sf::Vector2f(button_width, button_height)); // Create rectangle shape for the button
    new_button.setOrigin(button_width / 2, button_height / 2); // Set origin of the button
    new_button.setFillColor(button_color); // Set fill color of the button
    new_button.setOutlineColor(button_line_color); // Set outline color of the button
    new_button.setOutlineThickness(button_outline_thickness); // Set outline thickness of the button
    new_button.setPosition(sf::Vector2f(s_width - (s_width - board_size - board_offset_x) / 2, 400)); // Set position of the button
    buttons.push_back(new_button); // Add button to the vector

    sf::Text new_game_text("New Game", bohemian_font, button_text_size); // Create text for the button
    new_game_text.setFillColor(black_color); // Set text color

    sf::FloatRect new_rectBounds = new_button.getGlobalBounds(); // Get global bounds of the button
    sf::FloatRect new_textBounds = new_game_text.getGlobalBounds(); // Get global bounds of the text

    new_game_text.setPosition(
        new_rectBounds.left + (new_rectBounds.width / 2) - (new_textBounds.width / 2),
        new_rectBounds.top + (new_rectBounds.height / 2) - (new_textBounds.height / 2)); // Set position of the text

    texts.push_back(new_game_text); // Add text to the vector

    // Solve button
    sf::RectangleShape solve_button(sf::Vector2f(button_width, button_height)); // Create rectangle shape for the button
    solve_button.setOrigin(button_width / 2, button_height / 2); // Set origin of the button
    solve_button.setFillColor(button_color); // Set fill color of the button
    solve_button.setOutlineColor(button_line_color); // Set outline color of the button
    solve_button.setOutlineThickness(button_outline_thickness); // Set outline thickness of the button
    solve_button.setPosition(sf::Vector2f(s_width - (s_width - board_size - board_offset_x) / 2, 650)); // Set position of the button
    buttons.push_back(solve_button); // Add button to the vector

    sf::Text solve_text("Solve the current", bohemian_font, button_text_size); // Create text for the button
    solve_text.setFillColor(black_color); // Set text color

    sf::FloatRect solve_rectBounds = solve_button.getGlobalBounds(); // Get global bounds of the button
    sf::FloatRect solve_textBounds = solve_text.getGlobalBounds(); // Get global bounds of the text

    solve_text.setPosition(
        solve_rectBounds.left + (solve_rectBounds.width / 2) - (solve_textBounds.width / 2),
        solve_rectBounds.top + (solve_rectBounds.height / 2) - (solve_textBounds.height / 2)); // Set position of the text

    texts.push_back(solve_text); // Add text to the vector

    // Manual Entry button
    sf::RectangleShape manual_entry_button(sf::Vector2f(button_width, button_height)); // Create rectangle shape for the button
    manual_entry_button.setOrigin(button_width / 2, button_height / 2); // Set origin of the button
    manual_entry_button.setFillColor(button_color); // Set fill color of the button
    manual_entry_button.setOutlineColor(button_line_color); // Set outline color of the button
    manual_entry_button.setOutlineThickness(button_outline_thickness); // Set outline thickness of the button
    manual_entry_button.setPosition(sf::Vector2f(s_width - (s_width - board_size - board_offset_x) / 2, 900)); // Set position of the button
    buttons.push_back(manual_entry_button); // Add button to the vector

    sf::Text manual_entry_text("Manual", bohemian_font, button_text_size); // Create text for the button
    manual_entry_text.setFillColor(black_color); // Set text color

    sf::FloatRect manual_entry_rectBounds = manual_entry_button.getGlobalBounds(); // Get global bounds of the button
    sf::FloatRect manual_entry_textBounds = manual_entry_text.getGlobalBounds(); // Get global bounds of the text

    manual_entry_text.setPosition(
        manual_entry_rectBounds.left + (manual_entry_rectBounds.width / 2) - (manual_entry_textBounds.width / 2),
        manual_entry_rectBounds.top + (manual_entry_rectBounds.height / 2) - (manual_entry_textBounds.height / 2)); // Set position of the text

    texts.push_back(manual_entry_text); // Add text to the vector

    // Load texture for loading animation
    load_texture.loadFromFile("img/load_sheet.png");
    load_sprite.setTexture(load_texture);
    load_sprite.setTextureRect(sf::IntRect(0, 0, load_texture.getSize().x / num_of_anims, load_texture.getSize().y));
    load_sprite.setOrigin(load_sprite.getGlobalBounds().width / 2, load_sprite.getGlobalBounds().height / 2);
    load_sprite.setPosition(board_offset_x + board_size / 2, board_offset_y + board_size / 2);

    // Load icon
    icon.loadFromFile("img/icon.png");
}

// Destructor
ResourceHolder::~ResourceHolder()
{
}
