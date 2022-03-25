#pragma once
#include <SFML/Graphics.hpp>
class Singleton {
private:
	Singleton();
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	sf::Clock m_gameClock;
	sf::Texture m_Texture_menu_Button;
	sf::Texture m_Texture_BackGroundPlay;
	sf::Texture m_Texture_MenuBackGround;
public:
	static Singleton& getInstance();
	sf::Time getElapsedTime() { return m_gameClock.getElapsedTime(); }
	const sf::Texture & GetTexture_menu_Button()const {return m_Texture_menu_Button; };
	const sf::Texture & GetTexture_BackGroundPlay()const { return m_Texture_BackGroundPlay; };
	const sf::Texture & GetTexture_MenuBackGround()const { return m_Texture_MenuBackGround; };
	~Singleton();
};

