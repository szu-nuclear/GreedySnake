#pragma once
#include"snake.h"
class Snake;
class Food
{
public:
	Food() : cnt(0), flash_flag(false), super_food(false), x(0), y(0), big_x(0), big_y(0), super_progress(0) {}
	void DrawFood(Snake& s);
	void DrawSuperFood(Snake&);
	int GetCnt ()const;
	void FlashSuperFood();
	bool GetSuperFlag()const;
	int GetProgressBar()const;
	

private:
	int cnt;
	bool flash_flag;	//��˸���
	bool super_food;	//����ʳ��
	int x, y;
	int big_x, big_y;
	int super_progress;	//����ʳ�������
	friend class Snake;
};

inline bool Food::GetSuperFlag() const
{
	return this->super_food;
}


inline int Food::GetCnt()const
{
	return cnt;
}
