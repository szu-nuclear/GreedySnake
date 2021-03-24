#include<iostream>
#include<ctime>
#include<conio.h>
#include<Windows.h>
#include "Controller.h"
#include"tools.h"
#include"startinterface.h"
#include"map.h"
#include"snake.h"
#include"food.h"
#include<fstream>



using namespace std;




Controller::Controller(): snake_speed(200), key(1), score(0)
{
	Top.clear();
	ifstream ifs;
	ifs.open("Top3.txt", ios::out);
	int f_score;
	while (ifs >> f_score)
	{
		Top.push_back(f_score);
	}
	ifs.close();
}

//初始化开始界面及播放动画
void Controller::Start()
{
	ShowConsoleCursor(false);//将光标隐藏，避免破坏游戏体验
	SetWindowSize(41,35);//窗口大小
	SetColor(3);		//动画颜色

	//动画
	auto _startinterface = new StartInterface();	
	_startinterface->Action();
	delete _startinterface;

	SetCursorPosition(13, 26);
	cout << "Press any key to start...";

	SetCursorPosition(13, 27);
	system("pause");

}

//选择游戏难度
void Controller::Select()
{
	/*初始化界面选项*/
	SetColor(3);
	SetCursorPosition(13, 26);
	cout << "                          ";
	SetCursorPosition(13, 27);
	cout << "                          ";
	SetCursorPosition(6, 21);
	cout << "请选择游戏难度：";
	SetCursorPosition(6, 22);
	cout << "(w s键选择,回车确认)";
	SetCursorPosition(27, 22);
	SetBackColor();//第一个选项设置背景色以表示当前选中
	cout << "简单模式";
	SetColor(3);
	SetCursorPosition(27, 24);
	cout << "普通模式";
	SetCursorPosition(27, 26);
	cout << "困难模式";
	SetCursorPosition(0, 31);
	score = 0;

	//选择难度
	int ch;					//记录键入值
	key = 1;				//默认选简单模式
	bool flag = false;		//记录是否确认

	while (true)
	{
		//等待玩家从键盘输入		
		ch = _getch();
		
		switch (ch)
		{
		case 119://降低难度
		{
			if (key > 1)//只有普通模式和困难模式能继续调低难度
			{
				if (key == 2)//当前为普通模式
				{
					SetCursorPosition(27, 22);//给待选中项设置背景色
					SetBackColor();
					cout << "简单模式";

					SetCursorPosition(27, 24);//将已选中项取消背景色
					SetColor(3);
					cout << "普通模式";

					--key;
					
					SetCursorPosition(0, 31);//将光标置于左下角，避免影响游戏体验，下同
					break;
				}
				else if (key == 3)//当前为困难模式
				{
					SetCursorPosition(27, 24);//给待选中项设置背景色
					SetBackColor();
					cout << "普通模式";

					SetCursorPosition(27, 26);//将已选中项取消背景色
					SetColor(3);
					cout << "困难模式";
					--key;
					SetCursorPosition(0, 31);
					break;

				}
			
			}
			
			break;
		}
		case 115://提高难度
		{
			if (key < 3)
			{
				if (key == 1)
				{
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "普通模式";
					SetCursorPosition(27, 22);
					SetColor(3);
					std::cout << "简单模式";
					SetCursorPosition(0, 31);
					++key;
					break;
				}
				else if (key == 2)
				{
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "困难模式";
					SetCursorPosition(27, 24);
					SetColor(3);
					std::cout << "普通模式";
					SetCursorPosition(0, 31);
					++key;
					break;
					
				}
				
			}
			break;

		}
		case 13:
		{
			flag = true;
			break;
		}
		default :
		{
			
			break;
		}

		}
		//如果键入回车则退出循环
		if (flag == true)
		{
			break;
		}

				
	}

	//根据玩家选择的难度设定蛇的移动速度，snake_speed值越小，速度越快
	switch (key)
	{
	case 1:
		this->snake_speed = 140;
		break;
	case 2:
		this->snake_speed = 100;
		break;
	case 3:
		this->snake_speed = 60;
		break;

	default:
		break;
	}
	

}

//绘制初始地图
void Controller::DrawGame()
{
	system("cls");

	//绘制初始地图边界
	//SetColor(2);
	Map* init_map = new Map();
	init_map->PrintInitmap();
	delete init_map;

	//初始侧边栏
	SetCursorPosition(33, 1);
	std::cout << "Greedy Snake";
	SetCursorPosition(34, 2);
	std::cout << "贪吃蛇";
	SetCursorPosition(31, 4);
	std::cout << "难度：";
	SetCursorPosition(36, 5);
	switch (key)
	{
	case 1:
		std::cout << "简单模式";
		break;
	case 2:
		std::cout << "普通模式";
		break;
	case 3:
		std::cout << "困难模式";
		break;
	default:
		break;
	}
	
	SetCursorPosition(31, 7);
	std::cout << "得分：";
	SetCursorPosition(37, 8);
	std::cout << "     0";
	SetCursorPosition(33, 13);
	std::cout << " wsad键移动";
	SetCursorPosition(33, 15);
	std::cout << " ESC键暂停";
	

}

