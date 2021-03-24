#include "snake.h"
#include<conio.h>
#include"tools.h"
#include<iostream>



using namespace std;


Snake::Snake()
{
	snake.emplace_back(14, 8);
	snake.emplace_back(15, 8);
	snake.emplace_back(16, 8);
	direction = Direction::DOWN;
}

//����ʼ�����ߴ�ӡ����
void Snake::InitSnake()
{
	SetColor(5);
	for (auto& point : snake)
	{		
		if (point == snake.back())//����ͷ��Ϊ��ͬ��ɫ
		{
			SetColor(4);
		}
		point.PrintCircular();
	}
		
}

//�߳Ե�ʳ��ʱ���ƶ� snakeֻ���Ӳ�����
void Snake::Move()
{
	//��ʱ�ɵ���ͷ��Ϊ����Ҫ�Ƚ�������ɫ��Ϊ����
	SetColor(5);
	snake.back().PrintCircular();
	switch (direction)
	{
	case Direction::UP:
	{
		snake.emplace_back(snake.back().GetX(), snake.back().GetY() - 1);
		break;
	}
	case Direction::DOWN:
	{
		snake.emplace_back(Point(snake.back().GetX(), snake.back().GetY() + 1));
		break;
	}
	case Direction::LEFT:
	{
		snake.emplace_back(Point(snake.back().GetX() - 1, snake.back().GetY()));
		break;

	}
	case Direction::RIGHT:
	{
		snake.emplace_back(Point(snake.back().GetX() + 1, snake.back().GetY()));
		break;
	}
	default:
		break;
	}
	//����ͷ��Ϊ��ɫ4
	SetColor(4);
	snake.back().PrintCircular();
	
}

//�ڳԵ�ʳ���Ƶ��Ļ�����ȥ����β��Ҳ����deque������front
void Snake::NormalMove()
{
	Move();
	snake.front().Clear();
	snake.pop_front();

}


//ײ���߽緵��false
bool Snake::OverEdge()
{
	return snake.back().GetX() < 30 &&
		snake.back().GetY() < 30 &&
		snake.back().GetX() > 1 &&
		snake.back().GetY() > 1;
}

bool Snake::HitItself()
{
	//�˴�������range for ��Ϊ��ȡ�����һ��Ԫ�� �ж�һ��ʧ��
	for (int i = 0; i < snake.size() - 1; i++)
	{
		if (snake[i] == snake.back())
			return false;
	}
	return true;
}

bool Snake::ChangeDirection()//�ı䷽��,�������ESC������false
{
	char ch;
	if (_kbhit())//kbhit������鵱ǰ�Ƿ��м�������
	{
		ch = _getch();//�ӿ���̨��ȡһ���ַ���������ʾ����Ļ�ϣ�����ͷ�ļ�conio.h
		switch (ch)
		{

		case 119:
			if (direction != Direction::DOWN)//����������˶������෴����Ч
				direction = Direction::UP;
			break;
		case 115:
			if (direction != Direction::UP)
				direction = Direction::DOWN;
			break;
		case 97:
			if (direction != Direction::RIGHT)
				direction = Direction::LEFT;
			break;
		case 100:
			if (direction != Direction::LEFT)
				direction = Direction::RIGHT;
			break;


		case 27:
			return false;
		default:
			return true;
		}
	}
	return true;

}

bool Snake::GetSuperFood(Food& cfood)
{
	if (snake.back().GetX() == cfood.big_x && snake.back().GetY() == cfood.big_y)
	{
		cfood.super_food = false;
		cfood.big_x = 0;
		cfood.big_y = 0;
		SetCursorPosition(1, 0);
		cout << "                                                            ";
		return true;
	}
	else
		return false;
}

bool Snake::GetFood(const Food& cfood)
{
	if (snake.back().GetX() == cfood.x && snake.back().GetY() == cfood.y)
		return true;
	else
		return false;
}



