#include "point.h"
#include "tools.h"
#include <iostream>

void Point::Print()//�������
{
	SetCursorPosition(m_x, m_y);
	std::cout << "��";
}

void Point::PrintCircular()//���Բ��
{
	SetCursorPosition(m_x, m_y);
	std::cout << "��";
}

void Point::Clear()//������
{
	SetCursorPosition(m_x, m_y);
	std::cout << "  ";
}

void Point::ChangePosition(const int x, const int y)
{
	this->m_x = x;
	this->m_y = y;
}


