#pragma once
#include "buttton.h"
class button_help :public buttton
{
public:
	button_help();//consractor button help
	button_help( sf::Vector2f pos);
	//function if the mouse press the button
	virtual void ClickOn(sf::Vector2f pos, sf::RenderWindow &window);
	//function get the sprite
	virtual sf::Sprite GetSprite() { return m_sprite; };
	
	~button_help();
private:
	bool m_open_help;
};

