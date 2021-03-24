#pragma once
#include <vector>
#include<deque>
#include"point.h"
using namespace std;

class StartInterface
{
public:
        StartInterface() :m_speed(35)
        {
        //蛇初始化
        startsnake.emplace_back(Point(0, 14));
        startsnake.emplace_back(Point(1, 14));
        startsnake.emplace_back(Point(2, 15));
        startsnake.emplace_back(Point(3, 16));
        startsnake.emplace_back(Point(4, 17));
        startsnake.emplace_back(Point(5, 18));
        startsnake.emplace_back(Point(6, 17));
        startsnake.emplace_back(Point(7, 16));
        startsnake.emplace_back(Point(8, 15));
        startsnake.emplace_back(Point(9, 14));

        //文本初始化
        textsnake.emplace_back(Point(-26, 14));//S
        textsnake.emplace_back(Point(-25, 14));
        textsnake.emplace_back(Point(-27, 15));
        textsnake.emplace_back(Point(-26, 16));
        textsnake.emplace_back(Point(-25, 17));
        textsnake.emplace_back(Point(-27, 18));
        textsnake.emplace_back(Point(-26, 18));

        textsnake.emplace_back(Point(-23, 14));//N
        textsnake.emplace_back(Point(-23, 15));
        textsnake.emplace_back(Point(-23, 16));
        textsnake.emplace_back(Point(-23, 17));
        textsnake.emplace_back(Point(-23, 18));
        textsnake.emplace_back(Point(-22, 15));
        textsnake.emplace_back(Point(-21, 16));
        textsnake.emplace_back(Point(-20, 17));
        textsnake.emplace_back(Point(-19, 14));
        textsnake.emplace_back(Point(-19, 15));
        textsnake.emplace_back(Point(-19, 16));
        textsnake.emplace_back(Point(-19, 17));
        textsnake.emplace_back(Point(-19, 18));

        textsnake.emplace_back(Point(-17, 18));//A
        textsnake.emplace_back(Point(-16, 17));
        textsnake.emplace_back(Point(-15, 16));
        textsnake.emplace_back(Point(-14, 15));
        textsnake.emplace_back(Point(-14, 16));
        textsnake.emplace_back(Point(-13, 14));
        textsnake.emplace_back(Point(-13, 16));
        textsnake.emplace_back(Point(-12, 15));
        textsnake.emplace_back(Point(-12, 16));
        textsnake.emplace_back(Point(-11, 16));
        textsnake.emplace_back(Point(-10, 17));
        textsnake.emplace_back(Point(-9, 18));

        textsnake.emplace_back(Point(-7, 14));//K
        textsnake.emplace_back(Point(-7, 15));
        textsnake.emplace_back(Point(-7, 16));
        textsnake.emplace_back(Point(-7, 17));
        textsnake.emplace_back(Point(-7, 18));
        textsnake.emplace_back(Point(-6, 16));
        textsnake.emplace_back(Point(-5, 15));
        textsnake.emplace_back(Point(-5, 17));
        textsnake.emplace_back(Point(-4, 14));
        textsnake.emplace_back(Point(-4, 18));

        textsnake.emplace_back(Point(-2, 14));//E
        textsnake.emplace_back(Point(-2, 15));
        textsnake.emplace_back(Point(-2, 16));
        textsnake.emplace_back(Point(-2, 17));
        textsnake.emplace_back(Point(-2, 18));
        textsnake.emplace_back(Point(-1, 14));
        textsnake.emplace_back(Point(-1, 16));
        textsnake.emplace_back(Point(-1, 18));
        textsnake.emplace_back(Point(0, 14));
        textsnake.emplace_back(Point(0, 16));
        textsnake.emplace_back(Point(0, 18));

    }
   
    void Action ();

private:
	int m_speed;				//过场动画速度
	vector<Point> textsnake;	//过场动画文本
	deque<Point> startsnake;	//过场动画中的蛇

private:
    //将过场动画分为三阶段
    void PrintFirst();
    void PrintSecond();
    void PrintThird();

    //文字部分动画
    void PrintText();
    void ClearText();
};

