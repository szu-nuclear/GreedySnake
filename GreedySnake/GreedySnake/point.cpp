#include "point.h"
#include "tools.h"
#include <iostream>

void Point::Print()//输出方块
{
	SetCursorPosition(m_x, m_y);
	std::cout << "■";
}

void Point::PrintCircular()//输出圆形
{
	SetCursorPosition(m_x, m_y);
	std::cout << "●";
}

void Point::Clear()//清除输出
{
	SetCursorPosition(m_x, m_y);
	std::cout << "  ";
}

void Point::ChangePosition(const int x, const int y)
{
	this->m_x = x;
	this->m_y = y;
}


