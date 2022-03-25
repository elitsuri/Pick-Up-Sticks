#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
class Dok
{
//=======================================================================
public:
	Dok(int IndexInVec);
	Dok & operator=(const Dok& d1);
	sf::Color RandColor(int num);
	//החזרת מלבן הדוק
	sf::RectangleShape GetDokRec()const { return m_DokRec; };
	sf::Vector2f operator[](int index)const;
	//החזרת וקטור הנקודות של הדוק
	std::vector<sf::Vector2f> GetGlobalRec()const { return m_GlobalRec; };
	void InsetToAboveMe();
	void InsetToUnderMe(sf::Vector2f pos_dok);
	void RemoveToAboveMe();
	//החזרת וקטור הדוקים מתחתיי
	std::vector<sf::Vector2f> GetUnderMe()const { return m_UnderMe; }
	sf::Vector2f PopFromUnderMe ();
	bool ClickOn(const sf::RenderWindow & Windows);
	//החזרת מיקום הדוק במפה
	int GetIndexInVec()const {return m_IndexInVec;}
	//החזרת מספר הדוקים שמעליי
	int GetIfHaveDokOnMe() { return m_CounterAboveMe; };
	void SetPrintBool() ;
	//החזרת שווי הניקוד של הדוק
	int MyScore() { return m_Score; }
	~Dok() {};
//======================================================================
private:
	void SetGlobalRec(); 
	float FlotRandom(float min, float max); //מיקום הדוק
	sf::RectangleShape m_DokRec;//המלבן של הדוק
	sf::Color m_Color; //שמירת צבע של הדוק
	int m_IndexInVec;
	int m_CounterAboveMe; //קואנטור לדוקים מעליי
	std::vector<sf::Vector2f>m_UnderMe;//וטקטור דוקים מתחתיי
	std::vector<sf::Vector2f>m_GlobalRec;//וקטור נקודות של הדוק
	int m_Score;//ניקוד של הדוק

};
//==================================================================
bool operator==(const Dok& d1, const Dok& d2);
bool operator<(const Dok& d1, const Dok& d2);
