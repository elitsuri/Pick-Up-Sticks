#include "buttton.h"

void buttton::Draw(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

void buttton::MoveOn(sf::Vector2f pos)
{
	{
		//if the mouse button
		if (m_sprite.getGlobalBounds().contains(pos))
			m_sprite = m_button_on;
		else
			m_sprite = m_button_before; }//if back
}

buttton::~buttton()
{

}
