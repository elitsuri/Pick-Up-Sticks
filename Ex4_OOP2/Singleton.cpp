#include "Singleton.h"
#include <iostream>
Singleton::Singleton()
{
	m_gameClock.restart();//restart the clock
	m_Texture_menu_Button.loadFromFile("main1.png"); //load main1
	m_Texture_BackGroundPlay.loadFromFile("back_groundForPlay.png");
	m_Texture_MenuBackGround.loadFromFile("menu_p.jpg");
}

Singleton & Singleton::getInstance()
{
	static Singleton single;
	return single;
}

Singleton::~Singleton()
{
}