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

//将初始化的蛇打印出来
void Snake::InitSnake()
{
	SetColor(5);
	for (auto& point : snake)
	{		
		if (point == snake.back())//将蛇头置为不同颜色
		{
			SetColor(4);
		}
		point.PrintCircular();
	}
		
}

//蛇吃到食物时的移动 snake只增加不减少
void Snake::Move()
{
	//此时旧的蛇头成为蛇身，要先将他的颜色改为蛇身
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
	//将蛇头置为颜色4
	SetColor(4);
	snake.back().PrintCircular();
	
}

//在吃到食物移到的基础上去掉蛇尾，也就是deque容器的front
void Snake::NormalMove()
{
	Move();
	snake.front().Clear();
	snake.pop_front();

}


//撞到边界返回false
bool Snake::OverEdge()
{
	return snake.back().GetX() < 30 &&
		snake.back().GetY() < 30 &&
		snake.back().GetX() > 1 &&
		snake.back().GetY() > 1;
}

bool Snake::HitItself()
{
	//此处不能用range for 因为会取到最后一个元素 判定一定失败
	for (int i = 0; i < snake.size() - 1; i++)
	{
		if (snake[i] == snake.back())
			return false;
	}
	return true;
}

bool Snake::ChangeDirection()//改变方向,如果按下ESC键返回false
{
	char ch;
	if (_kbhit())//kbhit函数检查当前是否有键盘输入
	{
		ch = _getch();//从控制台读取一个字符，但不显示在屏幕上，所在头文件conio.h
		switch (ch)
		{

		case 119:
			if (direction != Direction::DOWN)//如果方向与运动方形相反，无效
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



