#include "Controller.h"
#include "Singleton.h"
const double TimeForDok = 1.1;//זמן עבור כל דוק כפול מספר הדוקים שווה להגבלת הזמן
const float SIZE_OFSCREN_X = 800;//גודל המסך
const float SIZE_OFSCREN_Y = 800;
Controller::Controller(int RangeMin, int RangeMax)
{

	m_TouchingOkSound.play();//music player
					  //*****************set background for the game game*****************
	m_GameBackGround.setTexture(Singleton::getInstance().GetTexture_BackGroundPlay());
	m_MyDoks.SetGame(RangeMin, RangeMax);
	//*****************call for the fuction that runs the game and check the resualt of the game win\lose*****************
	if (PlayNow())
	{
		//set msg
		m_SondFile.loadFromFile("Hall.ogg");
		m_TouchingOkSound.setBuffer(m_SondFile);
		if (m_MyScore.NewHigeScore())
			m_MessegeAfterGame = "    YOU    WIN \n NEW HIGE SCORE!";

		else
			m_MessegeAfterGame = "    YOU    WIN ";

	}
	else
	{
		m_SondFile.loadFromFile("Game Over.ogg");
		m_TouchingOkSound.setBuffer(m_SondFile);
		m_MessegeAfterGame = "YOU LOSE \n TIME OVER";
	}
	PrintAfterGame();//print the resualt

}
//========================================
bool Controller::PlayNow()
{
	//*****************set sound for the game*****************
	m_SondFile.loadFromFile("bleep.ogg");
	m_TouchingOkSound.setBuffer(m_SondFile);
	//*****************set sound for the game*****************
	m_SondFileForWorng.loadFromFile("Wrong.ogg");
	m_TouchingDontGoodSound.setBuffer(m_SondFileForWorng);
	//*****************open wndow for game*****************
	sf::RenderWindow window(sf::VideoMode(SIZE_OFSCREN_X, SIZE_OFSCREN_Y), "Tight GAMES!", sf::Style::Titlebar | sf::Style::Close);
	GameTime TimeGame(m_MyDoks.HowManyDoks()*TimeForDok);

	int score = 0;
	//****************loop for the game*****************
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				return false;
			case sf::Event::MouseButtonPressed: {
				score = 0;
				TimeGame.setTimeRun();///check the time of game
									  //*****************check if the gamer chose adok*****************
				score = m_MyDoks.FindClickOnDok(window, { float(event.mouseButton.x),float(event.mouseButton.y) });
				if (score != 0)
				{
					m_MyScore.SetScore(score);
					m_TouchingOkSound.play();
					//std::cout << "k= " << k << '\n'
				}

				else
					m_TouchingDontGoodSound.play();

				if (m_MyDoks.GetDokVec().size() == 0)
				{
					window.close();
					return true;
				}
				break;
			}
			{
			default:break;
			}
			}
		TimeGame.setTimeRun();//update the time
		if (TimeGame.GetEndTime()) //check if the time for this game end
			return false;
		//****************draw the object on the game*****************
		window.clear();//draw the menu object
		window.draw(m_GameBackGround);
		m_MyScore.print(window);
		TimeGame.print(window);
		m_MyDoks.DrawOnWin(window);
		window.display();
	}
	return true;
}
//========================================================================
void Controller::PrintAfterGame()
{
	m_TouchingOkSound.play();
	//*****************set the text to print after the game*****************
	sf::Font m_font;//font of the texr
	sf::Text m_text_WIN;//text timar
	m_font.loadFromFile("myfont.ttf");
	m_text_WIN.setFont(m_font);
	m_text_WIN.setCharacterSize(30);
	m_text_WIN.setFillColor(sf::Color::Black);
	m_text_WIN.setOutlineThickness(2);
	m_text_WIN.setOutlineColor(sf::Color::White);
	m_text_WIN.setStyle(sf::Text::Bold);
	m_text_WIN.setPosition(0, 0);
	m_text_WIN.setString(m_MessegeAfterGame);
	sf::RenderWindow window(sf::VideoMode(600, 200), "Tight GAMES!", sf::Style::Titlebar | sf::Style::Close);
	//*****************print the msg after game*****************
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

				{
			default:break;
				}
			}

		window.clear();//draw the menu object
		m_MyScore.print(window);
		window.draw(m_text_WIN);
		window.display();
	}



}
//========================================
Controller::~Controller()
{
}
