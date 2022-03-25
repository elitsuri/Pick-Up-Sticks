#pragma once
#ifdef _DEBUG
#pragma comment(lib, "sfml-main-d.lib")
#pragma comment(lib, "sfml-system-d.lib")
#pragma comment(lib, "sfml-window-d.lib")
#pragma comment(lib, "sfml-graphics-d.lib")
#pragma comment(lib, "sfml-audio-d.lib")
#elif defined(NDEBUG)
#pragma comment(lib, "sfml-main.lib")
#pragma comment(lib, "sfml-system.lib")
#pragma comment(lib, "sfml-window.lib")
#pragma comment(lib, "sfml-graphics.lib")
#pragma comment(lib, "sfml-audio.lib")
#else
#error "Unrecognized configuration!"
#endif
#include <SFML\Graphics.hpp>
#include "buttton.h"
#include <memory>
class start_menu

{
public:
	start_menu();//c-tor set the buttton vector 
//The main function of the menu opens a window and manages it,
/// has a vector of buttons and thus the user selects what he wants or 
//start a new game or help or get out in addition to buttons are 
//polymorphisms that spawn them simple for loop vector only
	void MenuOpsion();

private:
	std::vector<std::unique_ptr<buttton>> m_but;//vector of the buttton
	bool m_GameOver;//
	sf::Sprite m_help;///the sprite of the help
	sf::Sprite m_menu;//the sprite of the menu
//=================================================
};

