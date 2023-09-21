#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<time.h>
#include<math.h>
#include <stdlib.h>
#include "Snake.h"
#include<windows.h>
#include<conio.h>


/*
自身撞
墙壁撞
食物撞--自身长--食物再生成
方向控制
*/

int main()
{
	int score = 0;
	srand((size_t)time(NULL));
	InitFood();
	InitSnake();
	ShowUI();
	PlayGame();
	getchar();




}

void UpdadeFood(int i)
{
	food[i][0] = rand() % WIDE;
	food[i][1] = rand() % HIGH;
}

void InitFood()
{

	for (int i = 0; i < FOOD_COUNGT; i++)
	{
		food[i][0] = rand() % WIDE;
		food[i][1] = rand() % HIGH;
	}

	for (int i = 0; i < FOOD_COUNGT; i++)
	{
		if (food[i][0] == snake.body[0].X && food[i][1] == snake.body[0].Y)
		{


			void initFood();


		}

	}
}

void InitSnake()
{
	snake.size = 2;

	snake.body[0].X = WIDE / 2;
	snake.body[0].Y = HIGH / 2;

	snake.body[1].X = WIDE / 2;
	snake.body[1].Y = HIGH / 2 + 1;
}

void ShowUI()
{
	COORD coord;
	for (int i = 0; i < snake.size; i++)
	{
		coord.X = snake.body[i].X;
		coord.Y = snake.body[i].Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		if (i == 0)
			putchar('@');
		else
			putchar('*');
		for (int i = 0; i < FOOD_COUNGT; i++)
		{
			coord.X = food[i][0];
			coord.Y = food[i][1];
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			putchar('#');


		}
	}

}


void gotoxy(short x, short y) {
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void PlayGame()
{
	char key = 'S';
	while (snake.body[0].X >= 0 && snake.body[0].X < WIDE    //区域约束
		&& snake.body[0].Y >= 0 && snake.body[0].Y < HIGH)
	{
		ShowUI();

		while (_kbhit())
		{
			key = _getch();

		}
		//方向控制
		switch(key)
		{
		case'd':case'D':dx = 1; dy = 0; break;
		case'w':case'W':dx = 0; dy = -1; break;
		case's':case'S':dx = 0; dy = 1; break;
		case'a':case'A':dx = -1; dy = 0; break;
			 
		}

	
		for (int i = snake.size - 1; i > 0; i--)
		{
			snake.body[i].X = snake.body[i - 1].X;
			snake.body[i].Y = snake.body[i - 1].Y;
			
			

		}
		snake.body[0].X += dx;
		snake.body[0].Y += dy;
		gotoxy(45, 0);
		printf("目前得分是%d", score);

	/*	switch (snake.size)
		{
		case 1:Sleep(200);
		case 5:Sleep(200);
		case 7:Sleep(250);
		case 10:Sleep(150);
		case 20:Sleep(100);
		}*/

		if (snake.size > 0)
		{
			Sleep(350);
		}
		else if (snake.size > 5)
		{
			Sleep(250);

		}
		else if (snake.size > 10)
		{
			Sleep(100);
		}
		else 
		{
			Sleep(50);
		}
		
		
		system("cls");
		for (int i = 0; i < FOOD_COUNGT; i++)
		{
			if (snake.body[0].X == food[i][0] && snake.body[0].Y == food[i][1])
			{
				//资源刷新
				UpdadeFood(i);

				snake.size++;

				score += 10;
				
			}
		}
		for (int i = 1; i < snake.size; i++)  //自身碰撞
		{
			if (snake.body[0].X == snake.body[i].X && snake.body[0].Y == snake.body[i].Y)
			{
				gotoxy(45, 0);
				printf("最后得分是%d", score);
				return ;
			}
		}

	}
	

	//if (snake.body[0].X == food[0] && snake.body[0].Y == food[1])
	//{
	//	//资源刷新
	//	InitFood();

	//	snake.size++;

	//	score += 10;
	//}

	//for (int i = 1; i < snake.size; i++)  //自身碰撞
	//{
	//	if (snake.body[0].X == snake.body[i].X && snake.body[0].Y == snake.body[i].Y)
	//	{
	//		return;
	//	}
	//}


}

