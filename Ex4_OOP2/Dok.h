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
	//����� ���� ����
	sf::RectangleShape GetDokRec()const { return m_DokRec; };
	sf::Vector2f operator[](int index)const;
	//����� ����� ������� �� ����
	std::vector<sf::Vector2f> GetGlobalRec()const { return m_GlobalRec; };
	void InsetToAboveMe();
	void InsetToUnderMe(sf::Vector2f pos_dok);
	void RemoveToAboveMe();
	//����� ����� ������ ������
	std::vector<sf::Vector2f> GetUnderMe()const { return m_UnderMe; }
	sf::Vector2f PopFromUnderMe ();
	bool ClickOn(const sf::RenderWindow & Windows);
	//����� ����� ���� ����
	int GetIndexInVec()const {return m_IndexInVec;}
	//����� ���� ������ ������
	int GetIfHaveDokOnMe() { return m_CounterAboveMe; };
	void SetPrintBool() ;
	//����� ���� ������ �� ����
	int MyScore() { return m_Score; }
	~Dok() {};
//======================================================================
private:
	void SetGlobalRec(); 
	float FlotRandom(float min, float max); //����� ����
	sf::RectangleShape m_DokRec;//����� �� ����
	sf::Color m_Color; //����� ��� �� ����
	int m_IndexInVec;
	int m_CounterAboveMe; //������� ������ �����
	std::vector<sf::Vector2f>m_UnderMe;//������ ����� ������
	std::vector<sf::Vector2f>m_GlobalRec;//����� ������ �� ����
	int m_Score;//����� �� ����

};
//==================================================================
bool operator==(const Dok& d1, const Dok& d2);
bool operator<(const Dok& d1, const Dok& d2);
