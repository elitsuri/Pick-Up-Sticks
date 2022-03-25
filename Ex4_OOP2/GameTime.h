#pragma once
#include <SFML\Graphics.hpp>
#include <string>
class GameTime
{
public:
	GameTime(int TimeLeft);//ctor get atime for the game and srat to run form this time until zero
	//function to set time
	void setTimeRun();
	//function to print the timar and time
	void print(sf::RenderWindow & Window);
	//function to get if end of time game
	bool GetEndTime()const { return m_endTime; };
	~GameTime();
private:
	sf::Font m_font;//font of the texr
	sf::Text m_text_clock_left;//text timar
	sf::Text m_textTimeLeft;//texxt that show the name
	sf::Text m_textLeft;//text for name 
	int m_counterGamaeRun; //Calculate for the end time
	bool m_endTime = false;//if time over stop the clock
	int m_TimeLeft = 0;//zero the counter
	int m_TimeWas;//for Calculate the time
	sf::Clock m_clock;
};

