#define _CRT_SECURE_NO_WARNINGS 1
#define WIDE 90
#define HIGH 37
#define FOOD_COUNGT 10

struct BODY
{
	int X;
	int Y;
};


struct SNAKE
{
	struct BODY body[WIDE * HIGH];
	int size;

}snake;

int food[FOOD_COUNGT][2] = {0};      // food[0]Ϊx, food[1]ΪY

void InitFood();
void InitSnake();
void ShowUI();
void PlayGame();
int score = 0;
int dx = 0;
int dy = 0;
