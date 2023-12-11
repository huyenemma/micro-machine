#ifndef BASE_MENU_HPP
#define BASE_MENU_HPP

#include <SFML/Graphics.hpp>
#include <vector>

const int NUM_ITEMS = 3; 

class BaseMenu {
public:

    BaseMenu(sf::RenderWindow& window, const sf::Font& font, const sf::Texture& texture);
    virtual ~BaseMenu() {};
    virtual void draw();
    void MoveUp();
    void MoveDown();
    int GetPressedItem() const;

protected:

    sf::Text menuItems_[NUM_ITEMS];
    sf::RenderWindow& window_;
    sf::Font font_; 
    sf::Texture texture_; 
    sf::Sprite sprite_;
    std::size_t selectedItemIndex;
    
};

#endif // BASE_MENU_HPP
