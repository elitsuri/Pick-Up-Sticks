#include "GameTime.h"
#include <iostream>

//================================================================
GameTime::GameTime(int TimeLeft)
{
	//**********************************
	//set the text font
	m_font.loadFromFile("myfont.ttf");
	//***********************************
	//set the text game time left
	m_TimeWas = 0;
	 m_TimeLeft = TimeLeft;
	m_text_clock_left.setFont(m_font);

	m_text_clock_left.setCharacterSize(30);
	m_text_clock_left.setFillColor(sf::Color::Black);
	m_text_clock_left.setOutlineThickness(2);
	m_text_clock_left.setOutlineColor(sf::Color::White);
	m_text_clock_left.setStyle(sf::Text::Bold);
	m_text_clock_left.setPosition(220, 0);
	//**********************
	//set the text timar
	m_textTimeLeft.setFont(m_font);
	m_textTimeLeft.setCharacterSize(30);
	m_textTimeLeft.setFillColor(sf::Color::White);
	m_textTimeLeft.setStyle(sf::Text::Bold);
	m_textTimeLeft.setPosition(10,0);
	m_textTimeLeft.setOutlineThickness(5);
	m_textTimeLeft.setOutlineColor(sf::Color::Black);
	m_textTimeLeft.setString("GAME OVER :");
	m_clock.restart();
}
//================================================================
void GameTime::setTimeRun()//chek the time and if its end
{
	sf::Time t1;//save the time as seconed
	t1 = sf::seconds(m_clock.getElapsedTime().asSeconds());
	m_counterGamaeRun = t1.asSeconds();
	//Calculation seconds

	
		//Calculate the end time
		if (m_counterGamaeRun > m_TimeWas)
		{
			m_TimeWas = m_counterGamaeRun;
			m_TimeLeft--;

			m_text_clock_left.setString(std::to_string(m_TimeLeft));
		}
		//if over the time
		if (m_TimeLeft == 0)
			m_endTime = true;
	

}
//================================================================
void GameTime::print(sf::RenderWindow & Window)
{
		Window.draw(m_text_clock_left);//draw the timar
		Window.draw(m_textTimeLeft);//draw the text timar
	
}
//================================================================
GameTime::~GameTime()
{
}
