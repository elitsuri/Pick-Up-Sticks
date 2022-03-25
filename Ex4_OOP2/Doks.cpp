#include "Doks.h"
#include <time.h> 
#include <iostream>
#include <algorithm>
const int RangeOfDok = 120;//טווח של בדיקת כל דוק
enum { topLeft = 0, topRight = 1, bottomLeft = 2, bottomRight = 3 };

//========================================================
Doks::Doks()
{

}
// פונקציה שבונה את הדוק למשחק
void Doks::SetGame(int RangeMin, int RangeMax)
{
	srand(time(NULL)); // הפעלת מחולל מספרים
	m_NumberOfDoks = IntRandom(RangeMin, RangeMax); //מספר הדוקים על הלוח שולח טווח
	//לולאה ליצירת המבנה נתונים בונה ומכניס את הדוקים ךלשני מפות
	for (int i = 0; i < m_NumberOfDoks; i++)
	{
		
		m_AllDoks.insert(std::make_pair(i,Dok(i))); //הכנסת דוק עם מפתח ממוין לפי אינדקס
		m_MapSortX.insert(std::make_pair(m_AllDoks.find(i)._Ptr->_Myval.second.GetDokRec().getPosition().x,//הכנסת דוק עם מפתח ממויין לפי איקס
			m_AllDoks.find(i)._Ptr->_Myval.second));//חיפוש הדוק
	}
	BuildListOfNeighbors();// בניית רשימת "שכני"ם
}
//========================================================
//טווח מספר הדוקים שעל הלוח
int Doks::IntRandom(int min, int max)
{
	return min + rand() % (max - min);
}
//========================================================
// פונקציה לבניית רשימת הכשנים ש ל הדוקים
void Doks::BuildListOfNeighbors()
{
	//לעבור על כל הדוקים
	for (auto dok = m_MapSortX.begin(); dok != m_MapSortX.end(); dok++)
	{
		//זיהוי הדוקים שמסביבי בטווח גודל הדוק
		auto min_range_dok = m_MapSortX.lower_bound(dok._Ptr->_Myval.first - RangeOfDok);
		auto max_range_dok = m_MapSortX.upper_bound(dok._Ptr->_Myval.first + RangeOfDok);
		//עבור על כל מה שמצאנו
		while (min_range_dok != max_range_dok)
		{
			//אם הדוק לא שווה לעצמו
			if (dok != min_range_dok)
			{
				//אם מצאנו חיתוך בין שני דוקים
				if (FindIfCut(dok._Ptr->_Myval.second, min_range_dok._Ptr->_Myval.second))
				{
					//נבדוק איזה דוק מעל מי
					if (dok._Ptr->_Myval.second.GetIndexInVec() > min_range_dok._Ptr->_Myval.second.GetIndexInVec())
					{
					//נכניס דוק לרשימה שתמתתיו
						dok._Ptr->_Myval.second.InsetToUnderMe(min_range_dok._Ptr->_Myval.second.GetDokRec().getPosition());
						//ודוק שני לרשימה שמעליו (מעלים תקונטר)
						min_range_dok._Ptr->_Myval.second.InsetToAboveMe();
					}

				}
			}
			min_range_dok++;
		}
	}
}
//========================================================
//פונקציה שבודקת אם שני דוקים נחתכים
//שוליים את הנקודות שבסוף הישרים
bool Doks::FindIfCut(const Dok & d1, const Dok & d2)
{
	//בדיקת חיתוכים
	if (AreTheyCut(d1.GetGlobalRec()[bottomLeft], d1.GetGlobalRec()[topLeft], d2.GetGlobalRec()[topRight], d2.GetGlobalRec()[bottomRight]))
	{
		return true;
	}
	if (AreTheyCut(d1.GetGlobalRec()[topRight], d1.GetGlobalRec()[bottomRight], d2.GetGlobalRec()[topRight], d2.GetGlobalRec()[bottomRight]))
	{
		return true;
	}
	if (AreTheyCut(d1.GetGlobalRec()[bottomLeft], d1.GetGlobalRec()[bottomRight], d2.GetGlobalRec()[topRight], d2.GetGlobalRec()[bottomRight]))
	{
		return true;
	}
	if (AreTheyCut(d1.GetGlobalRec()[bottomLeft], d1.GetGlobalRec()[topLeft], d2.GetGlobalRec()[topRight], d2.GetGlobalRec()[bottomRight]))
	{
		return true;
	}
	//===================================================================
	if (AreTheyCut(d1.GetGlobalRec()[topRight], d1.GetGlobalRec()[topLeft], d2.GetGlobalRec()[topLeft], d2.GetGlobalRec()[bottomLeft]))
	{
		return true;
	}
	if (AreTheyCut(d1.GetGlobalRec()[topRight], d1.GetGlobalRec()[bottomRight], d2.GetGlobalRec()[topLeft], d2.GetGlobalRec()[bottomLeft]))
	{

		return true;
	}
	if (AreTheyCut(d1.GetGlobalRec()[bottomLeft], d1.GetGlobalRec()[bottomRight], d2.GetGlobalRec()[topLeft], d2.GetGlobalRec()[bottomLeft]))
	{

		return true;
	}
	if (AreTheyCut(d1.GetGlobalRec()[bottomLeft], d1.GetGlobalRec()[topLeft], d2.GetGlobalRec()[topLeft], d2.GetGlobalRec()[bottomLeft]))
	{
		return true;
	}
	return false;
}
//========================================================
//פונקציה לחתיוכים
bool Doks::AreTheyCut(const sf::Vector2f &p1, const sf::Vector2f &q1, const sf::Vector2f &p2, const sf::Vector2f &q2)
{
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);

	// General case
	if (o1 != o2 && o3 != o4)
		return true;

	// Special Cases
	// p1, q1 and p2 are colinear and p2 lies on segment p1q1
	if (o1 == 0 && onSegment(p1, p2, q1)) return true;

	// p1, q1 and p2 are colinear and q2 lies on segment p1q1
	if (o2 == 0 && onSegment(p1, q2, q1)) return true;

	// p2, q2 and p1 are colinear and p1 lies on segment p2q2
	if (o3 == 0 && onSegment(p2, p1, q2)) return true;

	// p2, q2 and q1 are colinear and q1 lies on segment p2q2
	if (o4 == 0 && onSegment(p2, q1, q2)) return true;

	return false; // Doesn't fall in any of the above cases
}
//========================================================
bool Doks::onSegment(const sf::Vector2f &p, const sf::Vector2f &q, const sf::Vector2f &r)
{
	if (q.x <= fmax(p.x, r.x) && q.x >= fmin(p.x, r.x) &&
		q.y <= fmax(p.y, r.y) && q.y >= fmin(p.y, r.y))
		return true;

	return false;
}
//========================================================
int Doks::orientation(const sf::Vector2f & p, const sf::Vector2f & q, const sf::Vector2f & r)
{
	int val = (q.y - p.y) * (r.x - q.x) -
		(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0;  // colinear

	return (val > 0) ? 1 : 2; // clock or counterclock wise
}
//========================================================
//מחיקת הדוקים שמתחתי להודיע לכל הדוקים שמתחתיי
void Doks::RemoveToUnderMe(std::pair<float, Dok> ToDel)
{
	std::map<float, Dok>::iterator it;
	//לעבור על כל הרשימה שמתחתיי הדוקים
	while (ToDel.second.GetUnderMe().size() != 0)
	{
		//מחיקת הדוק ושמירת נתנויו
		sf::Vector2f ToCheck = ToDel.second.PopFromUnderMe();
		it = m_MapSortX.find(ToCheck.x);
		//אם מצאנו את הדוק שאנו רוצים למחוק
		while (it != m_MapSortX.end())
		{
			if (it._Ptr->_Myval.second.GetDokRec().getPosition() == ToCheck)
			{
				//תעבור על כל הרשימה ותוייע לאלה שתמתחיו שימחקו פחות אחד בקאונטר
				it._Ptr->_Myval.second.RemoveToAboveMe();
				break;
			}
			it++;
		}
	}

}
//========================================================
//פונקציה שמוצאת איזה דוק לחץ השחקן
int Doks::FindClickOnDok(sf::RenderWindow & Windows, const sf::Vector2f& muose_buut)
{
	int score=0;
	auto min_range_dok = m_MapSortX.lower_bound(muose_buut.x - RangeOfDok);
	auto max_range_dok = m_MapSortX.upper_bound(muose_buut.x + RangeOfDok);
	while (min_range_dok != max_range_dok)
	{

		if (min_range_dok._Ptr->_Myval.second.ClickOn(Windows))
		{
			if (CanRemoveDok(min_range_dok._Ptr->_Myval))
			{
				//לעלות את הניקוד בהתאם לדוק הנמצא
				score = min_range_dok._Ptr->_Myval.second.MyScore();
				//מחיקת הדוק
				m_AllDoks.erase(m_AllDoks.find(min_range_dok._Ptr->_Myval.second.GetIndexInVec()));
				m_MapSortX.erase(min_range_dok);
				return score;
			}
		}
		min_range_dok++;
	}
	return score;
}
//========================================================
//פונקציה שמגיעים אליה אם אפשר למחוק את הדוק
bool Doks::CanRemoveDok(std::pair<float, Dok> ToDel)
{
	//אם אין אף דוק מעליי
	if (ToDel.second.GetIfHaveDokOnMe() == 0)
	{
		//מחיקת הדוק
		RemoveToUnderMe(ToDel);


		return true;
	}
	return false;
}
//========================================================
//פונקציה לציור הדוקים
void Doks::DrawOnWin(sf::RenderWindow & window)
{
	for (auto i = m_AllDoks.begin(); i != m_AllDoks.end(); i++)
	{
		window.draw(i._Ptr->_Myval.second.GetDokRec());
	}
}
Doks::~Doks()
{
}
//========================================================

