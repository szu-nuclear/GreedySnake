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

//��ʼ����ʼ���漰���Ŷ���
void Controller::Start()
{
	ShowConsoleCursor(false);//��������أ������ƻ���Ϸ����
	SetWindowSize(41,35);//���ڴ�С
	SetColor(3);		//������ɫ

	//����
	auto _startinterface = new StartInterface();	
	_startinterface->Action();
	delete _startinterface;

	SetCursorPosition(13, 26);
	cout << "Press any key to start...";

	SetCursorPosition(13, 27);
	system("pause");

}

//ѡ����Ϸ�Ѷ�
void Controller::Select()
{
	/*��ʼ������ѡ��*/
	SetColor(3);
	SetCursorPosition(13, 26);
	cout << "                          ";
	SetCursorPosition(13, 27);
	cout << "                          ";
	SetCursorPosition(6, 21);
	cout << "��ѡ����Ϸ�Ѷȣ�";
	SetCursorPosition(6, 22);
	cout << "(w s��ѡ��,�س�ȷ��)";
	SetCursorPosition(27, 22);
	SetBackColor();//��һ��ѡ�����ñ���ɫ�Ա�ʾ��ǰѡ��
	cout << "��ģʽ";
	SetColor(3);
	SetCursorPosition(27, 24);
	cout << "��ͨģʽ";
	SetCursorPosition(27, 26);
	cout << "����ģʽ";
	SetCursorPosition(0, 31);
	score = 0;

	//ѡ���Ѷ�
	int ch;					//��¼����ֵ
	key = 1;				//Ĭ��ѡ��ģʽ
	bool flag = false;		//��¼�Ƿ�ȷ��

	while (true)
	{
		//�ȴ���ҴӼ�������		
		ch = _getch();
		
		switch (ch)
		{
		case 119://�����Ѷ�
		{
			if (key > 1)//ֻ����ͨģʽ������ģʽ�ܼ��������Ѷ�
			{
				if (key == 2)//��ǰΪ��ͨģʽ
				{
					SetCursorPosition(27, 22);//����ѡ�������ñ���ɫ
					SetBackColor();
					cout << "��ģʽ";

					SetCursorPosition(27, 24);//����ѡ����ȡ������ɫ
					SetColor(3);
					cout << "��ͨģʽ";

					--key;
					
					SetCursorPosition(0, 31);//������������½ǣ�����Ӱ����Ϸ���飬��ͬ
					break;
				}
				else if (key == 3)//��ǰΪ����ģʽ
				{
					SetCursorPosition(27, 24);//����ѡ�������ñ���ɫ
					SetBackColor();
					cout << "��ͨģʽ";

					SetCursorPosition(27, 26);//����ѡ����ȡ������ɫ
					SetColor(3);
					cout << "����ģʽ";
					--key;
					SetCursorPosition(0, 31);
					break;

				}
			
			}
			
			break;
		}
		case 115://����Ѷ�
		{
			if (key < 3)
			{
				if (key == 1)
				{
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "��ͨģʽ";
					SetCursorPosition(27, 22);
					SetColor(3);
					std::cout << "��ģʽ";
					SetCursorPosition(0, 31);
					++key;
					break;
				}
				else if (key == 2)
				{
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "����ģʽ";
					SetCursorPosition(27, 24);
					SetColor(3);
					std::cout << "��ͨģʽ";
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
		//�������س����˳�ѭ��
		if (flag == true)
		{
			break;
		}

				
	}

	//�������ѡ����Ѷ��趨�ߵ��ƶ��ٶȣ�snake_speedֵԽС���ٶ�Խ��
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

//���Ƴ�ʼ��ͼ
void Controller::DrawGame()
{
	system("cls");

	//���Ƴ�ʼ��ͼ�߽�
	//SetColor(2);
	Map* init_map = new Map();
	init_map->PrintInitmap();
	delete init_map;

	//��ʼ�����
	SetCursorPosition(33, 1);
	std::cout << "Greedy Snake";
	SetCursorPosition(34, 2);
	std::cout << "̰����";
	SetCursorPosition(31, 4);
	std::cout << "�Ѷȣ�";
	SetCursorPosition(36, 5);
	switch (key)
	{
	case 1:
		std::cout << "��ģʽ";
		break;
	case 2:
		std::cout << "��ͨģʽ";
		break;
	case 3:
		std::cout << "����ģʽ";
		break;
	default:
		break;
	}
	
	SetCursorPosition(31, 7);
	std::cout << "�÷֣�";
	SetCursorPosition(37, 8);
	std::cout << "     0";
	SetCursorPosition(33, 13);
	std::cout << " wsad���ƶ�";
	SetCursorPosition(33, 15);
	std::cout << " ESC����ͣ";
	

}

//��Ϸ����ѭ��(����)
int Controller::PlayGame()
{
	Snake* cSnake = new Snake();
	Food* cFood = new Food();
	SetColor(6);
	cSnake->InitSnake();
	
	srand((unsigned)time(NULL));

	cFood->DrawFood(*cSnake);


	//��¼��ʼ�ٶ� ���ں��������Ѷ���
	int init_speed = this->snake_speed;
	//ֻҪ��ײ���Լ���ײ��ǽ��һֱѭ��	
	while (cSnake->OverEdge() == true && cSnake->HitItself() == true)
	{
		//������ESC �����ͣ�˵�
		if (cSnake->ChangeDirection() == false)
		{
			int choice = Menu();
			switch (choice)
			{
			case 1://������Ϸ
			{
				break;
			}

			case 2:	//���¿�ʼ
			{
				delete cSnake;
				delete cFood;
				return 1;//��1���ݵ�Game��������ʾ���¿�ʼ
			}

			case 3:	//�˳���Ϸ
			{
				delete cSnake;
				delete cFood;
				return 2;//��2���ݵ�Game��������ʾ���¿�ʼ
			}

			default:
				break;
			}
		}

		//�Ե�ʳ��
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
			UpdateScore(max(cFood->GetProgressBar()/5,1));//����������ʱʳ�������ȷ�� ���������ʱ��Ե���ȡһ������
			RewriteScore();
		}
		else//�����ƶ�
		{
			cSnake->NormalMove();
		}

		
		if (cFood->GetSuperFlag())//�г���ʳ�����˸��
		{
			cFood->FlashSuperFood();
		}

		//��ͬ���Ѷ��ܽ��͵��ٶȲ�һ������ֹ��������
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


		int tmp = min(cFood->GetCnt(), speed_up);	//ÿ��ʮ��ʳ���ٶȾͿ�һ�� ,��߼��ٲ��ܵ�����
		if (tmp)
		{
			snake_speed = init_speed - (tmp * 5);
		}

		Sleep(this->snake_speed);//��Ϸ�Ѷ� �ߵ��Ƶ��ٶ�
	}

	int flag = 0;//flagΪ0��ʾ���ε÷�û�н���ǰ����
	//����ǰ�������а�
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

	//�������а񱣴浽�ļ�
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
	

	//������
	delete cSnake;//�ͷŷ�����ڴ�ռ�
	delete cFood;
	int choice = Gameover();//������Ϸ�������棬��������ѡ��
	switch (choice)
	{
	case 1:
		return 1;//���¿�ʼ
	case 2:
		return 2;//�˳���Ϸ
	default:
		return 2;
	}
	
	
}

inline void Controller::UpdateScore(const int& s)
{
	score += key * 10 * s; //�Ѷ�Խ�� �÷�Խ��
}

void Controller::RewriteScore()
{
	/*Ϊ���ַ���β�����룬������������Ϊ6λ�����㵱ǰ����λ������ʣ��λ���ÿո�ȫ�����������*/
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
	/*���Ʋ˵�*/
	SetColor(11);
	SetCursorPosition(32, 19);
	std::cout << "�˵���";
	Sleep(100);
	SetCursorPosition(34, 21);
	SetBackColor();
	std::cout << "������Ϸ";
	Sleep(100);
	SetCursorPosition(34, 23);
	SetColor(11);
	std::cout << "���¿�ʼ";
	Sleep(100);
	SetCursorPosition(34, 25);
	std::cout << "�˳���Ϸ";
	SetCursorPosition(0, 31);

	//ѡ�񲿷�
	char ch;
	int choice = 1;			//Ĭ���û�ѡ�������Ϸ
	bool flag = false;		//��¼�Ƿ�ȷ������
	while ((ch = _getch()))
	{
		
		switch (ch)
		{
		case 119://w
		{
			if (choice == 2)
			{
				SetCursorPosition(34, 21);//��ѡ�е�ѡ�����ñ���ɫ
				SetBackColor();
				std::cout << "������Ϸ";

				SetCursorPosition(34, 23);//ȡ��֮ǰ�ı���ɫ
				SetColor(11);
				std::cout << "���¿�ʼ";

				--choice;
				break;

			}
			else if (choice == 3)
			{
				SetCursorPosition(34, 23);
				SetBackColor();
				std::cout << "���¿�ʼ";
				SetCursorPosition(34, 25);
				SetColor(11);
				std::cout << "�˳���Ϸ";

				--choice;
				break;
				
			}
			break;//��ʱѡ��Ϊ������Ϸ���޷���������ѡ��Ӧ��break
		}

		case 115://s
		{
			if (choice == 1)
			{
				SetCursorPosition(34, 23);
				SetBackColor();
				std::cout << "���¿�ʼ";
				SetCursorPosition(34, 21);
				SetColor(11);
				std::cout << "������Ϸ";

				++choice;
				break;
				
			}
			else if (choice == 2)
			{
				SetCursorPosition(34, 25);
				SetBackColor();
				std::cout << "�˳���Ϸ";
				SetCursorPosition(34, 23);
				SetColor(11);
				std::cout << "���¿�ʼ";

				++choice;
				break;
				
			}
			break;//��ʱѡ��Ϊ�˳���Ϸ���޷���������ѡ��Ӧ��break
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
			break;//ȷ��ѡ������ѡ��ѭ��
		}
		SetCursorPosition(0, 31);
	}
	

	if (choice == 1)			//�û�ѡ�������Ϸ����ղ˵�
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

//��Ϸһ��ѭ��
void Controller::Game()
{
	Start();//��ʼ����
	//int flag = 1;//���¿�ʼ��Ϸʱ��snack�����
	while (true)//��Ϸ����Ϊһ����ѭ����ֱ���˳���Ϸʱѭ������
	{

		Select();//ѡ�����
		DrawGame();//������Ϸ����
		ShowRanking();
		int tmp = PlayGame();//������Ϸѭ���������¿�ʼ���˳���Ϸʱ������ѭ��������ֵ��tmp
		if (tmp == 1) //����ֵΪ1ʱ���¿�ʼ��Ϸ
		{
			system("cls");
			continue;
		}
		else if (tmp == 2) //����ֵΪ2ʱ�˳���Ϸ
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
	/*������Ϸ��������*/
	Sleep(500);
	SetColor(11);
	SetCursorPosition(10, 8);
	std::cout << "��������������������������������������������������������������������������������������";
	Sleep(30);
	SetCursorPosition(9, 9);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 10);
	std::cout << " ��                Game Over !!!             ��";
	Sleep(30);
	SetCursorPosition(9, 11);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 12);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 13);
	std::cout << " ��             ��ķ���Ϊ��                 ��";
	SetCursorPosition(24, 13);
	std::cout << score;
	Sleep(30);
	SetCursorPosition(9, 14);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 15);
	std::cout << " ��              �Ƿ�����һ�֣�              ��";
	Sleep(30);
	SetCursorPosition(9, 16);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 17);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 18);
	std::cout << " ��      ����        ���ˣ�����Ҫ��        ��";
	Sleep(30);
	SetCursorPosition(9, 19);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 20);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(10, 21);
	std::cout << "��������������������������������������������������������������������������������������";

	Sleep(100);
	SetCursorPosition(13, 18);
	SetBackColor();
	std::cout << "����";
	SetCursorPosition(0, 31);

	/*ѡ�񲿷�*/
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
				std::cout << "����";
				SetCursorPosition(20, 18);
				SetColor(11);
				std::cout << "���ˣ�����Ҫ��";
				--tmp_key;
			}
			break;

		case 100://RIGHT
		{
			if (tmp_key < 2)
			{
				SetCursorPosition(20, 18);
				SetBackColor();
				std::cout << "���ˣ�����Ҫ��";
				SetCursorPosition(13, 18);
				SetColor(11);
				std::cout << "����";
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
		return 1;//���¿�ʼ
	case 2:
		return 2;//�˳���Ϸ
	default:
		return 1;
	}
	
}

void Controller::ShowRanking()
{
	SetCursorPosition(34,26);
	SetColor(4);
	std::cout << "���ٰ�" << endl;
	SetColor(7);
	SetCursorPosition(34, 27);
	cout << "1   " << Top[0] << endl;
	SetCursorPosition(34, 29);
	cout << "2   " << Top[1] << endl;
	SetCursorPosition(34, 31);
	cout << "3   " << Top[2] << endl;
}


