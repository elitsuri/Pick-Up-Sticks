#pragma once
#include "GameTime.h"
#include "Doks.h"
#include "GameScore.h"
#include <iostream>
#include <SFML\Audio.hpp>

class Controller
{
public:
	//c-tor set the vars for the borad and call to the function that run the game
	Controller(int RangeMin=15, int RangeMax=30);
	bool PlayNow();//main function in this object that mange the game
	void PrintAfterGame();//function to print the msg after the game
	~Controller();
private:
	//====vars for gameing============================
	Doks  m_MyDoks;
	sf::Sprite m_GameBackGround;
	int m_GameScore = 0;
	std::string m_MessegeAfterGame;
	GameScore m_MyScore;
	//====vars for music afacte============================
	sf::SoundBuffer m_SondFile;
	sf::Sound m_TouchingOkSound;
	//====vars for music afacte============================
	sf::SoundBuffer m_SondFileForWorng;
	sf::Sound m_TouchingDontGoodSound;

};

