#include "button_help.h"
#include <iostream>

button_help::button_help()
{

}
button_help::button_help( sf::Vector2f pos)
{
	
	m_sprite.setTexture(m_Texture);
	m_sprite.setTexture(m_Texture);//load the picture
	m_sprite.setTextureRect(sf::IntRect(pos.x, pos.y,150,50));//picture butoon from the all picture
	m_sprite.setPosition(280,435);//setting thesprite pos
	m_button_on.setTexture(m_Texture);//load picture mouse on button 
	 //picture butoon from the all picture
	m_button_on.setTextureRect(sf::IntRect(pos.x, (pos.y+50), 150, 50));
	m_button_on.setPosition(280, 435);//set the position on the window
	//save the before mouse on
	m_button_before = m_sprite;
	m_open_help = false;
}

void button_help::ClickOn(sf::Vector2f pos, sf::RenderWindow &window)
{
	if (!m_sprite.getGlobalBounds().contains(pos))
		return;
	 
	sf::Sprite helps;
	sf::Texture h1;
	h1.loadFromFile("Help.png");//load the detials help(picture)
	helps.setTexture(h1);

	window.clear();
	window.draw(helps);
	window.display();
	
	//loop for window help
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
			switch (event.type)
			{
			case sf::Event::Closed:
			{
				//if closed the window of help
		
				return;
				
			}
			case sf::Event::MouseButtonPressed:
			{
				//button to back to menu
				if (0 < event.mouseButton.x && event.mouseButton.x < 220
					&& 750 < event.mouseButton.y && event.mouseButton.y < 800)
				{

					return;
				}
			}

			}
	}
}

button_help::~button_help()
{

}