//游戏过程循环(二级)
int Controller::PlayGame()
{
	Snake* cSnake = new Snake();
	Food* cFood = new Food();
	SetColor(6);
	cSnake->InitSnake();
	
	srand((unsigned)time(NULL));

	cFood->DrawFood(*cSnake);


	//记录初始速度 用于后面提升难度用
	int init_speed = this->snake_speed;
	//只要不撞到自己、撞到墙则一直循环	
	while (cSnake->OverEdge() == true && cSnake->HitItself() == true)
	{
		//按下了ESC 输出暂停菜单
		if (cSnake->ChangeDirection() == false)
		{
			int choice = Menu();
			switch (choice)
			{
			case 1://继续游戏
			{
				break;
			}

			case 2:	//重新开始
			{
				delete cSnake;
				delete cFood;
				return 1;//将1传递到Game函数，表示重新开始
			}

			case 3:	//退出游戏
			{
				delete cSnake;
				delete cFood;
				return 2;//将2传递到Game函数，表示重新开始
			}

			default:
				break;
			}
		}

		//吃到食物
		if (cSnake->GetFood(*cFood))
		{
			cSnake->Move();
			UpdateScore(1);
			RewriteScore();
			cFood->DrawFood(*cSnake);
		}
		else if (cSnake->GetSuperFood(*cFood))
		{
			cSnake->Move();
			UpdateScore(max(cFood->GetProgressBar()/5,1));//分数根据限时食物进度条确定 如果在最后的时间吃到则取一个保底
			RewriteScore();
		}
		else//正常移动
		{
			cSnake->NormalMove();
		}

		
		if (cFood->GetSuperFlag())//有超级食物就闪烁他
		{
			cFood->FlashSuperFood();
		}

		//不同的难度能降低的速度不一样，防止降到负数
		int speed_up;
		if (key == 1)
		{
			speed_up = 10;
		}
		else if (key == 2)
		{
			speed_up = 6;
		}
		else
		{
			speed_up = 2;
		}


		int tmp = min(cFood->GetCnt(), speed_up);	//每吃十个食物速度就快一点 ,最高加速不能到负数
		if (tmp)
		{
			snake_speed = init_speed - (tmp * 5);
		}

		Sleep(this->snake_speed);//游戏难度 蛇的移到速度
	}

	int flag = 0;//flag为0表示本次得分没有进入前三名
	//更新前三名排行榜
	if (score > Top[0])
	{
		
		Top[1] = Top[0];
		Top[0] = score;
		flag = 1;
	}
	else if (score > Top[1])
	{
		Top[2] = Top[1];
		Top[1] = score;
		flag = 1;
	}
	else if (score > Top[2])
	{
		Top[2] = score;
		flag = 1;
	}

	//将新排行榜保存到文件
	if (flag == 1)
	{
		ofstream ofs;
		ofs.open("Top3.txt", ios::in|ios::trunc);
		for (auto e : Top)
		{
			ofs << e << endl;
		}
		ofs.close();
	}
	

	//蛇死亡
	delete cSnake;//释放分配的内存空间
	delete cFood;
	int choice = Gameover();//绘制游戏结束界面，并返回所选项
	switch (choice)
	{
	case 1:
		return 1;//重新开始
	case 2:
		return 2;//退出游戏
	default:
		return 2;
	}
	
	
}

inline void Controller::UpdateScore(const int& s)
{
	score += key * 10 * s; //难度越高 得分越高
}

void Controller::RewriteScore()
{
	/*为保持分数尾部对齐，将最大分数设置为6位，计算当前分数位数，将剩余位数用空格补全，再输出分数*/
	SetCursorPosition(37, 8);
	SetColor(11);
	int bit = 0;
	int tmp = score;
	while (tmp != 0)
	{
		++bit;
		tmp /= 10;
	}
	for (int i = 0; i < (6 - bit); ++i)
	{
		std::cout << " ";
	}
	std::cout << score;
	
}


