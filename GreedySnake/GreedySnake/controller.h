#pragma once
#include<vector>
class Controller
{
public:
	Controller() ;

	//初始化开始界面及播放动画
	void Start();

	//选择界面
	void Select();

	void DrawGame();

	int PlayGame();

	void UpdateScore(const int&);

	void RewriteScore();

	//暂停选项菜单
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

