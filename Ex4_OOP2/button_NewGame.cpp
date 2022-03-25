#include "button_NewGame.h"
#include "Controller.h"
const sf::Vector2i EASY = { 30,40 };
const sf::Vector2i MEDIUM = { 60,80 };
const sf::Vector2i HARD = { 85,120 };
const float SIZE_TEXT = 70;

button_NewGame::button_NewGame()
{

}
button_NewGame::button_NewGame(sf::Vector2f pos)
{
	//setting the pictur for the window and from picture
	m_sprite.setTexture(m_Texture);
	m_sprite.setTextureRect(sf::IntRect(pos.x, pos.y, 350, 50));
	m_sprite.setPosition(180, 360);
	m_sprite.setColor(sf::Color(85, 40, 40, 223));
	//
	m_button_on.setTexture(m_Texture);
	m_button_on.setTextureRect(sf::IntRect(pos.x, (pos.y + 50), 350, 50));
	m_button_on.setPosition(180, 367);
	m_button_before = m_sprite;
}

void button_NewGame::ClickOn(sf::Vector2f pos, sf::RenderWindow &window)
{
	if (!m_sprite.getGlobalBounds().contains(pos))
		return;
	SetMyDifficultyLevelText();
	ChooseDifficultyLevel(window);
	window.close();//close the window
	std::cout << "new game\n"; //open the level
	//open window
	if (m_RangeOfDifLevl.x!=0 || m_RangeOfDifLevl.y!=0)
	Controller(m_RangeOfDifLevl.x,m_RangeOfDifLevl.y);
}

button_NewGame::~button_NewGame()
{
}

void button_NewGame::SetMyDifficultyLevelText()
{
	//****************************************************
	m_font.loadFromFile("myfont.ttf");
	//***set Text for EASY********************************
	m_text_esay.setFont(m_font);
	m_text_esay.setCharacterSize(SIZE_TEXT);
	m_text_esay.setFillColor(sf::Color::Magenta);
	m_text_esay.setOutlineThickness(2);
	m_text_esay.setOutlineColor(sf::Color::White);
	m_text_esay.setStyle(sf::Text::Bold);
	m_text_esay.setPosition(250, 200);
	m_text_esay.setString(" EASY ");
	//******************************************************

	//***set Text for medium***************************
	m_text_medium.setFont(m_font);
	m_text_medium.setCharacterSize(SIZE_TEXT);
	m_text_medium.setFillColor(sf::Color::Red);
	m_text_medium.setOutlineThickness(2);
	m_text_medium.setOutlineColor(sf::Color::White);
	m_text_medium.setStyle(sf::Text::Bold);
	m_text_medium.setPosition(250, 300);
	m_text_medium.setString(" medium ");
	//*******************************************************
	//***set Text for hard************
	m_text_hard.setFont(m_font);
	m_text_hard.setCharacterSize(SIZE_TEXT);
	m_text_hard.setFillColor(sf::Color::Cyan);
	m_text_hard.setOutlineThickness(2);
	m_text_hard.setOutlineColor(sf::Color::White);
	m_text_hard.setStyle(sf::Text::Bold);
	m_text_hard.setPosition(250, 400);
	m_text_hard.setString(" hard ");
	//*****************************************************
	m_MyDifLevl.push_back(m_text_esay);
	m_MyDifLevl.push_back(m_text_medium);
	m_MyDifLevl.push_back(m_text_hard);
	//*****************************************************
	m_MenuDifLevel.setTexture(Singleton::getInstance().GetTexture_MenuBackGround());
}
//*****************************************************
void button_NewGame::ChooseDifficultyLevel(sf::RenderWindow & window)
{
	/// loop for the user  chose the Difficulty of the game
	m_DokTex.loadFromFile("Untitled-4.png");
	m_DokSprite.setTexture(m_DokTex);
	bool ShowDok = false;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
			{
				for (size_t index = 0; index < m_MyDifLevl.size(); index++)
				{
				
					///the user can chose the Difficulty of the game
					if (m_MyDifLevl[index].getGlobalBounds().contains(event.mouseButton.x, (float)event.mouseButton.y))
					{
						switch (index)
						{
						case 0:
						{
							m_RangeOfDifLevl = EASY;
							window.close();
							return;
						}
						case 1:
						{

							m_RangeOfDifLevl = MEDIUM;
							window.close();
							return;
						}
						case 2:
						{
							m_RangeOfDifLevl = HARD;
							window.close();
							return;
						}
						default:break;
						}

					}

				}
				break;

			}
			case sf::Event::MouseMoved:
			{
				//show the dok photo
				for (size_t index = 0; index < m_MyDifLevl.size(); index++)
				{
					ShowDok = false;
					if (m_MyDifLevl[index].getGlobalBounds().contains((float)event.mouseMove.x,(float)event.mouseMove.y))
					{
						m_DokSprite.setPosition(m_MyDifLevl[index].getPosition().x-310, m_MyDifLevl[index].getPosition().y + 80);
						ShowDok = true;
						break;
					}

				}
			}
			default:break;
			}
		window.clear();//draw the menu object

		window.draw(m_MenuDifLevel);

		for (size_t i = 0; i < m_MyDifLevl.size(); ++i)
		{
			window.draw(m_MyDifLevl[i]);//draw the object of the menu 
		}
		if (ShowDok)
			window.draw(m_DokSprite);
		window.display();

	}


}

