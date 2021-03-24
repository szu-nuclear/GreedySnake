#pragma once

class Point
{
public:
	Point() = default;
	Point(const int x,const int y):m_x(x), m_y(y){}

	void Print();
	void PrintCircular();
	void Clear();
	void ChangePosition(const int x, const int y);

	bool operator== (const Point& point) {
		return (point.m_x == this->m_x) && (point.m_y == this->m_y);
	}

	int GetX() const { return this->m_x; }
	int GetY() const{ return this->m_y; }
	
private:
	int m_x;
	int m_y;
};

