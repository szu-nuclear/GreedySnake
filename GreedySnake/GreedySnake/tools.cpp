#include "tools.h"
#include<Windows.h>
#include<cstdio>


void SetWindowSize(int cols, int lines)//设置窗口大小
{
	//窗口标题
	system("title Greedy Snake");
	
	char cmd[30];
	sprintf_s(cmd, "mode con cols=%d lines=%d", cols * 2, lines);//一个图形■占两个字符，故宽度乘以2
	system(cmd);//system(mode con cols=88 lines=88)设置窗口宽度和高度


}

void SetCursorPosition(const int x, const int y)//设置光标位置
{
	COORD position;
	position.X = x * 2;
	position.Y = y;

	//GetStdHandle(STD_OUTPUT_HANDLE)返回标准的输出设备的句柄，也就是获得输出的屏幕缓冲区的句柄
	//SetConsoleCursorPosition()是一个window api;作用是设置控制台(cmd)光标位置
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	
}

void SetColor(int colorID)//设置文本颜色
{
	//SetConsoleTextAttribute()是一个可以在API（应用程序编程接口）中设置控制台窗口字体颜色和背景色的计算机函数
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void SetBackColor()//设置文本背景色(白色)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_BLUE |
		BACKGROUND_BLUE |
		BACKGROUND_GREEN |
		BACKGROUND_RED);

}

//隐藏光标
void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}