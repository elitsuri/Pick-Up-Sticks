#pragma once
#include "buttton.h"
class button_NewGame :public buttton
{
public:
	button_NewGame();
	button_NewGame(sf::Vector2f pos);//consractor button new game
   //function if the mouse press the button
	virtual void ClickOn(sf::Vector2f pos, sf::RenderWindow &window);
	//function get the sprite
	virtual sf::Sprite GetSprite() { return m_sprite; }
	
	~button_NewGame();
private:
	//==========================================
	void SetMyDifficultyLevelText();
	void ChooseDifficultyLevel(sf::RenderWindow &window);
	//==========================================
	sf::Font m_font;//font of the texr
	sf::Text m_text_esay;//text timar
	sf::Text m_text_medium;//texxt that show the name
	sf::Text m_text_hard;//texxt that show the name
	std::vector<sf::Text>m_MyDifLevl;
	sf::Vector2i m_RangeOfDifLevl;
	sf::Sprite m_MenuDifLevel;//the sprite of the menu
	//==========================================
	sf::Texture m_DokTex;
	sf::Sprite m_DokSprite;

};

