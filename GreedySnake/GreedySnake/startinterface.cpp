#include "startinterface.h"
#include<windows.h>



void StartInterface::PrintFirst()//蛇从左边出现到完全出现的过程
{
	for (auto& p : startsnake)
	{
		p.Print();
		Sleep(m_speed);//挂起一段时间
	}
}

void StartInterface::PrintSecond()//蛇从左向右移动的过程
{
    
    for (int i = 10; i != 40; ++i) //蛇头需要从10移动到40
    {
        /*计算蛇头的下一个位置，并将其压入startsnake中，绘制出来，将蛇尾去掉*/
        int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);       
        startsnake.emplace_back(Point(i, j));
        startsnake.back().Print();
        startsnake.front().Clear();
        startsnake.pop_front();
        Sleep(m_speed);
    }
   }

void StartInterface::PrintThird()
{
    while (!startsnake.empty() || textsnake.back().GetX() < 33)//当蛇还没消失或文字没移动到指定位置
    {
        if (!startsnake.empty()) //如果蛇还没消失，继续移动
        {
            startsnake.front().Clear();
            startsnake.pop_front();
        }
        

        ClearText();//清除已有文字
        PrintText();//绘制更新位置后的文字
        Sleep(m_speed);
    }
    
}

void StartInterface::PrintText()
{
    for ( auto& t : textsnake)
    {
        if (t.GetX() > 0)
        {
            
            t.Print();
        }
        
    }
}

void StartInterface::ClearText()
{
    for (auto& point : textsnake) 
    {
        if (point.GetX() >= 0)//清除
        {
            point.Clear();
        }
        //将文字整体向右移动一格         
        point.ChangePosition(point.GetX()+1 , point.GetY());
    }
}


void StartInterface::Action ()
{
    PrintFirst();
    PrintSecond();
    PrintThird();
}
