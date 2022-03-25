#include "Dok.h"
#include <iostream>
const int SIZE_DOK_X = 7; //���� ����� �� ����
const int SIZE_DOK_y = 120; //���� ����� �� ����
const int SIZE_DOK_Thicknes = 3; //���� ������ �� ����
const int NUMBER_MIN_COLOR = 0; // ���� ������ �� ����� �����
const int NUMBER_MAX_COLOR = 0;// ���� ������� �� ����� �����

//========================================================
//����������� �� ������ ������ ��� ����
//
Dok::Dok(int IndexInVec)
{
	//����� ������ ������ ���
	m_CounterAboveMe = 0;
	m_Color = RandColor(int(FlotRandom(0, 6)));//��� �����
	m_DokRec.setSize(sf::Vector2f(SIZE_DOK_X,SIZE_DOK_y)); //���� ����
	m_DokRec.setOutlineThickness(SIZE_DOK_Thicknes);
	//����� ������ ���� ����� ����� ����� ���� ����
	m_DokRec.setPosition(FlotRandom(120,570), FlotRandom(200,570)); 
	m_DokRec.setRotation(FlotRandom(0,180));// ���� ������ �� ����
	m_DokRec.setFillColor(m_Color);
	m_DokRec.setOutlineColor(sf::Color::Black);
	m_IndexInVec = IndexInVec;
	//����� ������ �� ����
	SetGlobalRec();

}
//========================================================
//������������ �� ����� ���
//����� �� ����� ����� �����
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
//�������� ������� ���� ������� ����� ������
//����� ���� ������ �������� ������� ���� �����
float Dok::FlotRandom(float min, float max)
{
	return min + rand() % int((max - min));
}
//========================================================
//������� ������ ��� ����� ����� ������ ������ ����� ����
//������ �� ���� ����
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
//(������� ������ ������ �� ����� ������ �� ����� (����)
void Dok::SetGlobalRec()
{
	sf::Vector2f  topLeft = m_DokRec.getTransform().transformPoint(sf::Vector2f(0, 0));//���� ������ ������
	sf::Vector2f   topRight = m_DokRec.getTransform().transformPoint(sf::Vector2f(m_DokRec.getSize().x, 0));//���� ����� ������
	sf::Vector2f  bottomLeft = m_DokRec.getTransform().transformPoint(sf::Vector2f(0, m_DokRec.getSize().y));//���� ������ ������
	sf::Vector2f   bottomRight = m_DokRec.getTransform().transformPoint(sf::Vector2f(m_DokRec.getSize().x, m_DokRec.getSize().y));//���� ����� ������
	//����� ������� ������ �� �������
	m_GlobalRec.push_back(topLeft);
	m_GlobalRec.push_back(topRight);
	m_GlobalRec.push_back(bottomLeft);
	m_GlobalRec.push_back(bottomRight);
}
//========================================================
//������� ������ �� ���� ������ ���� ����
//
void Dok::InsetToAboveMe()
{
	m_CounterAboveMe++;
}
//========================================================
//������� ������ ������ �� ������ ������� ���� ����
//��� ���� ����� ������ ����� ���� �� ����
void Dok::InsetToUnderMe(sf::Vector2f pos_dok)
{
	m_UnderMe.push_back(pos_dok);
}
//============================================================
//������� ������� �� ������ �� ������ ����� �1
//========================================================
void Dok::RemoveToAboveMe()
{
	m_CounterAboveMe--;
}
//========================================================
//������� ����� �� ����� ���� ��� ��� ����� ���� �����
sf::Vector2f Dok::PopFromUnderMe()
{	
	sf::Vector2f temp;
	temp.x = m_UnderMe[m_UnderMe.size() - 1].x;
	temp.y = m_UnderMe[m_UnderMe.size() - 1].y;
		m_UnderMe.erase(m_UnderMe.begin()+ m_UnderMe.size() - 1);
		return temp;
}
//========================================================
//������� ����� �� ���� ��� ����� ���
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
//������� ������ ��� ��� ����� �� �� ����
//����� �� �� �� ��� �� ��
bool operator==(const Dok & d1, const Dok & d2)
{
	if (&d1 == &d2)
		return true;
	return false;
}
//������� ������ ���� ��� ���� "���" �� ���� �-����  
//========================================================
bool operator<(const Dok & d1, const Dok & d2)
{
	if (d1.GetDokRec().getPosition().x < d2.GetDokRec().getPosition().x)
		return true;
	return false;
}
//========================================================