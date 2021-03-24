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

	//����ʼ�����ߴ�ӡ����
	void InitSnake();

	//�߳Ե�ʳ��ʱ���ƶ� snakeֻ���Ӳ�����
	void Move();

	//�������ƶ�
	void NormalMove();

	//�����߽�ײ���߽緵��false
	bool OverEdge();

	//�Ⲩ�� �������Լ� ײ���ͷ���false
	bool HitItself();

	bool ChangeDirection();

	bool GetFood(const Food&);

	bool GetSuperFood(Food&);

private:
	std::deque<Point> snake;
	Direction direction;
	friend class Food;	//���������˽�г�Ա
};

