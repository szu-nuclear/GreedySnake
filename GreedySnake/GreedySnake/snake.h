#pragma once
#include <deque>
#include "point.h"
#include "food.h"
class Food;

class Snake
{
public:
	enum Direction{UP,DOWN,LEFT,RIGHT};

	Snake();

	//将初始化的蛇打印出来
	void InitSnake();

	//蛇吃到食物时的移动 snake只增加不减少
	void Move();

	//蛇正常移动
	void NormalMove();

	//超过边界撞到边界返回false
	bool OverEdge();

	//这波啊 是碰到自己 撞到就返回false
	bool HitItself();

	bool ChangeDirection();

	bool GetFood(const Food&);

	bool GetSuperFood(Food&);

private:
	std::deque<Point> snake;
	Direction direction;
	friend class Food;	//方便访问其私有成员
};

