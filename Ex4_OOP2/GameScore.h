#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <fstream>
class GameScore
{
public:
	GameScore();//ctor rest the text for the score 
	void SetScore(int Score);//set the var for the score of game
	int GetScore() { return m_Score; };//reurn the score
	void print(sf::RenderWindow & Window);//show the score and higa score
	bool NewHigeScore();//check the higs score

	~GameScore();
private:
	int m_Score;
	sf::Font m_font;//font of the texr
	sf::Text m_text_Score;//text timar
	sf::Text m_textNumberScore;//texxt that show the name
	//***********************************************
	sf::Text m_textHigeScore;
	std::fstream m_HigeScore;//text that save the hige score the user make in th lasts games
	int m_HigeScoreRes;
	bool m_PrintHiga;//if the gamer make new hige score

};

