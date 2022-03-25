#include "Dok.h"
#include <iostream>
const int SIZE_DOK_X = 7; //גודל הרוחב של הדוק
const int SIZE_DOK_y = 120; //גודל האורך של הדוק
const int SIZE_DOK_Thicknes = 3; //גודל המסגרת של הדוק
const int NUMBER_MIN_COLOR = 0; // גודל מינמלי של הצבעי דוקים
const int NUMBER_MAX_COLOR = 0;// גודל מקסימלי של הצבעי דוקים

//========================================================
//הקונסרטקטור של המחלקה לבניית דוק יחיד
//
Dok::Dok(int IndexInVec)
{
	//איפוס נתונים ויצירת דוק
	m_CounterAboveMe = 0;
	m_Color = RandColor(int(FlotRandom(0, 6)));//צבע אקראי
	m_DokRec.setSize(sf::Vector2f(SIZE_DOK_X,SIZE_DOK_y)); //גודל הדוק
	m_DokRec.setOutlineThickness(SIZE_DOK_Thicknes);
	//מיקום הדוקים בלוח באופן אקראי בטווח ביחס למסך
	m_DokRec.setPosition(FlotRandom(120,570), FlotRandom(200,570)); 
	m_DokRec.setRotation(FlotRandom(0,180));// גודל הסיבוב של הדוק
	m_DokRec.setFillColor(m_Color);
	m_DokRec.setOutlineColor(sf::Color::Black);
	m_IndexInVec = IndexInVec;
	//שמירת נתנוים על הדוק
	SetGlobalRec();

}
//========================================================
//קופיקונרקטור של מחלקת דוק
//מעתיק את השדות העתקה עמוקה
Dok & Dok::operator=(const Dok & d1)
{
	m_CounterAboveMe = d1.m_CounterAboveMe;
	m_Color = d1.m_Color;
	m_DokRec.setSize(sf::Vector2f(SIZE_DOK_X, SIZE_DOK_y));
	m_DokRec.setOutlineThickness(SIZE_DOK_Thicknes);
	m_DokRec = d1.m_DokRec;

	m_IndexInVec = d1.m_IndexInVec;
	m_GlobalRec = d1.m_GlobalRec;
	return *this;
}
//========================================================
//פונקצייה שמגרילה מספר רנדומלי בטווח מסויים
//מקבלת מספר מינמלי ומקסימלי ומגרילה מספר בינהם
float Dok::FlotRandom(float min, float max)
{
	return min + rand() % int((max - min));
}
//========================================================
//פונקציה לבחירת צבע בהתאם למספר שמקבלת וניקוד מתאים לצבע
//מחזירה את הצבע לדוק
sf::Color Dok::RandColor(int num)
{
	switch (num)
	{
	case 0:
	{
		m_Score = 20;
		return sf::Color::Red;
		break;
	}
	case 1:
	{
		m_Score = 12;
		return sf::Color::Green;
		break;
	}
	case 2:
	{
		m_Score = 15;
		return sf::Color::Blue;
		break;
	}
	case 3:
	{
		m_Score = 17;
		return sf::Color::Cyan;
		break;
	}
	case 4:
	{
		m_Score = 9;
		return sf::Color::Yellow;
		break;
	}
	case 5:
	{
		m_Score = 30;
		return sf::Color::Magenta;
		break;
	}
	default:
		break;
	}
	return sf::Color();
}
//======================================================================================================
//(פונקציה ששומרת בוקטור את מיקום הפיונת של המלבן (הדוק)
void Dok::SetGlobalRec()
{
	sf::Vector2f  topLeft = m_DokRec.getTransform().transformPoint(sf::Vector2f(0, 0));//פינה שמאלית עליונה
	sf::Vector2f   topRight = m_DokRec.getTransform().transformPoint(sf::Vector2f(m_DokRec.getSize().x, 0));//פינה ימנית עליונה
	sf::Vector2f  bottomLeft = m_DokRec.getTransform().transformPoint(sf::Vector2f(0, m_DokRec.getSize().y));//פינה שמאלית תחתונה
	sf::Vector2f   bottomRight = m_DokRec.getTransform().transformPoint(sf::Vector2f(m_DokRec.getSize().x, m_DokRec.getSize().y));//פינה ימנית תחתונה
	//הכנסת הנקודות לוקטור של הפרייבט
	m_GlobalRec.push_back(topLeft);
	m_GlobalRec.push_back(topRight);
	m_GlobalRec.push_back(bottomLeft);
	m_GlobalRec.push_back(bottomRight);
}
//========================================================
//פונקציה שסופרת את מספר הדוקים שמעל הדוק
//
void Dok::InsetToAboveMe()
{
	m_CounterAboveMe++;
}
//========================================================
//פונקציה ששומרת בוקטור את הדוקים שנמצאים מתחת לדוק
//כדי לגשת אליהם והודיע אליהם שדוק זה נמחק
void Dok::InsetToUnderMe(sf::Vector2f pos_dok)
{
	m_UnderMe.push_back(pos_dok);
}
//============================================================
//פונקציה שמורידה את הקנטאר של הדוקים מעליי ב1
//========================================================
void Dok::RemoveToAboveMe()
{
	m_CounterAboveMe--;
}
//========================================================
//פונקציה שומרת את מיקום הדוק שלי ואז מוחקת אותו מהמפה
sf::Vector2f Dok::PopFromUnderMe()
{	
	sf::Vector2f temp;
	temp.x = m_UnderMe[m_UnderMe.size() - 1].x;
	temp.y = m_UnderMe[m_UnderMe.size() - 1].y;
		m_UnderMe.erase(m_UnderMe.begin()+ m_UnderMe.size() - 1);
		return temp;
}
//========================================================
//פונקציה שמזהה על איזה דוק השחקן לחץ
//
bool Dok::ClickOn(const sf::RenderWindow & Windows)
{
	const sf::Vector2f mappedMousePosition = Windows.mapPixelToCoords(sf::Mouse::getPosition(Windows));
	const sf::Vector2f transformedMousePosition = m_DokRec.getInverseTransform().transformPoint(mappedMousePosition);
	if (m_DokRec.getLocalBounds().contains(transformedMousePosition))
		return true;
	return false;
}
//========================================================
//אופרטור שמשווה בין שני דוקים אם הם זהים
//מחזיר כן אם כן ולא אם לא
bool operator==(const Dok & d1, const Dok & d2)
{
	if (&d1 == &d2)
		return true;
	return false;
}
//פונקציה שבודקת איזה דוק נמצא "מעל" מי ביחס ל-איקס  
//========================================================
bool operator<(const Dok & d1, const Dok & d2)
{
	if (d1.GetDokRec().getPosition().x < d2.GetDokRec().getPosition().x)
		return true;
	return false;
}
//========================================================