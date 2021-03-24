#include "food.h"
#include"tools.h"
#include <cstdlib>
#include<iostream>

//绘制食物
void Food::DrawFood(Snake& Csnake)
{
	while (true)
	{
		int tmp_x = rand() % 28 + 2;
		int tmp_y = rand() % 28 + 2;
		bool flag = true;	//	判断生成的食物是否合理
		for (auto& p : Csnake.snake)
		{
			//生成的食物在蛇身上或和超级食物重叠
			if (p.GetX() == tmp_x && p.GetY() == tmp_y || (tmp_x == big_x && tmp_y == big_y))
			{
				flag = false;
				break;
			}
		}
		if (flag == false)//生成的食物在蛇身上，重新生成
		{
			continue;
		}
		x = tmp_x;
		y = tmp_y;
		SetCursorPosition(x, y);
		SetColor(13);
		std::cout << "★";

		++cnt;
		if (cnt % 5 == 0)//每吃五个生成一个超级食物
		{
			DrawSuperFood(Csnake);
		}
		break;
	}
	
}

//绘制超级食物
void Food::DrawSuperFood(Snake& Csnake)
{
	SetCursorPosition(5, 0);
	SetColor(11);
	std::cout << "------------------------------------------";//进度条
	super_progress = 42;
	while (true)
	{
		int tmp_x = rand() % 28 + 2;
		int tmp_y = rand() % 28 + 2;
		bool flag = true;	//	判断生成的食物是否合理
		for (auto& p : Csnake.snake)
		{
			//生成的食物在蛇身上或和超级食物重叠
			if (p.GetX() == tmp_x && p.GetY() == tmp_y || (tmp_x == big_x && tmp_y == big_y))
			{
				flag = false;
				break;
			}
		}
		if (flag == false)//生成的食物在蛇身上，重新生成
		{
			continue;
		}
		big_x = tmp_x;
		big_y = tmp_y;
		SetCursorPosition(big_x, big_y);
		SetColor(18);
		std::cout << "■";
		super_food = true;
		flash_flag = true;
		break;
		
	}
}



void Food::FlashSuperFood()
{
	SetCursorPosition(big_x, big_y);
	SetColor(18);
	//闪烁效果
	if (flash_flag)
	{
		std::cout << " ";
		flash_flag = false;
	}
	else
	{
		std::cout << "■";
		flash_flag = true;
	}

	SetCursorPosition(26, 0);
	SetColor(11);
	for (int i = 42; i >= super_progress; --i)
	{
		std::cout << "\b \b";
	}
	--super_progress;
	if (super_progress == 0)
	{
		SetCursorPosition(big_x, big_y);
		std::cout << "  ";
		super_food = false;
		big_x = 0;
		big_y = 0;
	}

}




int Food::GetProgressBar()const
{
	return super_progress;
}


