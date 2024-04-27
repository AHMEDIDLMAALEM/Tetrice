#pragma once
#include <iostream>
#include <conio.h>
#include<Windows.h>


class Menu
{
	public:
		int x;
		int y;
	const static int timer_x = 7, timer_y = 7;
	int size;
	Menu(std::string options[], int size,int x = 0,int y = 0);
	int get_choice();

	


	static void gotoxy(int x, int y, std::string s);
	static void gotoxy(int x, int y, char s);

};

