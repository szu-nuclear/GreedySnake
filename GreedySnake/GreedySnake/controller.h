#pragma once
#include<vector>
class Controller
{
public:
	Controller() ;

	//��ʼ����ʼ���漰���Ŷ���
	void Start();

	//ѡ�����
	void Select();

	void DrawGame();

	int PlayGame();

	void UpdateScore(const int&);

	void RewriteScore();

	//��ͣѡ��˵�
	int  Menu();

	void Game();

	int Gameover();

	void ShowRanking();

private:
	int snake_speed;
	int key;
	int score;
	std::vector<int> Top;
};