int Controller::Menu()
{
	/*绘制菜单*/
	SetColor(11);
	SetCursorPosition(32, 19);
	std::cout << "菜单：";
	Sleep(100);
	SetCursorPosition(34, 21);
	SetBackColor();
	std::cout << "继续游戏";
	Sleep(100);
	SetCursorPosition(34, 23);
	SetColor(11);
	std::cout << "重新开始";
	Sleep(100);
	SetCursorPosition(34, 25);
	std::cout << "退出游戏";
	SetCursorPosition(0, 31);

	//选择部分
	char ch;
	int choice = 1;			//默认用户选择继续游戏
	bool flag = false;		//记录是否确认输入
	while ((ch = _getch()))
	{
		
		switch (ch)
		{
		case 119://w
		{
			if (choice == 2)
			{
				SetCursorPosition(34, 21);//给选中的选项设置背景色
				SetBackColor();
				std::cout << "继续游戏";

				SetCursorPosition(34, 23);//取消之前的背景色
				SetColor(11);
				std::cout << "重新开始";

				--choice;
				break;

			}
			else if (choice == 3)
			{
				SetCursorPosition(34, 23);
				SetBackColor();
				std::cout << "重新开始";
				SetCursorPosition(34, 25);
				SetColor(11);
				std::cout << "退出游戏";

				--choice;
				break;
				
			}
			break;//此时选项为继续游戏，无法继续向上选择，应该break
		}

		case 115://s
		{
			if (choice == 1)
			{
				SetCursorPosition(34, 23);
				SetBackColor();
				std::cout << "重新开始";
				SetCursorPosition(34, 21);
				SetColor(11);
				std::cout << "继续游戏";

				++choice;
				break;
				
			}
			else if (choice == 2)
			{
				SetCursorPosition(34, 25);
				SetBackColor();
				std::cout << "退出游戏";
				SetCursorPosition(34, 23);
				SetColor(11);
				std::cout << "重新开始";

				++choice;
				break;
				
			}
			break;//此时选项为退出游戏，无法继续向下选择，应该break
		}

		case 13://Enter
		{
			flag = true;
			break;
		}
		default:
			break;
		}
		if (flag)
		{
			break;//确认选择，跳出选择循环
		}
		SetCursorPosition(0, 31);
	}
	

	if (choice == 1)			//用户选择继续游戏，清空菜单
	{
		SetCursorPosition(32, 19);
		std::cout << "      ";
		SetCursorPosition(34, 21);
		std::cout << "        ";
		SetCursorPosition(34, 23);
		std::cout << "        ";
		SetCursorPosition(34, 25);
		std::cout << "        ";
		
	}
	return choice;
}

//游戏一级循环
void Controller::Game()
{
	Start();//开始界面
	//int flag = 1;//重新开始游戏时把snack打出来
	while (true)//游戏可视为一个死循环，直到退出游戏时循环结束
	{

		Select();//选择界面
		DrawGame();//绘制游戏界面
		ShowRanking();
		int tmp = PlayGame();//开启游戏循环，当重新开始或退出游戏时，结束循环并返回值给tmp
		if (tmp == 1) //返回值为1时重新开始游戏
		{
			system("cls");
			continue;
		}
		else if (tmp == 2) //返回值为2时退出游戏
		{
			
			break;
		}
		else
		{
			break;
		}
	}
}

int Controller::Gameover()
{
	/*绘制游戏结束界面*/
	Sleep(500);
	SetColor(11);
	SetCursorPosition(10, 8);
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
	Sleep(30);
	SetCursorPosition(9, 9);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 10);
	std::cout << " ┃                Game Over !!!             ┃";
	Sleep(30);
	SetCursorPosition(9, 11);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 12);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 13);
	std::cout << " ┃             你的分数为：                 ┃";
	SetCursorPosition(24, 13);
	std::cout << score;
	Sleep(30);
	SetCursorPosition(9, 14);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 15);
	std::cout << " ┃              是否再来一局？              ┃";
	Sleep(30);
	SetCursorPosition(9, 16);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 17);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 18);
	std::cout << " ┃      冲冲冲        不了，读书要紧        ┃";
	Sleep(30);
	SetCursorPosition(9, 19);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 20);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(10, 21);
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";

	Sleep(100);
	SetCursorPosition(13, 18);
	SetBackColor();
	std::cout << "冲冲冲";
	SetCursorPosition(0, 31);

	/*选择部分*/
	int ch;
	int tmp_key = 1;
	bool flag = false;
	while ((ch = _getch()))
	{
		switch (ch)
		{
		case 97://LEFT
			if (tmp_key > 1)
			{
				SetCursorPosition(13, 18);
				SetBackColor();
				std::cout << "冲冲冲";
				SetCursorPosition(20, 18);
				SetColor(11);
				std::cout << "不了，读书要紧";
				--tmp_key;
			}
			break;

		case 100://RIGHT
		{
			if (tmp_key < 2)
			{
				SetCursorPosition(20, 18);
				SetBackColor();
				std::cout << "不了，读书要紧";
				SetCursorPosition(13, 18);
				SetColor(11);
				std::cout << "冲冲冲";
				++tmp_key;
			}
			break;
		}
			

		case 13://Enter
		{
			flag = true;
			break;
		}
			

		default:
			break;
		}

		SetCursorPosition(0, 31);
		if (flag) {
			break;
		}
	}

	SetColor(11);
	switch (tmp_key)
	{
	case 1:
		return 1;//重新开始
	case 2:
		return 2;//退出游戏
	default:
		return 1;
	}
	
}

void Controller::ShowRanking()
{
	SetCursorPosition(34,26);
	SetColor(4);
	std::cout << "光荣榜" << endl;
	SetColor(7);
	SetCursorPosition(34, 27);
	cout << "1   " << Top[0] << endl;
	SetCursorPosition(34, 29);
	cout << "2   " << Top[1] << endl;
	SetCursorPosition(34, 31);
	cout << "3   " << Top[2] << endl;
}


