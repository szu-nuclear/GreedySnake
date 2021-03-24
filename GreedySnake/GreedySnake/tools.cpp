#include "tools.h"
#include<Windows.h>
#include<cstdio>


void SetWindowSize(int cols, int lines)//���ô��ڴ�С
{
	//���ڱ���
	system("title Greedy Snake");
	
	char cmd[30];
	sprintf_s(cmd, "mode con cols=%d lines=%d", cols * 2, lines);//һ��ͼ�Ρ�ռ�����ַ����ʿ�ȳ���2
	system(cmd);//system(mode con cols=88 lines=88)���ô��ڿ�Ⱥ͸߶�


}

void SetCursorPosition(const int x, const int y)//���ù��λ��
{
	COORD position;
	position.X = x * 2;
	position.Y = y;

	//GetStdHandle(STD_OUTPUT_HANDLE)���ر�׼������豸�ľ����Ҳ���ǻ���������Ļ�������ľ��
	//SetConsoleCursorPosition()��һ��window api;���������ÿ���̨(cmd)���λ��
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	
}

void SetColor(int colorID)//�����ı���ɫ
{
	//SetConsoleTextAttribute()��һ��������API��Ӧ�ó����̽ӿڣ������ÿ���̨����������ɫ�ͱ���ɫ�ļ��������
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void SetBackColor()//�����ı�����ɫ(��ɫ)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_BLUE |
		BACKGROUND_BLUE |
		BACKGROUND_GREEN |
		BACKGROUND_RED);

}

//���ع��
void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}