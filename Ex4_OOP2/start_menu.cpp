#include "start_menu.h"
#include "button_EXIT.h"
#include "button_help.h"
#include "button_NewGame.h"
const float SIZE_OFSCREN_X = 800;
const float SIZE_OFSCREN_Y = 800;
start_menu::start_menu()//c-tor defalot set the buttton vecotr
{
	//set pos for all the button
	sf::Vector2f pos{ 50,0 };
	m_but.push_back(std::make_unique<button_NewGame>(pos));//set the button_NewGame
	pos.y += 100;
	m_but.push_back(std::make_unique<button_help>(pos));//set the button_help
	pos.y += 100;
	m_but.push_back(std::make_unique<button_EXIT>(pos));//set the button_EXIT

	
	 //set the siprte of the menu
	m_menu.setTexture(Singleton::getInstance().GetTexture_MenuBackGround());

	MenuOpsion();//main func Director of the menu display and operation
}
//===============================================================
void start_menu::MenuOpsion()
{
	//The main function of the menu opens a window and manages it,
	/// has a vector of buttons and thus the user selects what he wants or 
	//start a new game or help or get out in addition to buttons are 
	//polymorphisms that spawn them simple for loop vector only
	sf::RenderWindow window(sf::VideoMode(SIZE_OFSCREN_X, SIZE_OFSCREN_Y), "Tight GAMES!", sf::Style::Titlebar | sf::Style::Close);

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

				for (size_t i = 0; i < m_but.size(); ++i)
				{
					//First loop, going through all the buttons and triggers the one on 
					//which the user clicked works according to the principle Hfolimorfizim
					m_but[i]->ClickOn({ (float)event.mouseButton.x,(float)event.mouseButton.y }, window);
				}
			}
			case sf::Event::MouseMoved:
			{

				for (size_t i = 0; i < m_but.size(); ++i)
				{
					//change the photo of the of the Button
					m_but[i]->MoveOn({ (float)event.mouseMove.x,(float)event.mouseMove.y });
				}
				break;
			}
			default:break;
			}

		window.clear();//draw the menu object
		window.draw(m_menu);
		for (size_t i = 0; i < m_but.size(); ++i)
		{
			m_but[i]->Draw(window);//draw the object of the menu 
		}

		window.display();
	}

}