#pragma once
#include "buttton.h"
class button_EXIT :public buttton
{
public:
	button_EXIT();
	button_EXIT( sf::Vector2f pos);//consractor button exit
	//function if the mouse press the button
	virtual void ClickOn(sf::Vector2f pos, sf::RenderWindow &window);
	//function get the sprite
	virtual sf::Sprite GetSprite() { return m_sprite; };

	~button_EXIT();
};

