#pragma once

#include "Dok.h"
#include <map>
#include<unordered_map>
class Doks
{
	
public:
	Doks();
	void SetGame(int RangeMin = 20, int RangeMax = 45);
	int IntRandom(int min, int max); //range : [min, max)
	void BuildListOfNeighbors();
	bool FindIfCut(const Dok& d1, const Dok& d2);
	bool AreTheyCut(const sf::Vector2f &p1, const sf::Vector2f &q1, const sf::Vector2f &p2,const sf::Vector2f &q2);
	bool onSegment(const sf::Vector2f &point1, const sf::Vector2f &point2, const sf::Vector2f &point3);
	int orientation(const sf::Vector2f &p, const sf::Vector2f &q, const sf::Vector2f &r);
	void RemoveToUnderMe(std::pair<float, Dok> ToDel);
	int FindClickOnDok( sf::RenderWindow & Windows, const sf::Vector2f& muose_buut);
	bool CanRemoveDok(std::pair<float, Dok>);
	//החזרת המפה הראשית
	std::unordered_map<int, Dok> GetDokVec()const { return m_AllDoks; };
	void DrawOnWin(sf::RenderWindow &window);
	//מחיזרה את מספר הדוקים שנשארו על הלוח
	int HowManyDoks() {return m_NumberOfDoks;};
		 
		
	~Doks();
private:
	int m_NumberOfDoks; //מספר הדוקים

	std::unordered_map<int, Dok> m_AllDoks;//מפה ממוינת דוקים מסודרים לפי אינדקיסים
	std::multimap<float,Dok>m_MapSortX;//מפה ממוינת דוקים מסודרים לפי איקסים

};

