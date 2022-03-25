#pragma once
#include <SFML\Graphics.hpp>
#include "Singleton.h"
//Bequeaths all buttons
class buttton
{
public:
	//consractor of button 
	buttton() {m_Texture = Singleton::getInstance().GetTexture_menu_Button();};
   //Clicking to button function is realized not here
	virtual void ClickOn(sf::Vector2f pos, sf::RenderWindow &window) = 0;
	//Drawing function buttons
	virtual void Draw(sf::RenderWindow &window);
	//get the sprite is realized not here
	virtual sf::Sprite GetSprite() = 0;
	//With the mouse button
	virtual void MoveOn(sf::Vector2f pos);
	virtual ~buttton();
protected:
	sf::Sprite m_sprite;
	sf::Sprite m_button_on;
	sf::Sprite m_button_before;
	sf::Texture m_Texture;
};

