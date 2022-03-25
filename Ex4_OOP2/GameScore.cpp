#include "GameScore.h"
GameScore::GameScore()
{
	m_Score = 0;
	//set the text font
	m_font.loadFromFile("myfont.ttf");
	//***set Text for Score************
	m_text_Score.setFont(m_font);
	m_text_Score.setCharacterSize(30);
	m_text_Score.setFillColor(sf::Color::Black);
	m_text_Score.setOutlineThickness(2);
	m_text_Score.setOutlineColor(sf::Color::White);
	m_text_Score.setStyle(sf::Text::Bold);
	m_text_Score.setPosition(300, 0);
	m_text_Score.setString("YOUR SCORE :");
	//**********************
	//***set Text for number Score************
	m_textNumberScore.setFont(m_font);
	m_textNumberScore.setCharacterSize(30);
	m_textNumberScore.setFillColor(sf::Color::White);
	m_textNumberScore.setStyle(sf::Text::Bold);
	m_textNumberScore.setPosition(525, 0);
	m_textNumberScore.setOutlineThickness(5);
	m_textNumberScore.setOutlineColor(sf::Color::Black);
	m_textNumberScore.setString(std::to_string(m_Score));
	//=********************************************************
	m_HigeScore.open("HigeScore.txt");
	m_HigeScore >> m_HigeScoreRes;
	m_HigeScore.close();
	m_PrintHiga = false;
	//***set Text for hige Score************
	m_textHigeScore.setFont(m_font);
	m_textHigeScore.setCharacterSize(20);
	m_textHigeScore.setFillColor(sf::Color::White);
	m_textHigeScore.setStyle(sf::Text::Bold);
	m_textHigeScore.setPosition(300, 50);
	m_textHigeScore.setOutlineThickness(5);
	m_textHigeScore.setOutlineColor(sf::Color::Black);
	m_textHigeScore.setString("HIGE SCORE :"+ std::to_string(m_HigeScoreRes));
	//=********************************************************
}
//===========================================================
void GameScore::SetScore(int Score)
{
	m_Score += Score;//clacalte the score of the game

	m_textNumberScore.setString(std::to_string(m_Score));
}
//========================================================

void GameScore::print(sf::RenderWindow & Window)
{
	//show the text and the schores
	Window.draw(m_textNumberScore);
	Window.draw(m_text_Score);
	Window.draw(m_textHigeScore);
	//Window.draw(m_textNumberScore);
}
//========================================================
bool GameScore::NewHigeScore()
{
	//make new hige score
	if(m_HigeScoreRes<m_Score)
	{ 
	m_HigeScore.open("HigeScore.txt");
	m_HigeScore << m_Score;
	m_HigeScoreRes= m_Score;
	m_textHigeScore.setString("HIGE SCORE :" + std::to_string(m_HigeScoreRes));
	m_HigeScore.close();
	return true;
	}
	return false;
}
//========================================================
GameScore::~GameScore()
{
}
