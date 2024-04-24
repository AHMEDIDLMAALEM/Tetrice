#pragma once
#include <iostream>
#include <conio.h>
#include<Windows.h>


class Menu
{
	public:
	const static int timer_x = 7, timer_y = 7;
	int size;
	Menu(std::string options[],int size) {
		this->size = size;
		system("cls");
		
		for (int i = 0; i < size; i++)
		{
			std::cout <<" "<<(char)(i+97)<<". " << options[i] <<".\n";
		}
		std::cout << "Press (E) to enter";

		
	}
	int get_choice() {
		char in;
		int opt = 1;
		
		while (1) {
			gotoxy(0, opt-1, ">");
			in = _getch();
			if (in == 'P' && opt < size) {
				gotoxy(0, opt - 1, " ");
				opt++;
			}
			else if (in == 'H' && opt > 1) {
				gotoxy(0, opt - 1, " ");
				opt--;
			}
			else if (in == 'e' || in == 'E') { // Check for Enter key
				system("cls");
				return opt;
			}
				
			


		}
	}

	


	static void gotoxy(int x, int y,std::string s) {
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		std::cout << s;
	}
	static void gotoxy(int x, int y,char s) {
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		std::cout << s;
	}

};

