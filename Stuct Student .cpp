#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>

struct Student
{
	int age;
	int score;
};

struct Student* CreateStudent(void);

void ShowStudent(struct Student* ps);


int main()
{
	struct Student* p;
	p = CreateStudent();
	ShowStudent(p);


}

struct Student* CreateStudent(void)
{

	struct Student *p = ((struct Student*)malloc(sizeof(struct Student)));
	p->age=18;
	p->score = 99;

	return p;
}

void ShowStudent(struct Student* ps)
{
	printf("age=%d,score=%d\n", ps->age, ps->score);
}

