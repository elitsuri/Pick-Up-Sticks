#include "button_EXIT.h"

button_EXIT::button_EXIT()
{
}
button_EXIT::button_EXIT(sf::Vector2f pos)
{
	m_sprite.setTexture(m_Texture);//load the picture of the button
	m_sprite.setTexture(m_Texture);
	m_sprite.setTextureRect(sf::IntRect(pos.x, pos.y,150, 50));//setting the option in the window
	m_sprite.setPosition(290, 500);//set the potsion in the window
	m_sprite.setColor(sf::Color(sf::Color::Cyan));//set color

	m_button_on.setTexture(m_Texture);//load the picture of the button on mouse
	m_button_on.setTextureRect(sf::IntRect(pos.x,(pos.y +45), 150, 50));//setting the option in the window
	m_button_on.setPosition(290, 500);//set the potsion in the window
	m_button_before = m_sprite;//after back to the orignal
}

void button_EXIT::ClickOn(sf::Vector2f pos, sf::RenderWindow &window)
{
	if (!m_sprite.getGlobalBounds().contains(pos))
		return;

	window.close();
}

button_EXIT::~button_EXIT()
{
}
